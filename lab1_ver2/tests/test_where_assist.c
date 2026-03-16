#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <testing.h>
#include <assertions.h>
#include <where_assist_funcs.h>


TEST(test_equal) {
    double data = 1;
    double bound = 1;
    int result = equal(data, bound);
    int expect = 1;
    assert(result == expect);

    data = 1;
    bound = 0;
    result = equal(data, bound);
    expect = 0;
    assert(result == expect);

    data = 0;
    bound = 1;
    result = equal(data, bound);
    expect = 0;
    assert(result == expect);
}

TEST(test_lower_bound) {
    double data = 1;
    double bound = 1;
    int result = lower_bound(data, bound);
    int expect = 1;
    assert(result == expect);

    data = 1;
    bound = 0;
    result = lower_bound(data, bound);
    expect = 1;
    assert(result == expect);

    data = 0;
    bound = 1;
    result = lower_bound(data, bound);
    expect = 0;
    assert(result == expect);
}

TEST(test_upper_bound) {
    double data = 1;
    double bound = 1;
    int result = upper_bound(data, bound);
    int expect = 1;
    assert(result == expect);

    data = 1;
    bound = 0;
    result = upper_bound(data, bound);
    expect = 0;
    assert(result == expect);

    data = 0;
    bound = 1;
    result = upper_bound(data, bound);
    expect = 1;
    assert(result == expect);
}

TEST(test_divide_base) {
    double data = 10;
    double bound = 5;
    int result = divide(data, bound);
    int expect = 1;
    assert(result == expect);

    data = 10;
    bound = 6;
    result = divide(data, bound);
    expect = 0;
    assert(result == expect);

    data = 5;
    bound = 10;
    result = divide(data, bound);
    expect = 0;
    assert(result == expect);
}

TEST(test_divide_by_zero) {
    double data = 1;
    double bound = 0;
    int result = divide(data, bound);
    int expect = 0;
    assert(result == expect);

    data = 10;
    bound = 0;
    result = divide(data, bound);
    expect = 0;
    assert(result == expect);

    data = 0;
    bound = 1;
    result = divide(data, bound);
    expect = 1;
    assert(result == expect);

    data = 0;
    bound = 10;
    result = divide(data, bound);
    expect = 1;
    assert(result == expect);
}

TEST(test_not_divide_base) {
    double data = 10;
    double bound = 5;
    int result = not_divide(data, bound);
    int expect = 0;
    assert(result == expect);

    data = 10;
    bound = 6;
    result = not_divide(data, bound);
    expect = 1;
    assert(result == expect);

    data = 5;
    bound = 10;
    result = not_divide(data, bound);
    expect = 1;
    assert(result == expect);

    data = 6;
    bound = 10;
    result = not_divide(data, bound);
    expect = 1;
    assert(result == expect);
}

TEST(test_not_divide_by_zero) {
    double data = 1;
    double bound = 0;
    int result = not_divide(data, bound);
    int expect = 0;
    assert(result == expect);

    data = 10;
    bound = 0;
    result = not_divide(data, bound);
    expect = 0;
    assert(result == expect);

    data = 0;
    bound = 1;
    result = not_divide(data, bound);
    expect = 0;
    assert(result == expect);

    data = 0;
    bound = 10;
    result = not_divide(data, bound);
    expect = 0;
    assert(result == expect);
}