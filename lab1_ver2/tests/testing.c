
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assertions.h>
#include <testing.h>
#include <float.h>
#include <support_funcs.h>



TEST(test_summation) {
    double num = 1;
    double add = 1;
    double expect = 2;
    double result = summation(num, add);
    assert(result == expect);

    num = 0;
    add = 0;
    expect = 0;
    result = summation(num, add);
    assert(result == expect);

    num = 5;
    add = DBL_MAX;
    expect = DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = 100;
    add = -DBL_MAX;
    expect = 100 - DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = -10;
    add = -DBL_MAX;
    expect = -DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = -10;
    add = DBL_MAX;
    expect = -10 + DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = 5;
    expect = DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = -100;
    expect = DBL_MAX - 100;
    result = summation(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = -10;
    expect = -DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = 10;
    expect = 10 - DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = -DBL_MAX;
    expect = -DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = DBL_MAX;
    expect = DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = -DBL_MAX;
    expect = 0;
    result = summation(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = DBL_MAX;
    expect = 0;
    result = summation(num, add);
    assert(result == expect);
    //

    num = 1.645289;
    add = 17.6200394;
    expect = 19.2653284;
    result = summation(num, add);
    assert(result == expect);

    num = 732.918471824;
    add = -109347.32434948;
    expect = -108614.405877656;
    result = summation(num, add);
    assert(result == expect);
}


TEST(test_multiplication) {
    double num = 1;
    double add = 1;
    double expect = 1;
    double result = multiplication(num, add);
    assert(result == expect);

    num = 0;
    add = 0;
    expect = 0;
    result = multiplication(num, add);
    assert(result == expect);

    num = 5;
    add = DBL_MAX;
    expect = DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = 0.5;
    add = DBL_MAX;
    expect = 0.5 * DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = 5;
    add = -DBL_MAX;
    expect = -DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = -5;
    add = DBL_MAX;
    expect = -DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = -0.5;
    add = DBL_MAX;
    expect = -0.5 * DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = -5;
    add = -DBL_MAX;
    expect = DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = 5;
    expect = DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = 0.5;
    expect = 0.5 * DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = 5;
    expect = -DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = -5;
    expect = -DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = -0.5;
    expect = -0.5*DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = -5;
    expect = DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);
    
    num = DBL_MAX;
    add = DBL_MAX;
    expect = DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = -DBL_MAX;
    expect = 10 - DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = DBL_MAX;
    expect = -DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = -DBL_MAX;
    expect = DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);
    ////////
    num = 1.6289;
    add = 17.62394;
    expect = 28.707635866;
    result = multiplication(num, add);
    assert(result == expect);

    num = 1.6289;
    add = -17.62394;
    expect = -28.707635866;
    result = multiplication(num, add);
    assert(result == expect);

    num = -1.6289;
    add = 17.62394;
    expect = -28.707635866;
    result = multiplication(num, add);
    assert(result == expect);

    num = -1.6289;
    add = -17.62394;
    expect = 28.707635866;
    result = multiplication(num, add);
    //printf("%lf", result);
    assert(result == expect);
}

TEST(test_map) {
    double (**map_funcs)(double, double) = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    double* arr = malloc(5 * sizeof(double));
    int result = map(map_funcs[0], arr, 5, 7.0);
    int expect = 0;
    assert(result == expect);
    free(map_funcs);
    free(arr);

    //map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    //map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    result = map(NULL, arr, 5, 7.0);
    expect = 1;
    assert(result == expect);
    //free(map_funcs);
    free(arr);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    //arr = malloc(5 * sizeof(double));
    result = map(map_funcs[0], NULL, 5, 7.0);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    //free(arr);

    //map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    //map_funcs[0] = &summation;  
    //arr = malloc(5 * sizeof(double));
    result = map(NULL, NULL, 5, 7.0);
    expect = 1;
    assert(result == expect);
    //free(map_funcs);
    //free(arr);

}

TEST(test_map_concat) {
    double (**map_funcs)(double, double) = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    double* arr = malloc(5 * sizeof(double));
    double* args = malloc(5 * sizeof(double));
    int* operations = malloc(5 * sizeof(int));
    size_t operation_ammount = 0;
    int result = map_concat(map_funcs, arr, 5, args, operations, operation_ammount);
    int expect = 0;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);


    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(NULL, arr, 5, args, operations, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(map_funcs, NULL, 5, args, operations, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);
    
    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(map_funcs, arr, 5, NULL, operations, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(map_funcs, arr, 5, args, NULL, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(NULL, NULL, 5, args, operations, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(NULL, arr, 5, NULL, operations, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(NULL, arr, 5, args, NULL, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(map_funcs, NULL, 5, NULL, operations, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(map_funcs, NULL, 5, args, NULL, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(map_funcs, arr, 5, NULL, NULL, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(NULL, NULL, 5, NULL, operations, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(NULL, NULL, 5, args, NULL, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(NULL, arr, 5, NULL, NULL, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);
    
    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(map_funcs, NULL, 5, NULL, NULL, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

    map_funcs = malloc(2 * sizeof(double(*) (double, double)));
    map_funcs[0] = &summation;  
    arr = malloc(5 * sizeof(double));
    args = malloc(5 * sizeof(double));
    operations = malloc(5 * sizeof(int));
    operation_ammount = 0;
    result = map_concat(NULL, NULL, 5, NULL, NULL, operation_ammount);
    expect = 1;
    assert(result == expect);
    free(map_funcs);
    free(arr);
    free(args);
    free(operations);

}


TEST(divider_on_by_zero_division) {
    int num = 27283;
    int del = 0;
    int cond = 0;
    int expect = 0;
    int result = divider(num, del, cond);
    assert(result == expect);
}

TEST(test_divider) {
    double num = 2.375;
    double del = 235.6;
    int cond = 1;
    double expect = 0;
    double result = divider(num, del, cond);
    assert(result == expect);

    num = 27283;
    del = 0;
    cond = 0;
    expect = 0;
    result = divider(num, del, cond);
    assert(result == expect);

    num = 0;
    del = 1209.293;
    cond = 0;
    expect = 0;
    result = divider(num, del, cond);
    assert(result == expect);

    num = 0;
    del = 0;
    cond = 0;
    expect = 0;
    result = divider(num, del, cond);
    assert(result == expect);

    num = 2938.283716;
    del = -12937.348732;
    cond = 1;
    expect = 0;
    result = divider(num, del, cond);
    assert(result == expect);

    num = -3232.28347236;
    del = 322.42387;
    cond = 1;
    expect = 0;
    result = divider(num, del, cond);
    assert(result == expect);

    num = -234.42513;
    del = -847.47389;
    cond = 1;
    expect = 0;
    result = divider(num, del, cond);
    assert(result == expect);

    num = 2.375;
    del = 235.6;
    cond = 0;
    expect = 1;
    result = divider(num, del, cond);
    assert(result == expect);

    num = 27283;
    del = 0;
    cond = 1;
    expect = 0;
    result = divider(num, del, cond);
    assert(result == expect);

    num = 0;
    del = 1209.293;
    cond = 1;
    expect = 1;
    result = divider(num, del, cond);
    assert(result == expect);

    num = 0;
    del = 0;
    cond = 1;
    expect = 0;
    result = divider(num, del, cond);
    assert(result == expect);

    num = 2938.283716;
    del = -12937.348732;
    cond = 0;
    expect = 1;
    result = divider(num, del, cond);
    assert(result == expect);

    num = -3232.28347236;
    del = 322.42387;
    cond = 0;
    expect = 1;
    result = divider(num, del, cond);
    assert(result == expect);

    num = -234.42513;
    del = -847.47389;
    cond = 0;
    expect = 1;
    result = divider(num, del, cond);
    assert(result == expect);
}

TEST(test_bounds) {
    double num = 2.375;
    double del = 235.6;
    int cond = 1;
    double expect = 0;
    double result = bounds(num, del, cond);
    assert(result == expect);

    num = 235.6;
    del = 2.375;
    cond = 1;
    expect = 1;
    result = bounds(num, del, cond);
    assert(result == expect);

    num = 235.6;
    del = 2.375;
    cond = 0;
    expect = 0;
    result = bounds(num, del, cond);
    assert(result == expect);

    num = 1209.293;
    del = -1;
    cond = 1;
    expect = 1;
    result = bounds(num, del, cond);
    assert(result == expect);

    num = -1;
    del = 1209.293;
    cond = 1;
    expect = 0;
    result = bounds(num, del, cond);
    assert(result == expect);

    num = -1;
    del = 1209.293;
    cond = 0;
    expect = 1;
    result = bounds(num, del, cond);
    assert(result == expect);

    num = -1;
    del = -1209.293;
    cond = 0;
    expect = 0;
    result = bounds(num, del, cond);
    assert(result == expect);

    num = -1209.293;
    del = -1;
    cond = 0;
    expect = 1;
    result = bounds(num, del, cond);
    assert(result == expect);

    num = -1209.293;
    del = -1;
    cond = 1;
    expect = 0;
    result = bounds(num, del, cond);
    assert(result == expect);

    num = 10;
    del = 10;
    cond = 1;
    expect = 1;
    result = bounds(num, del, cond);
    assert(result == expect);

    num = 10;
    del = 10;
    cond = 0;
    expect = 1;
    result = bounds(num, del, cond);
    assert(result == expect);
}

TEST(test_where){
    size_t* size = 0;
    int (**where_funcs)(double, double, int) = malloc(1 * sizeof(int(*) (double, double, int))); 
    where_funcs[0] = &bounds; 
    double* arr = malloc(5 * sizeof(double));
    double cond_data = 0;
    int cond = 0;
    double* result = where(NULL, arr, size, cond_data, cond);
    double* expect = NULL;
    assert(result == expect);
    free(where_funcs);
    free(arr);

    size = 0;
    where_funcs = malloc(1 * sizeof(int(*) (double, double, int))); 
    where_funcs[0] = &bounds; 
    arr = malloc(5 * sizeof(double));
    cond_data = 0;
    cond = 0;
    result = where(where_funcs[0], NULL, size, cond_data, cond);
    expect = NULL;
    assert(result == expect);
    free(where_funcs);
    free(arr);

    size = 0;
    where_funcs = malloc(1 * sizeof(int(*) (double, double, int))); 
    where_funcs[0] = &bounds; 
    arr = malloc(5 * sizeof(double));
    cond_data = 0;
    cond = 0;
    result = where(where_funcs[0], arr, NULL, cond_data, cond);
    expect = NULL;
    assert(result == expect);
    free(where_funcs);
    free(arr);

    size = 0;
    where_funcs = malloc(1 * sizeof(int(*) (double, double, int))); 
    where_funcs[0] = &bounds; 
    arr = malloc(5 * sizeof(double));
    cond_data = 0;
    cond = 0;
    result = where(NULL, NULL, size, cond_data, cond);
    expect = NULL;
    assert(result == expect);
    free(where_funcs);
    free(arr);

    size = 0;
    where_funcs = malloc(1 * sizeof(int(*) (double, double, int))); 
    where_funcs[0] = &bounds; 
    arr = malloc(5 * sizeof(double));
    cond_data = 0;
    cond = 0;
    result = where(NULL, arr, NULL, cond_data, cond);
    expect = NULL;
    assert(result == expect);
    free(where_funcs);
    free(arr);

    size = 0;
    where_funcs = malloc(1 * sizeof(int(*) (double, double, int))); 
    where_funcs[0] = &bounds; 
    arr = malloc(5 * sizeof(double));
    cond_data = 0;
    cond = 0;
    result = where(where_funcs[0], NULL, NULL, cond_data, cond);
    expect = NULL;
    assert(result == expect);
    free(where_funcs);
    free(arr);

    size = 0;
    where_funcs = malloc(1 * sizeof(int(*) (double, double, int))); 
    where_funcs[0] = &bounds; 
    arr = malloc(5 * sizeof(double));
    cond_data = 0;
    cond = 0;
    result = where(NULL, NULL, NULL, cond_data, cond);
    expect = NULL;
    assert(result == expect);
    free(where_funcs);
    free(arr);
}
//-------------------------------------------------------------------full_ready tests


/*
double* where_concat(int (**where_funcs)(double, double, int), double* arr, 
                    size_t* size, double* cond_data_array, int* cond_array, 
                    size_t operations_ammount, int* operations){
*/
