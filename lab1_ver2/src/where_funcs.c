#include <stdio.h>
#include <where_funcs.h>
#include <where_assist_funcs.h>

int is_value_positive(void* value){
    if(value == NULL){
        printf("Ошибка передачи данных в is_value_positive\n");
        return 0;
    }
    return lower_bound(*(double*)value, 0.0);
}

int is_value_negative(void* value){
    if(value == NULL){
        printf("Ошибка передачи данных в is_value_negative\n");
        return 0;
    }
    return upper_bound(*(double*)value, 0.0);
}

int is_value_between_0_and_10(void* value){
    if(value == NULL){
        printf("Ошибка передачи данных в is_value_between_0_and_10\n");
        return 0;
    }
    return lower_bound(*(double*)value, 0.0) && upper_bound(*(double*)value, 10);
}

int is_value_even(void* value){
    if(value == NULL){
        printf("Ошибка передачи данных в is_value_even\n");
        return 0;
    }
    return divide(*(double*)value, 2.0);
}

int is_commutative(void* elem_ptr){ 
    if(elem_ptr == NULL){
        printf("Ошибка передачи данных в is_commutative\n");
        return 0;
    }
    int (*func)(double, double) = *(int (**)(double, double))elem_ptr;

    return (
        (func(1, 2) == func(2,1)) &&
        (func(1, 5) == func(5,1)) &&
        (func(1, 0) == func(0,1)) 
    );
 }

int is_reflexive(void* elem_ptr) {
    if(elem_ptr == NULL){
        printf("Ошибка передачи данных в is_reflexive\n");
        return 0;
    }
    int (*func)(double, double) = *(int (**)(double, double))elem_ptr;

    return (
        (func(10, 10) == 1) &&
        (func(1, 1) == 1) &&
        (func(-10, -10) == 1)
    );
}

int is_irreflexive(void* elem_ptr) {
    if(elem_ptr == NULL){
        printf("Ошибка передачи данных в is_irreflexive\n");
        return 0;
    }
    int (*func)(double, double) = *(int (**)(double, double))elem_ptr;
    
    return (
        (func(10, 10) == 0) &&
        (func(1, 1) == 0) &&
        (func(-10, -10) == 0)
    );
}