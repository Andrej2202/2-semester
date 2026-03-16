#include <float.h>
#include <stdlib.h>
#include <testing.h>
#include <assertions.h>
#include <map_assist_funcs.h>

TEST(test_base_summation) {
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

TEST(test_summation_boundries_with_OVF){
    double num = 5;
    double add = DBL_MAX;
    double expect = DBL_MAX;
    double result = summation(num, add);
    assert(result == expect);

    num = -10;
    add = -DBL_MAX;
    expect = -DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = 5;
    expect = DBL_MAX;
    result = summation(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = -10;
    expect = -DBL_MAX;
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
}

TEST(test_summation_boundries_without_OVF){
    double num = 100;
    double add = -DBL_MAX;
    double expect = 100 - DBL_MAX;
    double result = summation(num, add);
    assert(result == expect);


    num = -100;
    add = DBL_MAX;
    expect = -100 + DBL_MAX;
    result = summation(num, add);
    assert(result == expect);


    num = DBL_MAX;
    add = -100;
    expect = DBL_MAX - 100;
    result = summation(num, add);
    assert(result == expect);

    num = -DBL_MAX;
    add = 100;
    expect = -DBL_MAX + 100;
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
}


TEST(test_base_multiplication) {
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
    assert(result == expect);
}

TEST(test_multiplication_boundries_with_OVF){
    double num = 5;
    double add = DBL_MAX;
    double expect = DBL_MAX;
    double result = multiplication(num, add);
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
    expect = -DBL_MAX;
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
}

TEST(test_multiplication_boundries_without_OVF){
    double num = 0.5;
    double add = DBL_MAX;
    double expect = 0.5 * DBL_MAX;
    double result = multiplication(num, add);
    assert(result == expect);

    num = -0.5;
    add = DBL_MAX;
    expect = -0.5 * DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = 0.5;
    expect = 0.5 * DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);

    num = DBL_MAX;
    add = -0.5;
    expect = -0.5*DBL_MAX;
    result = multiplication(num, add);
    assert(result == expect);
}