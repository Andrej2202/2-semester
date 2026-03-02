#include <stdio.h>
#include <stdlib.h>
#include "text_blocks.h"

void fill_array_text(double* arr, int n){
    printf("Массив:\n[");
    for(int i = 0; i < n; i++){
        printf("%.3f", arr[i]);
        if(i != n-1){printf(", ");}
    }
    printf("]\n\nМеню выбора действия\n");
    printf("  [1] Заполнить массив автоматически\n");
    printf("  [2] Заполнить массив вручную\n");
    printf("  [3] Изменить размер массива\n");
    printf("  [4] Изменить конкретный эллемент массива\n");
    printf("  [5] Перейти к работой с функциями\n");
    printf("  > ");
}