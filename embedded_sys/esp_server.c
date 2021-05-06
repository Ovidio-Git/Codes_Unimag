#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> // for socket(), connect(), and blind()
#include <string.h>     // for strncmp()
#include <netinet/in.h>

#define  MAXPENDING 2  //  queue max connection permited


void render(char file[],int socket){

    // Website templates files
    char *ptrContent = NULL;
    long filesize = 0;
    FILE* ptrfile = NULL;

    // Open file
    ptrfile = fopen(file, "r");
    if (ptrfile == NULL){
        printf("[ERROR] File not found\n\r");
        return (-1);
    }
    printf("[+] File found\n\r");

    //  File size
    fseek(ptrfile, 0L, SEEK_END); // go end file
    filesize = ftell(ptrfile);
    fseek(ptrfile, 0L, SEEK_SET); // go start file
    printf("File size [%ld] bytes\n\r", filesize); // print file size

    ptrContent = (char*) malloc(filesize);    // reserving memory
    fread(ptrContent, 1, filesize, ptrfile);  // reading file content
    send(socket, ptrContent, filesize, 0);  // sending website file
    for(int i=0; i<100000000; i++); // delay for testing
    close(socket); // close client socket
    free(ptrContent);   // freeing memory
    fclose(ptrfile);    // close file
}


int main(){

    // server variables
    int socket_server = 0;
    int socket_client = 0;
    int addr_length = 0;
    char Bind, Listen = 0;
    char buffer[100] = {0};
    struct sockaddr_in server_server;
    struct sockaddr_in server_client;

    // create socket sever
    socket_server = socket(PF_INET, SOCK_STREAM, 0);
    if (socket_server < 0){
        perror("[ERROR] Socket");
        return(-1);
    }
    printf("[+] Socket\n\r");

    // Server parameters
    server_server.sin_family      = PF_INET ;  // protocol
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

    // Listen funtion
    Listen = listen(socket_server, MAXPENDING);
    if (Listen < 0){
        perror("[ERROR] Listen");
        return(-1);
    }
    printf("[+] Listen\n\r");


    while(1){

        // create socket client
        socket_client = accept(socket_server,(struct sockaddr*)&server_client, &addr_length);

        // print data
        while(recv(socket_client, buffer, sizeof(buffer),0) > 0){
            if (strncmp("GET / ", buffer, 6) == 0) // compare get request or post request
            {
                render("./index.html", socket_client);
            }
            else if (strncmp("GET /test", buffer, 9) == 0){
                render("./dashboard.html", socket_client);
            }

        }
    }

    // closed sockets
    close(socket_server);
    close(socket_client);
    return(0);
}




