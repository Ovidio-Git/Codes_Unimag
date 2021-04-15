#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> //for socket(), connect(), send() and recv()
#include <netinet/in.h>
//https://github.com/lettier/ntpclient/blob/master/source/c/main.c

#define Seventy_years 2208988800
// SOCK_STREAM -> TCP 
// SOCK_DGRAM -> UDP

int main(){

    int connection = 0;
    int socket_id = 0;
    long int aux[6] = {0};
    unsigned char msg[48]={0x1B,0,0,0,0,0,0,0,0,0};
    unsigned char buffer[50]={0};

    // Server parameters  IP = 200.89.75.197
    struct sockaddr_in serverntp;
    serverntp.sin_family = AF_INET ;  // protocol
    serverntp.sin_addr.s_addr = inet_addr("200.89.75.197"); // server ip
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

    // LOS ULTIMOS 32 bits  contienen los segundos 
    // de la marca de tiempo cuando el paquete salió del servidor NTP.
    // El número de segundos corresponde a los segundos transcurridos desde 1900.
    // los ultimos 8 bites del buffer son los que forman los segundo
    
    aux[0] = recv(socket_id,buffer,sizeof(buffer),0);
    printf("--> %ld\n\r", aux[0]);
    

    // convirtiendo las cadenas de 8 bytes a una de 32 bytes
    aux[1] = buffer[43]<<24;
    aux[2] = buffer[42]<<16;
    aux[3] = buffer[41]<<8;
    aux[4] = aux[1]+ aux[2] + aux[3] + buffer[40];
    
  
    printf("summi %ld \n\r", aux[4]);
    
    aux[5]= ntohl( aux[4] ); // Time-stamp seconds.
    printf("a5 %ld \n\r", aux[5]);
    aux[5] = aux[5] - Seventy_years;
    printf("reste %ld \n\r", aux[5]);
    
    time_t txTm = ( time_t ) ( aux[5] - Seventy_years );

    printf( "Time: %s", ctime( ( const time_t* ) &txTm ) );

    close(socket_id);
    printf("[FINISH]\r\n");
    return (0);

}



