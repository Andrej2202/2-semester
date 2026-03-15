#ifndef SUPPORT_FUNCS_H
#define SUPPORT_FUNCS_H
// map часть 
double summation(double num, double addit);
double multiplication(double num, double mult);
int map(double (*func) (double, double), double* arr, int size, double data);
int map_concat(double (**map_funcs)(double, double), double* arr, 
                int size, double* args, int* operations, 
                size_t operations_ammount);

//where часть
int divider(double num, double numer, int cond);
int bounds(double num, double bound, int cond);
double* where(int(*func) (double, double, int), double* arr, size_t* size, double cond_data, int cond);
double* where_concat(int (**where_funcs)(double, double, int), double* arr, 
                    size_t* size, double* cond_data_array, int* cond_array, 
                    size_t operations_ammount, int* operations);

int is_value_between_2_and_7(double value);
 int is_commutative(double (*func)(double, double)) ;
#endif