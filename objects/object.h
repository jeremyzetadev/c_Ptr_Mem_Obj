typedef enum ObjectKind{
    INTEGER
} Object_Kind_t;

typedef union ObjectData{
    int v_int;
} Object_Data_t;

typedef struct Object{
    Object_Kind_t kind;
    Object_Data_t data;
} Object_t;
