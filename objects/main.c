#include <stdlib.h>
#include "object.h"
#include <stdio.h>
// #include "munit.h"

int main(){
    Object_t *obj = malloc(sizeof(Object_t));
    obj->kind = INTEGER;
    obj->data.v_int = 100;

    printf("The kind is %s\n",(char *)&(obj->kind));
    printf("The value is %d\n",obj->data.v_int);
    // printf("The kind is %s\n",obj->kind);
    // printf("The value is %s\n",obj->data.v_int);

    free(obj);
}
