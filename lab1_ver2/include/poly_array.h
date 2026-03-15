#ifndef POLY_ARRAY_H
#define POLY_ARRAY_H
struct TypeInfo {
    size_t (*get_elem_size)();
};

typedef int (*predicat)(void*);

struct DynamicArray{
    void* data;
    struct TypeInfo* t;
    size_t size;
    size_t capacity;
    struct DynamicArray* (*where) (const struct DynamicArray* this, predicat p);
};

struct TypeInfoDouble{
    struct TypeInfo base;
};

struct TypeInfoFunc{
    struct TypeInfo base;
};

struct DynamicArray* create_double_array(size_t initial_size);
struct DynamicArray* create_func_array(size_t initial_size);
struct DynamicArray* where(const struct DynamicArray * this, predicat p);
#endif