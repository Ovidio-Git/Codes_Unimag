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

#define  MAXPENDING 5


int main(){
    
    int socket_id = 0;
    unsigned int length = 0;
    
    socket_id = socket(PF_INET, SOCK_STREAM, 0);
    if (socket_id < 0){
        printf("[ERROR]: socket failed");
        return(-1);
    }

    // Server parameters   AWS IP Public= 18.222.148.97
    struct sockaddr_in server;
    server.sin_family      = AF_INET ;  // protocol
    server.sin_addr.s_addr = inet_addr("18.222.148.97"); // server ip
    server.sin_port        = htons(19900); // connection port
    // htons(port number) convert to 6 bit format 

    // Server client parameters   
    struct sockaddr_in serverclient;
    serverclient.sin_family      = AF_INET ;  // protocol
    serverclient.sin_addr.s_addr = inet_addr("18.222.148.97"); // server ip
    serverclient.sin_port        = htons(19900); // connection port
    // htons(port number) convert to 6 bit format

    Bind = bind(socket_id, (struct sockaddr*)&server, sizeof(server))
    if (Bind < 0){
        printf("[ERROR]: bind failed");
        return(-1);
    }

    Listen = listen(socket_id, MAXPENDING)
    if (Liste < 0){
        printf("[ERROR]: listen failed");
        return(-1);
    }
    while(1)
    {

    }
    return(0); 
}