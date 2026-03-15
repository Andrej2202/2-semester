#include <stdio.h>
#include <stdlib.h>
#include <poly_array.h>

static struct DynamicArray* _where(const struct DynamicArray * this, predicat p);
static struct DynamicArray* _concat(const struct DynamicArray* arr1, const struct DynamicArray* arr2);
static struct DynamicArray* _map(const struct DynamicArray* this, transformer t);


static size_t _get_double_size(){
    return sizeof(double);
}
static size_t _get_func_size(){
    return sizeof(void*);
}


static struct TypeInfoDouble _double_type = {
    .base = (struct TypeInfo){
        .get_elem_size = _get_double_size,
        .where = _where,
        .concat = _concat
    },
    .map = _map
};
static struct TypeInfoFunc _func_type = {
    .base = (struct TypeInfo){
        .get_elem_size = _get_func_size,
        .where = _where,
        .concat = _concat
    }
};


struct DynamicArray* create_double_array(size_t initial_size){
    struct DynamicArray* d = malloc(sizeof(struct DynamicArray));
    d->t = (struct TypeInfo*)&_double_type;
    d->data = malloc(initial_size * d->t->get_elem_size());
    d->size = 0;
    d->capacity = initial_size;
    d->t->where = _where;
    d->t->concat = _concat;
    return d;
}
struct DynamicArray* create_func_array(size_t initial_size){
    struct DynamicArray* d = malloc(sizeof(struct DynamicArray));
    d->t = (struct TypeInfo*)&_func_type;
    d->data = malloc(initial_size * d->t->get_elem_size());
    d->size = 0;
    d->capacity = initial_size;
    d->t->where = _where;
    d->t->concat = _concat;
    return d;
}


static struct DynamicArray* _where(const struct DynamicArray * this, predicat p){
    if(this == NULL || p == NULL){
        printf("Ошибка передачи данных в where\n");
        return NULL;
    }
    size_t elem_size = this->t->get_elem_size();
    char* temp = malloc(this->size * elem_size);
    if (temp == NULL){
        printf("Память на малоке функции Where не выделилась.");
        return NULL;
    } 

    size_t result_size = 0;
    for(size_t i = 0; i < this->size; i++){
        char* current_elem = (char*)this->data + i * elem_size; 
        if(p(current_elem) == 1){
            char* write_pos = temp + result_size * elem_size;
            for(size_t k = 0; k < elem_size; k++){
                write_pos[k] = current_elem[k];
            }
            result_size++;
        }
    }
    if(result_size == 0){
        free(temp);
        return NULL;
    }

    char* result_data = realloc(temp, result_size * elem_size);
    if(result_data == NULL){
        printf("Память на реаллоке функции Where не выделилась.");
        return NULL;
    }
    struct DynamicArray* result_array = malloc(sizeof(struct DynamicArray));
    if (result_array == NULL) {
        free(result_data);
        return NULL;
    }
    result_array->data = result_data;
    result_array->size = result_size;
    result_array->capacity = result_size;
    result_array->t = this->t;

    return result_array;
}
struct DynamicArray* where(const struct DynamicArray * this, predicat p){
    return this->t->where(this, p);
}


static struct DynamicArray* _concat(const struct DynamicArray* arr1, const struct DynamicArray* arr2){
    if(arr1 == NULL || arr2 == NULL){
        return NULL;
    }
    if (arr1->t != arr2->t) {
        printf("Ошибка: попытка конкатенации массивов разных типов.\n");
        return NULL;
    }
    size_t elem_size = arr1->t->get_elem_size();
    size_t new_size = arr1->size + arr2->size;


    struct DynamicArray* result = malloc(sizeof(struct DynamicArray));
    if (result == NULL) {
        return NULL;
    }
    result->data = malloc(new_size * elem_size);
    if (result->data == NULL) {
        free(result);
        return NULL;
    }


    char* dest = (char*)result->data;
    const char* src1 = (char*)arr1->data;
    for (size_t i = 0; i < arr1->size * elem_size; i++) {
        dest[i] = src1[i];
    } 
    const char* src2 = (char*)arr2->data;
    size_t offset = arr1->size * elem_size;
    for (size_t i = 0; i < arr2->size * elem_size; i++) {
        dest[offset + i] = src2[i];
    }


    result->size = new_size;
    result->capacity = new_size;
    result->t = arr1->t;
    return result;
}
struct DynamicArray* concat(const struct DynamicArray* arr1, const struct DynamicArray* arr2){
    return arr1->t->concat(arr1, arr2);
}


static struct DynamicArray* _map(const struct DynamicArray* this, transformer t){
    if(this == NULL || t == NULL){
        printf("Ошибка передачи данных в map\n");
        return NULL;
    }
    size_t elem_size = this->t->get_elem_size();
    
    struct DynamicArray* result_array = malloc(sizeof(struct DynamicArray));
    if (result_array == NULL) {
        return NULL;
    }
    
    result_array->data = malloc(this->size * elem_size);
    if (result_array->data == NULL) {
        free(result_array);
        return NULL;
    }

    result_array->size = this->size;
    result_array->capacity = this->size;
    result_array->t = this->t;

    char* src = (char*)this->data;
    char* dest = (char*)result_array->data;
    
    for(size_t i = 0; i < this->size; i++){
        t(src + i * elem_size, dest + i * elem_size);
    }

    return result_array;
}
struct DynamicArray* map(const struct DynamicArray* this, transformer t){
    struct TypeInfoDouble* double_type = (struct TypeInfoDouble*)this->t;
    if (double_type->map == NULL) {
        printf("Ошибка: map не поддерживается для данного типа массива.\n");
        return NULL;
    }
    return double_type->map(this, t);
}