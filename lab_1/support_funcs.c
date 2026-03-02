#include "support_funcs.h"

// map часть 
void summation(double* num, double addit) {
    *num += addit;
}


void multiplication(double* num, double mult) {
    *num *= mult;
}


void map(void (*func) (double*, double), double* arr, int arr_len){
    for(int i = 0; i < arr_len; i++){
        func(&arr[i], 78);
    }
}



//where часть
int parity(double num, int cond){ // cond = 1, четность cond = 0 - нечетность
    return (int)num % 2 + cond % 2;
}
