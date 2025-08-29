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

void strcpytry(){
    char s1_dest[] = "abcdef";
    char s1_src[] = "xyz";
    strcpy(s1_dest, s1_src);
    printf("s1: %s\n", s1_dest);

    char s4_src[] = "xyz";
    char *s4_dest;
    s4_dest = malloc(sizeof(char));
    strcpy(s4_dest, s4_src);
    printf("s4: %s\n", s4_dest);
}

void StrCpyTest(){
    // By array
    char s1_dest[] = "abcdef";
    char s1_src[] = "xyz";
    strcpy(s1_dest,s1_src); // or memcpy(s1_dest,s1_src,sizeof(s1_src));
    printf("s1: %s\n",s1_dest);
    // OK


    // https://stackoverflow.com/questions/30143902/strcpy-behaving-differently-when-two-pointers-are-assigned-strings-in-different
    // By pointer in stack
    // char *s2_dest = "abcdef";
    // char *s2_src = "xyz";
    // strcpy(s2_dest, s2_src); // or memcpy(s2_dest,s2_src,strlen(s2_src));
    // printf("s2: %s\n",s2_dest);
    // NG SEGFAULT
    
    
    // By pointer in stack
    // char *s3_dest;
    // *s3_dest= "abcdef";
    // char *s3_src = "xyz";
    // strcpy(s3_dest, s3_src); // or memcpy(s3_dest,s3_src,strlen(s3_src));
    // printf("s3: %s\n",s3_dest);
    // NG SEGFAULT

    // By pointer in heap
    char s4_src[] = "xyz";
    char *s4_dest;
    s4_dest = malloc(strlen(s4_src));
    strcpy(s4_dest,s4_src); // or memcpy(s4_dest,s4_src,strlen(s4_src));
    printf("s4: %s\n",s4_dest);
    // OK
    
    // OUTPUT
    // s1: xyz        OK
    // s2: SEGFAULT
    // s3: ERR: Assigning char from char[7]
    // s4: xyz        OK
    // OUTPUT
}

int main(){
    // ArrChar();
    // PtrChar();
    StrCpyTest();
    return 0;
}
