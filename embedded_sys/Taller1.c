

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> // socket library
#include <netinet/in.h>

// SOCK_STREAM -> TCP 
// SOCK_DGRAM -> UDP

int main(){
    
    int connection = 0;
    int socket_id = 0;
    char msg[] ="Hello sir\n\r";
    socket_id = socket(PF_INET, SOCK_STREAM, 0);

    // Server parameters   AWS IP Public= 18.222.148.97
    struct sockaddr_in server;
    server.sin_family = AF_INET ;  // protocol
    server.sin_addr.s_addr = inet_addr("157.240.6.35"); // server ip
    server.sin_port = htons(12000); // connection port
    // htons(port number) convert to 6 bit format 
    
    
    // Make connection
    connection = connect(socket_id, (struct sockaddr*)&server, sizeof(server));
    if (connection < 0){
        printf("[ERROR] connection failed\r\n");
        return(-1);
    }
    printf("[CONNECTION SUCCESS]\r\n");
    send(socket_id, msg, sizeof(msg), 0); 
    close(socket_id);

    return (0);

