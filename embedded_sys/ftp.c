
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket(), connect(), send() and recv()
#include <netinet/in.h>

// SOCK_STREAM -> TCP 
// SOCK_DGRAM -> UDP

int main(){
    
    int connection = 0;
    int socket_id = 0;
    char msg[] ="Hello sir, message send scket instance\n\r";
   
    // Server parameters  IP = 200.160.7.186
    struct sockaddr_in serverftp;
    serverftp.sin_family = AF_INET ;  // protocol
    serverftp.sin_addr.s_addr = inet_addr("200.160.7.186"); // server ip
    serverftp.sin_port = htons(123); // ntp connection port
    
    socket_id = socket(PF_INET, SOCK_DGRAM, 0);
    if (socket_id < 0){
        perror("[ERROR] Socket\r\n");
        return(-1);
    }
    printf("[+] Socket created\r\n");

    // Make connection
    connection = connect(socket_id, (struct sockaddr*)&serverftp, sizeof(serverftp));
    if (connection < 0){
        printf("[ERROR] connection failed\r\n");
        return(-1);
    }

    printf("[+] Successful connection\r\n");
    // send(socket_id, msg, sizeof(msg), 0); 
    // printf("[DATA SEND]\r\n");
    close(socket_id);

    return (0);

}



