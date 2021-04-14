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


int main(){
    
    int socket_id = 0;
    unsigned int length = 0;
    char Bind = 0;
    char Listen = 0;
    unsigned int address_length;
    int client = 0;
    

    // Server parameters   
    struct sockaddr_in serverr;
    serverr.sin_family      = AF_INET ;  // protocol
    serverr.sin_addr.s_addr = inet_addr("127.0.0.1"); // server ip
    serverr.sin_port        = htons(19900); // connection port
    // htons(port number) convert to 6 bit format
    // the funtion bind merge socket with serverr
    
    socket_id = socket(PF_INET, SOCK_STREAM, 0);
    if (socket_id < 0){
        perror("[ERROR] Socket");
        return(-1);
    }
    
   
    Bind = bind(socket_id, (struct sockaddr*)&serverr, sizeof(serverr));
    
    if (Bind < 0){
        perror("[ERROR] Bind");
        return (-1);
    }

    printf("[LISTENING]");

    Listen = listen(socket_id, MAXPENDING);
    if (Listen < 0){
        perror("[ERROR] Listen");
        return(-1);
    }
     printf("[PUIS]");
    
    // Server client parameters   
    struct sockaddr_in serverClient;
    client = accept(socket_id, (struct sockaddr*)&serverClient, sizeof(serverClient));
    
    printf("Recibi una conexione en %d", client);
    close(socket_id);
   

    return(0); 
}