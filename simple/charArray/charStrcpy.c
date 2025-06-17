#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ArrChar(){
    char message[40];  //Allocate stack memory for 20 chars
    strcpy(message, "By ArrChars: Hello, world");
    printf("%s\n", message);
}

void PtrChar(){
    char *message;
    message = (char*)malloc(sizeof(char) * 40); //Allocate heap memory for 20 chars
    strcpy(message, "By PtrChars: Hello, world!");
    printf("%s\n", message);
    free(message);
}

int main(){
    ArrChar();
    PtrChar();
    return 0;
}
