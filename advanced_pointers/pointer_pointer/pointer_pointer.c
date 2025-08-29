#include "munit.h"
#include <stdlib.h>
#include <stdio.h>

void allocate_int(int **pointer_pointer, int value){
    int *new_pointer = malloc(sizeof(int));
    *pointer_pointer = new_pointer;
    *new_pointer = value;
}

void allocate_int_error(int *pointer, int value){
    pointer = malloc(sizeof(int));
    *pointer = value;
}

int *allocate_init_ptr(int value){
    int *new_pointer = malloc(sizeof(int));
    *new_pointer = value;
    return new_pointer;
}

// munit_case(RUN, test_allocate, {
//   int *pointer = NULL;
//   allocate_int(&pointer, 10);
//
//   assert_ptr_not_null(pointer, "Should allocate pointer");
//   assert_int(*pointer, ==, 10, "Should assign value to pointer");
//
//   free(pointer);
// });
//
// munit_case(SUBMIT, test_does_not_overwrite, {
//   int value = 5;
//   int *pointer = &value;
//
//   allocate_int(&pointer, 20);
//
//   assert_int(value, ==, 5, "Should not overwrite original value");
//
//   assert_ptr_not_null(pointer, "Should allocate pointer");
//   assert_int(*pointer, ==, 20, "Should assign value to pointer");
//
//   free(pointer);
// });

int main(){
    // Need to fix/refactor/use in the future
    // MunitTest tests[] = {
    //     munit_test("/create", test_allocate),
    //     munit_test("/overwrite", test_does_not_overwrite),
    //     munit_null_test,
    // };
    // MunitSuite suite = munit_suite("allocate_list",tests);
    //
    // return munit_suite_main(&suite, NULL, 0, NULL);
    //

      int *pointer = NULL;
      allocate_int(&pointer, 9);

      // munit_assert_ptr_not_null(pointer);
      // munit_assert_int(*pointer, ==, 10);
      printf("pointer value is:%i\n", *pointer);
      free(pointer);

      int *pointer2 = NULL;
      pointer2 = allocate_init_ptr(18);
      printf("pointer2 value is:%i\n", *pointer2);
      free(pointer2);
}
