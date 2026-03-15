#include <stdio.h>
#include <stdlib.h>
#include <sys_funcs.h>
#include <poly_array.h>
#include <where_funcs.h>
#define MAX_SIZE 100000
#define R_MAX_NUM 100000


int main() {
    struct DynamicArray* doubles = create_double_array(10);
    for(int i = 0; i < 10; i++){
        ((double*)doubles->data)[i] = i;
    }
    doubles->size = 10;
    printf("Кол-во эл-тов в дата(до): %lld\n", doubles->size);
    doubles = where(doubles, (predicat)is_value_between_2_and_7);
    //
    printf("Кол-во эл-тов в дата(после): %lld\n", doubles->size);

    struct DynamicArray* funcs = create_func_array(10);
    ((void**)funcs->data)[0] = (void*)base_bound;
    ((void**)funcs->data)[1] = (void*)lower_bound;
    funcs->size = 2;

    funcs = where(funcs, (predicat)is_commutative);
    printf("Кол-во эл-тов в дата(после): %lld\n", funcs->size);
    return 0;
}