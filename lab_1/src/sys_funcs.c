#include <stdio.h>
#include <stdlib.h> 
#include "sys_funcs.h"

int clear_input(){
    int c, counter = 0;
    while ((c = getchar()) != '\n' && c != EOF){
        counter++;
    }
    return counter;
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear"); 
#endif
}