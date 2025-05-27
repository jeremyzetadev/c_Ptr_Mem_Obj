#include <stdio.h>
#include <stdlib.h>

int *allocate_scalar_list(int size, int multiplier){
    int *result = malloc(size * sizeof(int));
    if(result==NULL) return NULL;

    for(int i=0; i<size; i++)
        result[i] = i * multiplier;

    return result;
}

int main(){
    const int num_lists = 500;
    for(int i=0; i<num_lists; i++){
        int *lst = allocate_scalar_list(50000,2);
        if (lst==NULL) {
            printf("Failed to allocate list\n");
            return 1;
        } else {
            printf("Allocate list %d\n", i);
            free(lst);
        }
    }
    return 0;
}
