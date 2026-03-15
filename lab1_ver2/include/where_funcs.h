#ifndef WHERE_FUNCS_H
#define WHERE_FUNCS_H

//where часть
int divider(double num, double numer, int cond);
int bounds(double num, double bound, int cond);
int lower_bound(double num, double bound);
int base_bound(double num, double bound);
int is_value_between_2_and_7(void* value);
 int is_commutative(void* elem_ptr);
#endif