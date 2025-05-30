#include <stdio.h>

typedef enum SnekObjectKind {
    INTEGER,
    FLOAT,
    BOOL,
} Snek_Object_Kind_t;

typedef struct SnekInt {
    char *name;
    int value;
} Snek_Int_t;

typedef struct SnekFloat {
    char *name;
    float value;
} Snek_Float_t;

typedef struct SnekBool {
    char *name;
    unsigned int value;
} Snek_Bool_t;

void snek_zero_out(void *ptr, Snek_Object_Kind_t kind){
    if(kind==INTEGER){
        Snek_Int_t *obj = (Snek_Int_t *)ptr;
        obj->value=22;
    } else if(kind==FLOAT){
        Snek_Float_t *obj = (Snek_Float_t *)ptr;
        obj->value=8888.88;
    } else if(kind==BOOL){
        Snek_Bool_t *obj = (Snek_Bool_t *)ptr;
        obj->value=0;
    }
}

//Void pointers can cast to anything
//Careful error-prone
int main(){
    Snek_Int_t testInt= {"Integer", 11};
    Snek_Float_t testFloat= {"Float", 999.99};
    Snek_Bool_t testBool = {"Bool",0};

    snek_zero_out(&testInt,INTEGER);
    snek_zero_out(&testFloat,FLOAT);
    snek_zero_out(&testBool,BOOL);

    printf("%d\n" ,testInt.value);
    printf("%f\n" ,testFloat.value);
    printf("%d\n" ,testBool.value);
    return 0;
}
