#include <float.h>
#include <stdlib.h>
#include <testing.h>
#include <assertions.h>
#include <map_funcs.h>

TEST(test_summ_10_base) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 11;
    double* result = malloc(sizeof(double));
    summ_10(num, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = DBL_MAX;
    summ_10(num, result);
    assert(*result == expect);

    *num = 15.678;
    expect = 25.678;
    summ_10(num, result);
    assert(*result == expect);


    free(num);
    free(result);
}

TEST(test_summ_10_NULL) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 0;
    double* result = malloc(sizeof(double));
    *result = 0;
    summ_10(NULL, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = 0;
    summ_10(num, NULL);
    assert(*result == expect);

    *num = 15.678;
    expect = 0;
    summ_10(NULL, NULL);
    assert(*result == expect);
    free(num);
    free(result);
}

TEST(test_summ_1511_NULL) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 0;
    double* result = malloc(sizeof(double));
    *result = 0;
    summ_1511(NULL, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = 0;
    summ_1511(num, NULL);
    assert(*result == expect);

    *num = 15.678;
    expect = 0;
    summ_1511(NULL, NULL);
    assert(*result == expect);
    free(num);
    free(result);
}

TEST(test_summ_DBL_MAX_NULL) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 0;
    double* result = malloc(sizeof(double));
    *result = 0;
    summ_DBL_MAX(NULL, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = 0;
    summ_DBL_MAX(num, NULL);
    assert(*result == expect);

    *num = 15.678;
    expect = 0;
    summ_DBL_MAX(NULL, NULL);
    assert(*result == expect);
    free(num);
    free(result);
}

TEST(test_summ_minusDBL_MAX_NULL) {
    double* num = malloc(sizeof(double));
    *num = 1;
    double expect = 0;
    double* result = malloc(sizeof(double));
    *result = 0;
    summ_minusDBL_MAX(NULL, result);
    assert(*result == expect);

    *num = DBL_MAX;
    expect = 0;
    summ_minusDBL_MAX(num, NULL);
    assert(*result == expect);

    *num = 15.678;
    expect = 0;
    summ_minusDBL_MAX(NULL, NULL);
    assert(*result == expect);
    free(num);
    free(result);
}
