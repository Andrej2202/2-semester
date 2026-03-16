#include <stdlib.h>
#include <assertions.h>
#include <testing.h>
#include <float.h>
#include <where_funcs.h>


TEST(test_is_value_positive) {
    double* num = malloc(sizeof(double));
    *num = 1;
    int expect = 1;
    int result = is_value_positive(num);
    assert(result == expect);

    *num = DBL_MAX;
    expect = 1;
    result = is_value_positive(num);
    assert(result == expect);

    *num = -DBL_MAX;
    expect = 0;
    result = is_value_positive(num);
    assert(result == expect);

    *num = -15.678;
    expect = 0;
    result = is_value_positive(num);
    assert(result == expect);

    *num = 15.678;
    expect = 1;
    result = is_value_positive(num);
    assert(result == expect);

    free(num);
}

TEST(test_is_value_negative) {
    double* num = malloc(sizeof(double));
    *num = 1;
    int expect = 0;
    int result = is_value_negative(num);
    assert(result == expect);

    *num = DBL_MAX;
    expect = 0;
    result = is_value_negative(num);
    assert(result == expect);

    *num = -DBL_MAX;
    expect = 1;
    result = is_value_negative(num);
    assert(result == expect);

    *num = -15.678;
    expect = 1;
    result = is_value_negative(num);
    assert(result == expect);

    *num = 15.678;
    expect = 0;
    result = is_value_negative(num);
    assert(result == expect);

    free(num);
}

TEST(test_where_funcs_NULL){
    int expect = 0;
    int result = is_value_positive(NULL);
    assert(result == expect);
    
    expect = 0;
    result = is_value_negative(NULL);
    assert(result == expect);

    expect = 0;
    result = is_value_between_0_and_10(NULL);
    assert(result == expect);
    
    expect = 0;
    result = is_value_even(NULL);
    assert(result == expect);

    expect = 0;
    result = is_commutative(NULL);
    assert(result == expect);

    expect = 0;
    result = is_reflexive(NULL);
    assert(result == expect);

    expect = 0;
    result = is_irreflexive(NULL);
    assert(result == expect);
}