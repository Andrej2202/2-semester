#include <stdio.h>
#include <stdlib.h>
#include <sys_funcs.h>
#include <poly_array.h>
#include <map_funcs.h>
//#include <map_assist_funcs.h>
#include <where_funcs.h>
#include <where_assist_funcs.h>


int main() {
    struct DynamicArray* doubles = create_double_array(10);
    for(int i = 0; i < 10; i++){
        ((double*)doubles->data)[i] = i;
    }
    doubles->size = 10;

    struct DynamicArray* doubles1 = create_double_array(10);
    for(int i = 0; i < 10; i++){
        ((double*)doubles1->data)[i] = i+10;
    }
    doubles1->size = 10;


    printf("Кол-во эл-тов в doubles data(до where): %lld\n", doubles->size);
    doubles = where(doubles, (predicat)is_value_even);
    printf("Кол-во эл-тов в doubles data(после where): %lld\n\n\n\n", doubles->size);


    printf("Кол-во эл-тов в doubles data, doubles1 data(до конкатинации): %lld, %lld\nМассив doubles\n[", doubles->size, doubles1->size);
    for(size_t i = 0; i < doubles->size - 1; i++){
        printf("%.3lf, ", ((double*)doubles->data)[i]);
    }
    printf("%.3lf]\nМассив doubles1\n[", ((double*)doubles->data)[doubles->size - 1]);
    for(size_t i = 0; i < doubles1->size - 1; i++){
        printf("%.3lf, ", ((double*)doubles1->data)[i]);
    }
    printf("%.3lf]\n", ((double*)doubles1->data)[doubles1->size - 1]);
    struct DynamicArray* doubles2 = concat(doubles, doubles1);
    printf("\nКол-во эл-тов в doubles2 data(после конкатинации): %lld\nМассив doubles2\n[", doubles2->size);
    for(size_t i = 0; i < doubles2->size - 1; i++){
        printf("%.3lf, ", ((double*)doubles2->data)[i]);
    }
    printf("%.3lf]\n", ((double*)doubles2->data)[doubles2->size - 1]);


    printf("\n\n\nМассив doubles до map\n[");
    for(size_t i = 0; i < doubles->size - 1; i++){
        printf("%.3lf, ", ((double*)doubles->data)[i]);
    }
    printf("%.3lf]\n", ((double*)doubles->data)[doubles->size - 1]);
    struct DynamicArray* doubles3 = map(doubles, summ_10);
    printf("\nМассив doubles3 после map\n[");
    for(size_t i = 0; i < doubles3->size - 1; i++){
        printf("%.3lf, ", ((double*)doubles3->data)[i]);
    }
    printf("%.3lf]\n\n", ((double*)doubles3->data)[doubles3->size - 1]);
    
    free(doubles->data);
    free(doubles1->data);
    free(doubles2->data);
    free(doubles3->data);
    free(doubles);
    free(doubles1);
    free(doubles2);
    free(doubles3);

    printf("--------------------------------------------------------------------------------");

    struct DynamicArray* funcs = create_func_array(3);
    ((void**)funcs->data)[0] = (void*)equal; //+
    ((void**)funcs->data)[1] = (void*)lower_bound; //-
    ((void**)funcs->data)[2] = (void*)upper_bound; //-
    funcs->size = 3;

    struct DynamicArray* funcs1 = create_func_array(3);
    ((void**)funcs1->data)[0] = (void*)equal; //+
    ((void**)funcs1->data)[1] = (void*)not_divide; //-
    ((void**)funcs1->data)[2] = (void*)divide; //-
    funcs1->size = 3;

    printf("\n\n\nКол-во эл-тов в funcs data, funcs1 data(до конкатинации): %lld, %lld\n", funcs->size, funcs1->size);
    struct DynamicArray* funcs2 = concat(funcs1, funcs);
    printf("Кол-во эл-тов в созданном funcs2 data(после конкатинации): %lld\n", funcs2->size);


    printf("\nКол-во эл-тов в funcs2 data(до where): %lld\n", funcs2->size);
    struct DynamicArray* funcs3 = where(funcs2, (predicat)is_commutative);
    printf("Кол-во эл-тов в funcs2 data(после where): %lld\n", funcs3->size);
    
    

    free(funcs->data);
    free(funcs1->data);
    free(funcs2->data);
    free(funcs3->data);
    free(funcs);
    free(funcs1);
    free(funcs2);
    free(funcs3);
    return 0;
}