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

#define  MAXPENDING 2  // queue max connection permited 


int main(){
    
    int socket_server = 0;
    int socket_client = 0;
    char Bind, Listen = 0;
    char buffer[100] = {0};
    char msg[] = "Hello client!\n\r";
    struct sockaddr_in server_server;
    struct sockaddr_in server_client;

    socket_server = socket(PF_INET, SOCK_STREAM, 0);
    if (socket_server < 0){
        perror("[ERROR] Socket");
        return(-1);
    }
    printf("[+] Socket\n\r");
       
    // Server parameters   
    server_server.sin_family      = AF_INET ;  // protocol
    server_server.sin_addr.s_addr = INADDR_ANY; // server ip
    server_server.sin_port        = htons(19900); // connection port
    // htons(port number) convert to 6 bit format


    // the funtion bind merge socket with serverr
    Bind = bind(socket_server, (struct sockaddr*)&server_server, sizeof(server_server));
    if (Bind < 0){
        perror("[ERROR] Bind");
        return (-1);
    }
    printf("[+] Bind\n\r");


    Listen = listen(socket_server, MAXPENDING);
    if (Listen < 0){
        perror("[ERROR] Listen");
        return(-1);
    }
    printf("[+] Listen\n\r");


    socket_client = accept(socket_server,(struct sockaddr*)&server_client, sizeof(server_client));
    if (socket_client < 0){
        perror("[ERROR] Socket client");
        return(-1);
    }
    printf("[+] Client connect\n\r");


    if (send(socket_client, msg, sizeof(msg), 0) < 0){
        perror("[ERROR] Data send");
        return(-1);
    }
    printf("[+] Data send\r\n");


    if(recv(socket_server, buffer, sizeof(buffer),0) < 0){
        perror("[ERROR] Data Reveice: ");
        return(-1);
    }
    printf("[+] Data receive\r\n");


    printf("%s", buffer);


    close(socket_server);
    close(socket_client);
    return(0); 
}

