#include <stdio.h>

typedef struct{
    int x;
    int y;
} coord_t;

//POINTERS TO THE STACK

//error by CREATING-PTR not in heap
// coord_t *new_coord_err(int x, int y){
//     coord_t c;
//     c.x = x;
//     c.y = y;
//     return &c;
//     // error same output
//     // compiler knows
// }

//OK by CREATING-OBJ in stack
coord_t new_coord(int x, int y){
    coord_t c;
    c.x = x;
    c.y = y;
    return c;
}

int main_inline_struct_init();

int main(){
    // coord_t *c1 = new_coord_err(10, 20);
    // coord_t *c2 = new_coord_err(30, 40);
    // coord_t *c3 = new_coord_err(50, 60);

    coord_t c1 = new_coord(10, 20);
    coord_t c2 = new_coord(30, 40);
    coord_t c3 = new_coord(50, 60);


    printf("c1: %d, %d\n", c1.x, c1.y);
    printf("c2: %d, %d\n", c2.x, c2.y);
    printf("c3: %d, %d\n", c3.x, c3.y);

    main_inline_struct_init();
    return 0;
}


int main_inline_struct_init(){
    coord_t c1 = {10, 20};
    coord_t c2 = {30, 40};
    coord_t c3 = {50, 60};
    
    printf("inline init c1: %d, %d\n", c1.x, c1.y);
    printf("inline init c2: %d, %d\n", c2.x, c2.y);
    printf("inline init c3: %d, %d\n", c3.x, c3.y);
    return 0;
}

