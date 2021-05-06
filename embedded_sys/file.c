#include <stdio.h>
#include <stdlib.h>

int main(){
    char *ptrContent = NULL;
    long filesize = 0;
    FILE* ptrfile = NULL;
    char file[]="./index.html";

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
    printf("%s\n\r",ptrContent); // print file content
    free(ptrContent);   // freeing memory
    fclose(ptrfile);    // close file

    return (0);
}