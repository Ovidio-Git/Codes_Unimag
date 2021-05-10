#include <stdio.h>
#include <string.h>

int login(char username[], char password[]){

    FILE *database;
    char userdb[20], passdb[20];
    char cur=0;
    // open database file
    database= fopen("database.txt", "r");
    while(1){
        // extract user and password of database

        fscanf(database,"User:%s Password:%s",userdb,passdb);
        fseek(database, cur, SEEK_SET); // go end file
        // compare data with database
        if( (strcmp(username,userdb)==0) && (strcmp(password,passdb)==0) ){
            return 1;
        }
        else{
            cur += 27;
            // return 0;
        }
        if (cur == fseek(database, cur, SEEK_END) ){
            return 0;
        }
    }
    //close database
    fclose(database);
    return 0;
}

int main(){

    char username[20], password[20];
    char aux;
    printf("Username:");
    scanf("%s",username);
    printf("Password:");
    scanf("%s",password);

    aux = login(username, password);
    printf(" -> %d", aux);
}