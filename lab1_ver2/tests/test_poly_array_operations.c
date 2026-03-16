#include <testing.h>
#include <assertions.h>

#include <poly_array.h>
#include <where_funcs.h>
#include <map_funcs.h>

#include <stdlib.h>
#include <float.h>

TEST(test_map_operations){
    struct DynamicArray* this = create_double_array(1);
    ((double*)this->data)[0] = 0;
    this->size = 1;
    void* res_struct = map(this, summ_10);
    double expect = 10;
    double result = ((double*)((struct DynamicArray*)res_struct)->data)[0];
    assert(result == expect);
    free(this->data);
    free(this);
    free(((struct DynamicArray*)res_struct)->data);
    free((struct DynamicArray*)res_struct);

    this = create_double_array(1);
    ((double*)this->data)[0] = -100;
    this->size = 1;
    res_struct = map(this, summ_DBL_MAX);
    expect = DBL_MAX - 100;
    result = ((double*)((struct DynamicArray*)res_struct)->data)[0];
    assert(result == expect);
    free(this->data);
    free(this);
    free(((struct DynamicArray*)res_struct)->data);
    free((struct DynamicArray*)res_struct);

    this = create_double_array(1);
    ((double*)this->data)[0] = -100;
    this->size = 1;
    res_struct = map(this, summ_1511);
    expect = 1411;
    result = ((double*)((struct DynamicArray*)res_struct)->data)[0];
    assert(result == expect);
    free(this->data);
    free(this);
    free(((struct DynamicArray*)res_struct)->data);
    free((struct DynamicArray*)res_struct);
}

TEST(test_where_operations){
    struct DynamicArray* this = create_double_array(2);
    ((double*)this->data)[0] = 0;
    ((double*)this->data)[1] = 1;
    this->size = 2;
    void* res_struct = where(this, is_value_even);
    double expect = 1;
    double result = ((struct DynamicArray*)res_struct)->size;
    assert(result == expect);
    free(this->data);
    free(this);
    free(((struct DynamicArray*)res_struct)->data);
    free((struct DynamicArray*)res_struct);

    this = create_double_array(2);
    ((double*)this->data)[0] = 0;
    ((double*)this->data)[1] = 4;
    this->size = 2;
    res_struct = where(this, is_value_even);
    expect = 2;
    result = ((struct DynamicArray*)res_struct)->size;
    assert(result == expect);
    free(this->data);
    free(this);
    free(((struct DynamicArray*)res_struct)->data);
    free((struct DynamicArray*)res_struct);

    this = create_double_array(2);
    ((double*)this->data)[0] = 1;
    ((double*)this->data)[1] = 3;
    this->size = 2;
    res_struct = where(this, is_value_even);
    void* expect_res = NULL;
    assert(res_struct == expect_res);
    free(this->data);
    free(this);
}


TEST(test_concat_NULL){
    struct DynamicArray* arr1 = create_double_array(2);
    ((double*)arr1->data)[0] = 0;
    ((double*)arr1->data)[1] = 1;
    arr1->size = 2;
    struct DynamicArray* arr2 = create_double_array(2);
    ((double*)arr2->data)[0] = 2;
    ((double*)arr2->data)[1] = 3;
    arr2->size = 2;
    void* res_struct = concat(arr1, arr2);
    double expect_size = 4;
    double expect_first_value = 0;
    double expect_third_value = 2;
    double result_size = ((struct DynamicArray*)res_struct)->size;
    double result_first_elem = ((double*)((struct DynamicArray*)res_struct)->data)[0];
    double result_third_elem = ((double*)((struct DynamicArray*)res_struct)->data)[2];
    assert(result_size == expect_size);
    assert(result_first_elem == expect_first_value);
    assert(result_third_elem == expect_third_value);
    free(arr1->data);
    free(arr1);
    free(arr2->data);
    free(arr2);
    free(((struct DynamicArray*)res_struct)->data);
    free((struct DynamicArray*)res_struct);

    arr1 = create_double_array(2);
    ((double*)arr1->data)[0] = 0;
    arr1->size = 1;
    arr2 = create_double_array(2);
    ((double*)arr2->data)[0] = 2;
    arr2->size = 1;
    res_struct = concat(arr1, arr2);
    expect_size = 2;
    expect_first_value = 0;
    double expect_second_value = 2;
    result_size = ((struct DynamicArray*)res_struct)->size;
    result_first_elem = ((double*)((struct DynamicArray*)res_struct)->data)[0];
    result_third_elem = ((double*)((struct DynamicArray*)res_struct)->data)[1];
    assert(result_size == expect_size);
    assert(result_first_elem == expect_first_value);
    assert(result_third_elem == expect_second_value);
    free(arr1->data);
    free(arr1);
    free(arr2->data);
    free(arr2);
    free(((struct DynamicArray*)res_struct)->data);
    free((struct DynamicArray*)res_struct);
}
