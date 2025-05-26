#include <stdio.h>
#include <stdlib.h>
#include "munit.h"
#include <string.h>

char *get_full_greeting(char *greeting, char *name, int size){
    // ptr in stack
    // char full_greeting[100];
    // snprintf(full_greeting, 100, "%s %s", greeting, name);
    
    // ptr in heap
    char *full_greeting = malloc(size * sizeof(char));
    snprintf(full_greeting, size, "%s %s", greeting, name);
    return full_greeting;
}

int *new_int_array(int size){
    int *new_arr = (int*)malloc(size * sizeof(int));
    if(new_arr == NULL){
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    return new_arr;
}

int main(){
    // allocate heap
    int* arr_of_6 = new_int_array(6);
    arr_of_6[0] = 0;
    arr_of_6[1] = 1;
    arr_of_6[2] = 2;
    arr_of_6[3] = 3;
    arr_of_6[4] = 4;
    arr_of_6[5] = 5;
    free(arr_of_6);
    // free heap

    char *result = get_full_greeting("Hello", "Alice", 20);
    munit_assert_string_equal(result, "Hello Alice failed");
    // munit_assert_false(is_on_stack(result));
    free(result);
    return 0;
}
