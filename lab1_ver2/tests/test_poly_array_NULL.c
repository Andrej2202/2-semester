#include <testing.h>
#include <assertions.h>
#include <poly_array.h>
#include <where_funcs.h>
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
    void* result = where(this, NULL);
    void* expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);

    this = create_double_array(1);
    result = where(NULL, (predicat)is_value_even);
    expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);

    this = create_double_array(1);
    result = where(NULL, NULL);
    expect = NULL;
    assert(result == expect);
    free(this->data);
    free(this);
}

TEST(test_concat_NULL){
    struct DynamicArray* arr1 = create_double_array(1);
    struct DynamicArray* arr2 = create_double_array(1);
    void* result = concat(arr1, NULL);
    void* expect = NULL;
    assert(result == expect);
    free(arr1->data);
    free(arr1);
    free(arr2->data);
    free(arr2);

    arr1 = create_double_array(1);
    arr2 = create_double_array(1);
    result = concat(NULL, arr2);
    expect = NULL;
    assert(result == expect);
    free(arr1->data);
    free(arr1);
    free(arr2->data);
    free(arr2);

    arr1 = create_double_array(1);
    arr2 = create_double_array(1);
    result = concat(NULL, NULL);
    expect = NULL;
    assert(result == expect);
    free(arr1->data);
    free(arr1);
    free(arr2->data);
    free(arr2);
}