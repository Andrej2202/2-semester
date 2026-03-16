#include <stdlib.h>
#include <assertions.h>
#include <testing.h>
#include <float.h>
#include <where_funcs.h>
#include <where_assist_funcs.h>

TEST(test_is_commutative) {
    int (*func_ptr)(double, double) = divide;
    int expect = 0;
    int result = is_commutative((void*)&func_ptr);
    assert(result == expect);

    func_ptr = not_divide;
    expect = 0;
    result = is_commutative((void*)&func_ptr);
    assert(result == expect);

    func_ptr = upper_bound;
    expect = 0;
    result = is_commutative((void*)&func_ptr);
    assert(result == expect);

    func_ptr = lower_bound;
    expect = 0;
    result = is_commutative((void*)&func_ptr);
    assert(result == expect);

    func_ptr = equal;
    expect = 1;
    result = is_commutative((void*)&func_ptr);
    assert(result == expect);
}

TEST(test_is_reflexive) {
    int (*func_ptr)(double, double) = divide;
    int expect = 1;
    int result = is_reflexive((void*)&func_ptr);
    assert(result == expect);

    func_ptr = not_divide;
    expect = 0;
    result = is_reflexive((void*)&func_ptr);
    assert(result == expect);

    func_ptr = upper_bound;
    expect = 1;
    result = is_reflexive((void*)&func_ptr);
    assert(result == expect);

    func_ptr = lower_bound;
    expect = 1;
    result = is_reflexive((void*)&func_ptr);
    assert(result == expect);

    func_ptr = equal;
    expect = 1;
    result = is_reflexive((void*)&func_ptr);
    assert(result == expect);
}

TEST(test_is_irreflexive) {
    int (*func_ptr)(double, double) = divide;
    int expect = 0;
    int result = is_irreflexive((void*)&func_ptr);
    assert(result == expect);

    func_ptr = not_divide;
    expect = 1;
    result = is_irreflexive((void*)&func_ptr);
    assert(result == expect);

    func_ptr = upper_bound;
    expect = 0;
    result = is_irreflexive((void*)&func_ptr);
    assert(result == expect);

    func_ptr = lower_bound;
    expect = 0;
    result = is_irreflexive((void*)&func_ptr);
    assert(result == expect);

    func_ptr = equal;
    expect = 0;
    result = is_irreflexive((void*)&func_ptr);
    assert(result == expect);
}