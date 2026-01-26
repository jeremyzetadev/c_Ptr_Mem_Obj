#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "module.h"

#define SCREEN_WIDTH 400

int module_int = 22;

int global_int = 42; // from types.h variable is assigned here

typedef enum{
    SMALL = 1,
    BIG = 1000000
} number;

typedef enum{
    RED,
    GREEN,
    BLUE
} color;

typedef struct {
    u8 keybinds[5];
} Config_State;

int main(void){
    printf("%i\n", SCREEN_WIDTH);
    printf("%i\n", module_int);
    printf("%i\n", global_int);
    
    printf("enum.number ->> the value is: %i | the bytes is :%zu\n", BIG, sizeof(BIG));
    printf("enum.color  ->> the value is: %i | the bytes is :%zu\n", GREEN, sizeof(GREEN));
    
    Config_State config_state = {0};
    config_state.keybinds[0] = BLUE;
    config_state.keybinds[1] = SMALL;
    printf("keybinds[0] ->> the value is: %i | the bytes is :%zu\n", config_state.keybinds[0], sizeof(config_state.keybinds[0]));
    printf("keybinds[1] ->> the value is: %i | the bytes is :%zu\n", config_state.keybinds[1], sizeof(config_state.keybinds[1]));
    
    printf("count: %i\n", count_getVal());
    count_increment();
    printf("count: %i\n", count_getVal());
}

