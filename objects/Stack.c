#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Stack {
  size_t count;
  size_t capacity;
  void **data;
} Stack_t;

Stack_t *Stack_new(size_t capacity){
    Stack_t *s = malloc(sizeof(Stack_t));
    if (s==NULL) return NULL;

    s->count=0;
    s->capacity=capacity;
    s->data = malloc(sizeof(void *) * capacity);
    if(s->data == NULL) return NULL;

    return s;
}

void Stack_push(Stack_t *stack, void *obj){
    if(stack->count == stack->capacity){
        stack->capacity *=2;
        stack->data = realloc(stack->data, sizeof(void *) * stack->capacity);
        if(stack->data == NULL) {return;}
    }
    stack->data[stack->count] = obj;
    stack->count++;
}

void *Stack_pop(Stack_t *stack){
    if(stack->count==0) return NULL;
    stack->count--;
    return stack->data[stack->count];
}

void Stack_free(Stack_t *stack){
    if(stack==NULL) {return;}
    if(stack->data != NULL){
        free(stack->data);
    }
    free(stack);
}

void Stack_doublepush_Init(Stack_t *stack){
    Stack_push(stack, (void *)1337);
    
    int *ptr = malloc(sizeof(int));
    *ptr = 1024;
    Stack_push(stack, (void *)ptr);
}

void Stack_doublepush(Stack_t *stack,void *obj1, void *obj2){
    Stack_push(stack, obj1);
    Stack_push(stack, obj2);
}

void Stack_push_multipletypes(Stack_t *stack){
    float *fptr = malloc(sizeof(float));
    *fptr = 3.14;
    Stack_push(stack,(void *)fptr);

    char *value = "Sneklang is blazingly slow";
    size_t len = strlen(value) +1 ;

    char *string = malloc(sizeof(char) * len);
    strcpy(string,value);
    Stack_push(stack,string);
}

int main(){
    Stack_t *s = Stack_new(3);
    Stack_push(s, (void *)1);
    Stack_push(s, (void *)"Hello");

    printf("%zu\n",s->count);
    // printf("%d\n",(int *)s->data);
    printf("%lu\n", s->capacity);
    free(s);
}
