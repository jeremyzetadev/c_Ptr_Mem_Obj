#include <stdlib.h>
#include "object.h"

Object_t *new_integer(int value){
    Object_t *obj = malloc(sizeof(Object_t));
    if(obj == NULL) {return NULL;}

    obj->kind = INTEGER;
    obj->data.v_int = value;

    return obj;
}
