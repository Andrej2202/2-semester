#include <float.h>
#include <stdlib.h>
#include <testing.h>
#include <assertions.h>
#include <map_funcs.h>

TEST(test_multiplication_1_base) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 1;
    double* result = malloc(sizeof(double));
    multiplication_1(num, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = DBL_MAX;
    multiplication_1(num, result);
    assert(*result == expect);

    *num = 15.678;
    expect = 15.678;
    multiplication_1(num, result);
    assert(*result == expect);


    free(num);
    free(result);
}

TEST(test_multiplication_1_NULL) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 0;
    double* result = malloc(sizeof(double));
    *result = 0;
    multiplication_1(NULL, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = 0;
    multiplication_1(num, NULL);
    assert(*result == expect);

    *num = 15.678;
    expect = 0;
    multiplication_1(NULL, NULL);
    assert(*result == expect);
    free(num);
    free(result);
}

TEST(test_multiplication_0_NULL) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 0;
    double* result = malloc(sizeof(double));
    *result = 0;
    multiplication_0(NULL, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = 0;
    multiplication_0(num, NULL);
    assert(*result == expect);

    *num = 15.678;
    expect = 0;
    multiplication_0(NULL, NULL);
    assert(*result == expect);
    free(num);
    free(result);
}

TEST(test_multiplication_minus_500_NULL) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 0;
    double* result = malloc(sizeof(double));
    *result = 0;
    multiplication_minus_500(NULL, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = 0;
    multiplication_minus_500(num, NULL);
    assert(*result == expect);

    *num = 15.678;
    expect = 0;
    multiplication_minus_500(NULL, NULL);
    assert(*result == expect);
    free(num);
    free(result);
}

TEST(test_square_MAX_NULL) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 0;
    double* result = malloc(sizeof(double));
    *result = 0;
    square(NULL, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = 0;
    square(num, NULL);
    assert(*result == expect);

    *num = 15.678;
    expect = 0;
    square(NULL, NULL);
    assert(*result == expect);
    free(num);
    free(result);
}