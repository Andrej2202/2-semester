#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys_funcs.h"
#include "text_blocks.h"
#include "support_funcs.h"
#define MAX_SIZE 100000
#define R_MAX_NUM 100000
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))


void auto_fill(double *arr, int size){
    for (int i = 0; i < size; i++) {
        arr[i] = (double)rand() / RAND_MAX * R_MAX_NUM;
    }
}

void refill(double *arr, int place, double data){
    if(arr == NULL){
        printf("Ошибка передачи данных в refill");
    }
    arr[place] = data; 
}

void manual_fill(double *arr, int size){
    int check = 0;
    double data = 0.0;
    for (int i = 0; i < size; i++) {
        do{
            printf("Введите %d-ый элемент массива: ", i + 1);
            check = scanf("%lf", &data);
        }while(clear_input() != 0 || check != 1);
        arr[i] = data;
    }
}
/*
struct TypeInfo {
    size_t (*get_elem_size)();
};

typedef int (*predicat)(void*);

struct DynamicArray {
    void* data;
    struct TypeInfo* t;
    size_t size;
    size_t capacity;
    struct DynamicArray * (*where) (const struct DynamicArray * this, predicat p);
};

struct DynamicArray * _where(const struct DynamicArray * this, predicat p) {
    return this->where(this, p);
}

struct TypeInfoDouble
{
    struct TypeInfo base;
};


static get_double_size() {
    return sizeof(double);
}

static get_func_size() {
    return sizeof(void*);
}

static struct TypeInfoDouble _double_type = {
    .base = (struct TypeInfo){ .get_elem_size = get_double_size }
};

static struct TypeInfo _func_type = {
    .get_elem_size = get_func_size
};

struct DynamicArray* create_double_array(size_t initial_size) {
    struct DynamicArray* d = malloc(sizeof(struct DynamicArray));
    d->t = (struct TypeInfo*)&_double_type;
    d->data = malloc(initial_size * d->t->get_elem_size());
    d->size = initial_size;
    d->capacity = initial_size;
}

struct DynamicArray* create_func_array(size_t initial_size) {
    struct DynamicArray* d = malloc(sizeof(struct DynamicArray));
    d->t = (struct TypeInfo*)&_func_type;
    d->data = malloc(initial_size * d->t->get_elem_size());
    d->size = initial_size;
    d->capacity = initial_size;
}
*/

int main() {

    /*
    struct DynamicArray* d = create_double_array(10);
    struct DynamicArray* p = create_func_array(10);

    _where(d, (predicat)is_value_between_2_and_7);
    _where(p, (predicat)is_commutative);
    */
    srand(time(NULL));
    const int map_funcs_ammount = 2, where_funcs_ammount = 2;
    size_t size = 0, new_size = 0, place = 0, div_flag = 0;
    int check = 0, choice = 0, operations_ammount = 0, temp_for_where;
    double data = 0;
    double (**map_funcs)(double, double) = malloc(map_funcs_ammount * sizeof(double(*) (double, double))); //указатель на массив указателей
    int (**where_funcs)(double, double, int) = malloc(where_funcs_ammount * sizeof(int(*) (double, double, int))); //указатель на массив указателей
    void* temp_clear = NULL;
    if(map_funcs == NULL || where_funcs == NULL){
        printf("Ошибка выделения памяти под массивы указателей");
        free(map_funcs);
        free(where_funcs);
        return 0;
    }

    map_funcs[0] = &summation; //указатель на кнкретную функцию  
    map_funcs[1] = &multiplication;

    where_funcs[0] = &divider;
    where_funcs[1] = &bounds;

    // конец начальных настроек-------------------------------------------------------------------------------------------------------------------------
    do{
        clear_screen();
        printf("Введите желаемый размер массива: ");
        check = scanf("%lld", &size);
    }while(clear_input() != 0 || check != 1);

    double* arr = malloc(size * sizeof(double));
    if(arr == NULL){
        printf("Ошибка выделения памяти под массив чисел");
        free(map_funcs);
        free(where_funcs);
    }
    for(size_t i = 0; i < size; i++){ //!!!добавить обнуление массива в катину лабу
        arr[i] = 0;
    }

    while(choice != 5){ //начальная работа с массивом
        do{
            fill_array_text(arr, size);
            check = scanf("%d", &choice);
            if(choice < 1 || choice > 5){
                clear_screen();
                printf("Такого варианта не существует, введите заново\n");
            }
        }while(clear_input() != 0 || check != 1 || (choice < 1 || choice > 5));
        clear_screen();
        switch(choice){
            case 1:
                auto_fill(arr, size);
                break;
            case 2:
                manual_fill(arr, size);
                break;
            case 3:
                do{
                    printf("Введите новый желаемый размер массива: ");
                    check = scanf("%lld", &new_size);
                    if(new_size < 1 || new_size > MAX_SIZE){
                        clear_screen();
                        printf("Это невозможно, попробуйте еще раз.\n");
                    }
                }while(clear_input() != 0 || check != 1 || (new_size < 1 || new_size > MAX_SIZE));

                double* temp = realloc(arr, new_size * sizeof(double));
                if (temp == NULL) {
                    printf("Ошибка выделения памяти.");
                    clear_input();
                    break;
                }
                arr = temp;
                if (new_size > size) {
                    for (size_t i = size; i < new_size; i++) {
                        arr[i] = 0;
                    }
                }

                size = new_size;
                break;
            case 4:
                do{
                    printf("Какой индекс хотите заменить?\n >");
                    check = scanf("%lld", &place);
                    if(place < 1 || place >= size){
                        clear_screen();
                        printf("Это невозможно, попробуйте еще раз.\n");
                    }
                }while(clear_input() != 0 || check != 1 || (place < 1 || place > MAX_SIZE));

                do{
                    printf("На что вы хотите его заменить?\n >");
                    check = scanf("%lf", &data);
                }while(clear_input() != 0 || check != 1);
                refill(arr, place, data);
            default:

        }
    }
    
    while(choice != 9){ //map_where функции
        do{
            map_where_text(arr, size);
            check = scanf("%d", &choice);
            if(choice < 1 || choice > 7){
                clear_screen();
                printf("Такого варианта не существует, введите заново\n");
            }
        }while(clear_input() != 0 || check != 1 || (choice < 1 || choice > 10));
        clear_screen();

        if(choice < 3){ // map part
            do{
                printf("Укажите необходимое число для операции\n >");
                check = scanf("%lf", &data);
            }while(clear_input() != 0 || check != 1);
            map(map_funcs[choice - 1], arr, size, data);
        }
        else if(choice < 7){ //where part
            div_flag = (choice > 4);
            do{
                printf("Укажите необходимое число для операции\n >");
                check = scanf("%lf", &data);
            }while(clear_input() != 0 || check != 1 || (div_flag == 0 && data < 0));
            temp_clear = arr;
            arr = where(where_funcs[div_flag], arr, &size, data, choice % 2);
            free(temp_clear);
        }
        else if(choice < 9){ // concat part
            do{
                printf("Укажите количество операции\n >");
                check = scanf("%d", &operations_ammount);
            }while(clear_input() != 0 || check != 1 || operations_ammount < 1);
            int* arr_of_operations = malloc(operations_ammount * sizeof(int));
            double* data_for_concat = malloc(operations_ammount * sizeof(double));
            int* conditions = malloc(operations_ammount * sizeof(int));
            for(int i = 0; i < operations_ammount; i++){
                if(choice == 6){
                    do{
                        map_concat_text();
                        printf("Укажите номер нужной операции\n >");
                        check = scanf("%d", &arr_of_operations[i]);
                        arr_of_operations[i]--;
                    }while(clear_input() != 0 || check != 1 || arr_of_operations[i] < 0 || arr_of_operations[i] >= map_funcs_ammount);
                }
                else{
                    do{
                        where_concat_text();
                        printf("Укажите номер нужной операции\n >");
                        check = scanf("%d", &temp_for_where);
                        temp_for_where--;
                    }while(clear_input() != 0 || check != 1 || temp_for_where < 0 || temp_for_where >= 2 * where_funcs_ammount);
                    arr_of_operations[i] = temp_for_where / 2;
                    conditions[i] = temp_for_where % 2;
                    
                }
                do{
                    printf("Укажите необходимое число для операции\n >");
                    check = scanf("%lf", &data_for_concat[i]);
                }while(clear_input() != 0 || check != 1);
            }
            if(choice == 6){
                map_concat(map_funcs, arr, size, data_for_concat, arr_of_operations, operations_ammount);
            }
            else{
                temp_clear = arr;
                arr = where_concat(where_funcs, arr, &size, data_for_concat, conditions, operations_ammount, arr_of_operations);
                free(temp_clear);
            }
            free(arr_of_operations);
            free(data_for_concat);
            free(conditions);
        }
    }
    if(arr != NULL){
        free(arr);
    }
    free(map_funcs);
    free(where_funcs);

    
    return 0;
}