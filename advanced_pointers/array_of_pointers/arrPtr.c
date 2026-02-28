#include <stdlib.h>
#include <stdio.h>

typedef struct Token{
    // char* if not malloc will be added to stack, from created token(heap), char*(stack) -> the char is not needed to free
    char* literal;      
    int line;
    int column;
} token_t;

typedef struct Tok_{
    char* literal;
    int line;
    int column;
} Tok_t;

token_t** create_token_pointer_array(token_t* tokens, size_t count){
    token_t** token_pointers = malloc(sizeof(token_t*) * count);
    if(token_pointers == NULL)
        exit(1);

    for(size_t i=0; i< count; i++){
        token_t *pointer = malloc(sizeof(token_t));
        token_pointers[i] = pointer;
        *pointer = tokens[i];
        //token_pointers[i] = tokens[i]; is same as *pointer=tokens[i];
    }

    return token_pointers;
}

void printCharsOfToken(token_t **token_pointers, size_t count){
    // Print using strings
    // for(size_t i=0; i<count; i++){
    //     printf("%s\n",token_pointers[i]->literal);
    // }

    // Print using chars
    for(int i=0; i<count; i++){
        char* currentString = token_pointers[i]->literal;
        for(int j=0; currentString[j]!='\0'; j++){
            printf("%c\n",currentString[j]);
        }
    }
}

int main(){
    // char **string_array = malloc(sizeof(char)*3);
    // string_array[0] = "foo";
    // string_array[1] = "bar";
    // string_array[2] = "baz";

    // single token in array
    size_t size = 1;
    token_t token = {"hello",1,size};
    token_t **result = create_token_pointer_array(&token, size);
    printCharsOfToken(result,size);
    free(result[0]);
    free(result);

    // multiple token in array
    size = 3;
    token_t tokens[3] = {
        {"foo",1,1},
        {"bar",2,5},
        {"baz",3,10}
    };
    token_t **tokenArr = create_token_pointer_array(tokens, size);
    printCharsOfToken(tokenArr,size);
    for (int i = 0; i < 3; i++) {
        free(tokenArr[i]);
    }
    free(tokenArr);

    return 0;
}
