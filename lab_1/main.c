#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "sys_funcs.h"
#include "text_blocks.h"
#include "support_funcs.h"
#define MAX_SIZE 100000
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
#define safe_rand(a) ((a) = 0 ? 1 : (a))

void auto_fill(double *arr, int size){
    for (int i = 0; i < size; i++) {
        arr[i] = (double)(rand()) / 1000;
    }
}

void refill(double *arr, int place, double data){
    if(arr == NULL){
        printf("Ошибка передачи данных в refill");
    }
    arr[place] = data; 
}
/*
void auto_fill(double *arr, int size){
    for (int i = 0; i < size; i++) {
        arr[i] = (double)(rand()) / 1000;
    }
}
*/


int main() {
    srand(time(NULL));
    const int map_funcs_ammount = 2, where_funcs_ammount = 2;
    int size = 0, check = 0, chose = 0, new_size = 0, place = 0;
    double data = 0;
    void (**map_funcs)(double*, double) = malloc(map_funcs_ammount * sizeof(void(*) (double*, double))); //указатель на массив указателей
    void (**where_funcs)(double*, double) = malloc(where_funcs_ammount * sizeof(void(*) (double*, double))); //указатель на массив указателей

    map_funcs[0] = &summation; //указатель на кнкретную функцию
    map_funcs[1] = &multiplication;
    do{
        clear_screen();
        printf("Введите желаемый размер массива: ");
        check = scanf("%d", &size);
    }while(clear_input() != 0 || check != 1);

    double* arr = malloc(size * sizeof(double));
    for(int i = size; i < size; i++){
        arr[i] = 0;
    }

    while(chose != 5){
        do{
            fill_array_text(arr, size);
            check = scanf("%d", &chose);            
            clear_input();
            if(chose < 1 || chose > 5){
                clear_screen();
                printf("Такого варианта не существует, введите заново\n");
            }
        }while(check != 1 || (chose < 1 || chose > 5));
        clear_screen();
        switch(chose){
            case 1:
                auto_fill(arr, size);
                break;
            case 2:
                //manual_fill();
                break;
            case 3:
                do{
                    printf("Введите новый желаемый размер массива: ");
                    check = scanf("%d", &new_size);            
                    clear_input();
                    if(new_size < 1 || new_size > MAX_SIZE){
                        clear_screen();
                        printf("Это невозможно, попробуйте еще раз.\n");
                    }
                }while(check != 1 || (new_size < 1 || new_size > MAX_SIZE));

                double* temp = realloc(arr, new_size * sizeof(double));
                if (temp == NULL) {
                    printf("Ошибка выделения памяти.");
                    clear_input();
                    break;
                }
                arr = temp;
                if (new_size > size) {
                    for (int i = size; i < new_size; i++) {
                        arr[i] = 0;
                    }
                }

                size = new_size;
                break;
            case 4:
                do{
                    printf("Какой индекс хотите заменить?\n >");
                    check = scanf("%d", &place);            
                    clear_input();
                    if(place < 1 || place >= size){
                        clear_screen();
                        printf("Это невозможно, попробуйте еще раз.\n");
                    }
                }while(check != 1 || (place < 1 || place > MAX_SIZE));

                do{
                    printf("На что вы хотите его заменить?\n >");
                    check = scanf("%lf", &data);            
                    clear_input();
                }while(check != 1);
                refill(arr, place, data);
            default:

        }
    }
    printf("%d\n", check);
    map(map_funcs[0], arr, 3);
    for(int i = 0; i < size; i++){
        printf("%f\n", arr[i]);
    }
    free(arr);
    free(map_funcs);
    free(where_funcs);

    
    return 0;
}