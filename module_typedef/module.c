static int count = 0;  //can only be access within module.c

int count_increment(){
    count++;
}

static int count_decrement(){  //can only be access within module.
    count--;
}

int count_getVal(){
    return count;
}
