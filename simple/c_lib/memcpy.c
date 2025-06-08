#include <stdio.h>
#include <string.h>

void mem_cpy(){
    const char src[100] = "Hello ";
    char des[100];
    strcpy(des," World");
    printf("Before copy mem = %s\n", des);
    memcpy(des,src, strlen(src) + 1);
    printf("After copy mem = %s\n\n", des);
}

void mem_cpy2(){
    char first_str[] = "GoodBye";
    char sec_str[] = " World";

    puts("first_str before copy mem:");
    puts(first_str);

    memcpy(first_str, sec_str, sizeof(sec_str));

    puts("\nfirst_str after memcpy:");
    puts(first_str);
}

int main(){
    mem_cpy();
    mem_cpy2();
}
