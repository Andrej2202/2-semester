#include <stdio.h>
#include <stdlib.h>
#include <poly_array.h>

static size_t _get_double_size() {
    return sizeof(double);
}

static size_t _get_func_size() {
    return sizeof(void*);
}

static struct TypeInfoDouble _double_type = {
    .base = (struct TypeInfo){.get_elem_size = _get_double_size}
};

static struct TypeInfoFunc _func_type = {
    .base = (struct TypeInfo){.get_elem_size = _get_func_size}
};

static struct DynamicArray* _where(const struct DynamicArray * this, predicat p);

struct DynamicArray* create_double_array(size_t initial_size) {
    struct DynamicArray* d = malloc(sizeof(struct DynamicArray));
    d->t = (struct TypeInfo*)&_double_type;
    d->data = malloc(initial_size * d->t->get_elem_size());
    d->size = 0;
    d->capacity = initial_size;
    d->where = _where;
    return d;
}

struct DynamicArray* create_func_array(size_t initial_size) {
    struct DynamicArray* d = malloc(sizeof(struct DynamicArray));
    d->t = (struct TypeInfo*)&_func_type;
    d->data = malloc(initial_size * d->t->get_elem_size());
    d->size = 0;
    d->capacity = initial_size;
    d->where = _where;
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
    result_array->where = _where;

    return result_array;
}

struct DynamicArray* where(const struct DynamicArray * this, predicat p) {
    return this->where(this, p);
}