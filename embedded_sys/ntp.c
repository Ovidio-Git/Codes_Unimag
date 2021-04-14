
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket(), connect(), send() and recv()
#include <netinet/in.h>

// SOCK_STREAM -> TCP 
// SOCK_DGRAM -> UDP

int main(){

    int connection = 0;
    int socket_id = 0;
    unsigned char msg[48]={0x1B,0,0,0,0,0,0,0,0,0};
    unsigned char buffer[30];

    // Server parameters  IP = 200.160.7.186
    struct sockaddr_in serverntp;
    serverntp.sin_family = AF_INET ;  // protocol
    serverntp.sin_addr.s_addr = inet_addr("200.160.7.186"); // server ip
    serverntp.sin_port = htons(123); // 123 is ntp port number


    socket_id = socket(PF_INET, SOCK_DGRAM, 0);
    if (socket_id < 0){
        perror("[ERROR] Socket\r\n");
        return(-1);
    }
    printf("[+] Socket created\r\n");


    connection = connect(socket_id, (struct sockaddr*)&serverntp, sizeof(serverntp));
    if (connection < 0){
        printf("[ERROR] connection failed\r\n");
        return(-1);
    }
    printf("[+] Successful connection\r\n");
    

    send(socket_id, msg, sizeof(msg), 0); 
    printf("[+] Data send\r\n");
   
 
    while (recv(socket_id,buffer,sizeof(buffer),0) > 0)
    {
        printf("[+] Reading buffer\r\n");
        printf("%s\n\r", buffer);
        printf("[+] Print buffer\r\n");
    }
    

    close(socket_id);
    printf("[FINISH]\r\n");
    return (0);

}



