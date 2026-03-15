#include <float.h>
#include <stdio.h>
#include <map_funcs.h>
#include <map_assist_funcs.h>

void summ_10(void* num,  void* res){
    if(num == NULL || res == NULL){
        printf("Ошибка передачи указателей в summ_10\n");
        return;
    }
    *(double*)res = summation(*(double*) num, 10);
}

void summ_1511(void* num, void* res){
    if(num == NULL || res == NULL){
        printf("Ошибка передачи указателей в summ_10\n");
        return;
    }
    *(double*)res = summation(*(double*) num, 1511);
}

void summ_DBL_MAX(void* num, void* res){
    if(num == NULL || res == NULL){
        printf("Ошибка передачи указателей в summ_10\n");
        return;
    }
    *(double*)res = summation(*(double*) num, DBL_MAX);
}

void summ_minusDBL_MAX(void* num, void* res){
    if(num == NULL || res == NULL){
        printf("Ошибка передачи указателей в summ_10\n");
        return;
    }
    *(double*)res = summation(*(double*) num, -DBL_MAX);
}

void multiplication_1(void* num, void* res){
    if(num == NULL || res == NULL){
        printf("Ошибка передачи указателей в summ_10\n");
        return;
    }
    *(double*)res = multiplication(*(double*) num, 1);
}

void multiplication_0(void* num, void* res){
    if(num == NULL || res == NULL){
        printf("Ошибка передачи указателей в summ_10\n");
        return;
    }
    *(double*)res = multiplication(*(double*) num, 0);
}

void multiplication_minus_500(void* num, void* res){
    if(num == NULL || res == NULL){
        printf("Ошибка передачи указателей в summ_10\n");
        return;
    }
    *(double*)res = multiplication(*(double*) num, -500);
}

void square(void* num, void* res){
    if(num == NULL || res == NULL){
        printf("Ошибка передачи указателей в summ_10\n");
        return;
    }
    *(double*)res = multiplication(*(double*) num, *(double*) num);
}