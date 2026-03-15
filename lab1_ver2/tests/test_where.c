#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <testing.h>
#include <assertions.h>
#include <wAssist_funcs.h>



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
}
