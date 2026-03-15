#ifndef POLY_ARRAY_H
#define POLY_ARRAY_H

typedef int (*predicat)(void*);
typedef void (*transformer)(void* src, void* dest);
struct DynamicArray;

struct TypeInfo {
    size_t (*get_elem_size)();
    struct DynamicArray* (*where) (const struct DynamicArray* this, predicat p);
    struct DynamicArray* (*concat) (const struct DynamicArray* arr1, const struct DynamicArray* arr2);
};

struct DynamicArray{
    void* data;
    struct TypeInfo* t;
    size_t size;
    size_t capacity;
};

struct TypeInfoDouble{
    struct TypeInfo base;
    struct DynamicArray* (*map)(const struct DynamicArray* this, transformer t);
};
struct TypeInfoFunc{
    struct TypeInfo base;
};

struct DynamicArray* create_double_array(size_t initial_size);
struct DynamicArray* create_func_array(size_t initial_size);

struct DynamicArray* where(const struct DynamicArray * this, predicat p);
struct DynamicArray* concat(const struct DynamicArray* arr1, const struct DynamicArray* arr2);
struct DynamicArray* map(const struct DynamicArray* this, transformer t);
#endif