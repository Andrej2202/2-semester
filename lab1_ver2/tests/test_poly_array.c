#include <testing.h>
#include <assertions.h>
#include <poly_array.h>
#include <map_funcs.h>
#include <stdlib.h>


TEST(test_map_NULL){
    struct DynamicArray* this = create_double_array(1);
    void* result = map(this, NULL);
    void* expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);

    this = create_double_array(1);
    result = map(NULL, summ_10);
    expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);

    this = create_double_array(1);
    result = map(NULL, NULL);
    expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);
}

TEST(test_where_NULL){
    struct DynamicArray* this = create_double_array(1);
    void* result = map(this, NULL);
    void* expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);

    this = create_double_array(1);
    result = map(NULL, summ_10);
    expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);

    this = create_double_array(1);
    result = map(NULL, NULL);
    expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);
}

TEST(test_concat_NULL){
    struct DynamicArray* this = create_double_array(1);
    void* result = map(this, NULL);
    void* expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);

    this = create_double_array(1);
    result = map(NULL, summ_10);
    expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);

    this = create_double_array(1);
    result = map(NULL, NULL);
    expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);
}