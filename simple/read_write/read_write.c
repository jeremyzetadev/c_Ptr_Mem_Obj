#include <stdio.h>
#include <stdlib.h>


int readFile(){
    FILE *fptr = NULL;
    // relative path example: 
    // fptr = fopen("assets/test.txt", "r");
    // fptr = fopen("../test.txt", "r");
    fptr = fopen("test.txt", "r");
    char myString[100];
    if(fptr!=NULL){
        while(fgets(myString, 100, fptr)){
            printf("%s", myString);
        }
    } else {
        printf("Not able to open the file.");
        return 1;
    }
    fclose(fptr);
    return 0;
}

int writeFile(){
    FILE *fptr = NULL;
    // relative path example: 
    // fptr = fopen("assets/test.txt", "r");
    // fptr = fopen("../test.txt", "r");
    fptr = fopen("test.txt", "w");  // "a" -> for append
    if(fptr!=NULL){
        fprintf(fptr, "This is first line.\n");
        fprintf(fptr, "This is second line, num:%d.\n", 100);
    } else {
        printf("Not able to open the file.");
        return 1;
    }
    fclose(fptr);
    return 0;
}

typedef struct Person {
    int id;
    char fname[20];
    char lname[20];
} Person_t;

int serialize(){
    FILE* fptr;
    fptr = fopen("person1.dat", "wb+"); // write binary plus(file must exist)
    if(!fptr){
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    Person_t write_struct = {1, "John", "Doe"};

    fwrite(&write_struct, sizeof(write_struct), 1, fptr);
    fclose(fptr);
    return 0;
}

int deserialize(){
    FILE* fptr;
    fptr = fopen("person1.dat", "rb+");
    if(!fptr){
        fprintf(stderr, "Error opening file\n");
        exit(1);
    }
    Person_t read_struct;

    fread(&read_struct, sizeof(read_struct), 1, fptr);
    printf("Name: %s %s \nID: %d", read_struct.fname, read_struct.lname, read_struct.id);
    fclose(fptr);
    return 0;
}


int main(){
    //writeFile();
    //readFile();
    //serialize();
    deserialize();
    return 0;
}
