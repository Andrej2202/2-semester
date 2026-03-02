#ifndef SUPPORT_FUNCS_H
#define SUPPORT_FUNCS_H
// map часть 
void summation(double* num, double addit);
void multiplication(double* num, double mult);
void map(void (*func) (double*, double), double* arr, int n);



//where часть
int parity(double num, int cond);
#endif