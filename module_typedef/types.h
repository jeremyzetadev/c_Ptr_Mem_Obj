#include<inttypes.h>

extern int global_int;  // Dont assign value here, assign at different place

int test_int = 5;  //can access everywhere if imported this module

static int test_int_static = 6; // NG FOR HEADER FILES TO USE STATIC CANNOT BE INTERNAL

typedef uint8_t u8;
