#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include "sys_funcs.h"
#include "support_funcs.h"

// map часть 
double summation(double num, double addit) {
    if(num > 0 && addit > 0 && num >= DBL_MAX - addit){
        return DBL_MAX;
    }
    if(num < 0 && addit < 0 && num < -DBL_MAX - addit){
        return -DBL_MAX;
    }
    return num + addit;

}


double multiplication(double num, double addit) {
    if((num > 1 && addit > 1) && num > DBL_MAX / addit){
        return DBL_MAX;
    }
    if((num < -1 && addit < -1) && -1 * num > DBL_MAX / (-1 * addit)){
        return DBL_MAX;
    }
    if(num < -1 && addit > 1 && -1 * num > DBL_MAX / addit){
        return -DBL_MAX;
    }
    if((num > 1 && addit < -1) &&  num > DBL_MAX / (-1 * addit)){
        return -DBL_MAX;
    }
    return num * addit;

}


int map(double (*func) (double, double), double* arr, int size, double data){
    if(func == NULL || arr == NULL){
        printf("Ошибка передачи данных в map\n");
        return 1;
    }
    for(int i = 0; i < size; i++){
        arr[i] = func(arr[i], data);
    }
    return 0;
}

int map_concat(double (**map_funcs)(double, double), double* arr, 
                        int size, double* args, int* operations, 
                        size_t operations_ammount) {
    if(map_funcs == NULL || arr == NULL || args == NULL || operations == NULL){
        printf("Ошибка передачи данных в map_concat\n");
        return 1;
    }
    for (size_t i = 0; i < operations_ammount; i++){
        map(map_funcs[operations[i]], arr, size, args[i]);
    }
    return 0;
}



//where часть
int divider(double num, double numer, int cond){ // cond = 1 - дел cond = 0 - недел
    //printf("qqqqqq");
    if((int)numer == 0){
        return 0;
    }
    if(((int)num % (int)numer == 0) == cond){
        return 1;
    }
    return 0;
}

int bounds(double num, double bound, int cond){ // cond = 0 - верх cond = 1 - низ
    switch(cond){
        case 0:
            return num <= bound;
            break;
        case 1:
            return num >= bound;
            break;
        default:
            printf("Такого варианта не существует.\n");
            clear_input();
    }
    return 0;
}

int is_value_between_2_and_7(double value)
 {
    return bounds(value, 2.0, 7.0);
 }

 int is_commutative(double (*func)(double, double)) {
    return (
        (func(1, 2) == func(2,1)) &&
        (func(1, 5) == func(5,1)) &&
        (func(1, 0) == func(0,1)) 
    );
 }

double* where(int(*func) (double, double, int), double* arr, size_t* size, double cond_data, int cond){
    if(func == NULL || size == NULL || (arr == NULL && *size != 0)){
        printf("Ошибка передачи данных в where\n");
        return NULL;
    }
    if(*size == 0){
        printf("Операции на пустом массиве не имеют смысла\n");
        return NULL;
    }

    double* temp = malloc(*size * sizeof(double));
    if (temp == NULL){
        printf("Память на малоке функции Where не выделилась.");
        return NULL;
    } 
    size_t result_size = 0;
    for(size_t i = 0; i < *size; i++){
        if(func(arr[i], cond_data, cond) == 1){
            temp[result_size] = arr[i];
            result_size++;
        }
    }
    if(result_size == 0){
        *size = 0;
        free(temp);
        return NULL;
    }
    double* result = realloc(temp, result_size * sizeof(double));
    if(result == NULL){
        printf("Память на реаллоке функции Where не выделилась.");
        return temp;
    }
    *size = result_size;
    return result;
}

double* where_concat(int (**where_funcs)(double, double, int), double* arr, 
                    size_t* size, double* cond_data_array, int* cond_array, 
                    size_t operations_ammount, int* operations){
    if(where_funcs == NULL || size == NULL || (arr == NULL && *size != 0) || cond_data_array == NULL ||
        cond_array == NULL || operations == NULL){
            printf("Ошибка передачи данных в where_concat\n");
            return NULL;
        }
    if(*size == 0){
        printf("Операции на пустом массиве не имеют смысла\n");
        return NULL;
    }
    double* result = NULL, *temp = NULL;
    for (size_t i = 0; i < operations_ammount; i++){
        if(*size == 0){
            printf("Операции на пустом массиве не имеют смысла\n");
            if (result != NULL){
                free(result);
            } 
            return NULL;
        }
        else if(result == NULL){
            result = where(where_funcs[operations[i]], arr, size, cond_data_array[i],cond_array[i]);
        }
        else{
            temp = result;
            result = where(where_funcs[operations[i]], result, size, cond_data_array[i],cond_array[i]);
            free(temp);
        }
        if (result == NULL){
            printf("Под данные условия ничего не подходит.\n");
            return NULL;
        }
    }
    return result;
}