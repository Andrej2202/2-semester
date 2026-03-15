#include <where_funcs.h>



int divider(double num, double numer, int cond){
    if((int)numer == 0){
        return 0;
    }
    return ((int)num % (int)numer == 0) == cond;
}

int upper_bound(double num, double bound){ // cond = 0 - верх cond = 1 - низ
    return num <= bound;
}

int lower_bound(double num, double bound){ // cond = 0 - верх cond = 1 - низ
    return num >= bound;
}

int base_bound(double num, double bound){
    return num == bound;
}

int is_value_between_2_and_7(void* value){
    return lower_bound(*(double*)value, 2.0) && upper_bound(*(double*)value, 7.0);
}

 int is_commutative(void* elem_ptr) {
    int (*func)(double, double) = *(int (**)(double, double))elem_ptr;

    
    return (
        (func(1, 2) == func(2,1)) &&
        (func(1, 5) == func(5,1)) &&
        (func(1, 0) == func(0,1)) 
    );
 }