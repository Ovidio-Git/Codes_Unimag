/*
Steps for TCP server communication

1. Create a TCP socket using socket()
2. Assign a port number to the socket with bind()
3. Tell the system to allow connections to be made that port, using listen()
4. Repeatedly do the following:
  - Call accept() to get a new socket for each client connection.
  - Communicate with the client via that new socket using send() and recv()
  - Close the client connections using close()
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket(), connect(), and blind()
#include <netinet/in.h>

#define  MAXPENDING 10  // queue max connection permited 

void TCPClient( int socket_client);

int main(){
    
    int socket_server = 0;
    int socket_client = 0;
    char Bind, Listen = 0;
    struct sockaddr_in server_server;
    struct sockaddr_in server_client;

    socket_server = socket(PF_INET, SOCK_STREAM, 0);
    if (socket_server < 0){
        perror("[ERROR] Socket");
        return(-1);
    }
    printf("[+] Socket");
       

    // Server parameters   
    server_server.sin_family      = AF_INET ;  // protocol
    server_server.sin_addr.s_addr = htonl(INADDR_ANY); // server ip
    server_server.sin_port        = htons(19900); // connection port
    // htons(port number) convert to 6 bit format
    // the funtion bind merge socket with serverr


    Bind = bind(socket_server, (struct sockaddr*)&server_server, sizeof(server_server));
    if (Bind < 0){
        perror("[ERROR] Bind");
        return (-1);
    }
    printf("[+] Bind");


    Listen = listen(socket_server, MAXPENDING);
    if (Listen < 0){
        perror("[ERROR] Listen");
        return(-1);
    }
    printf("[+] Listen");

    for(;;){

        socket_client = accept(socket_server,(struct sockaddr*)&server_client, sizeof(server_client));
        if(socket_client < 0){
            perror("[ERROR] Socket client");
        }
        // printf("conecction client %s \n", inet_ntoa(server_client.sin_addr));
        TCPClient(socket_client);
    }

    return(0); 
}



void TCPClient( int socket_c){
    
    char buffer[30]={0};
    int msg = 0;

    msg = recv(socket_c, buffer, sizeof(buffer), 0);
    if (msg < 0){
        perror("[ERROR] Receive");
    }
    printf("[+] Receive");

    while (msg > 0)
    {
        if (send(socket_c, buffer, sizeof(buffer),0) != msg){
            perror("[ERROR] Send failed ");
        }
         
        msg = recv(socket_c, buffer, sizeof(buffer), 0);
        if (msg < 0){
            perror("[ERROR] Receive");
        }
        printf("%s", buffer);   
    }
    close(socket_c);

}
