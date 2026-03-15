#ifndef WHERE_FUNCS_H
#define WHERE_FUNCS_H

int is_value_positive(void* value);
int is_value_negative(void* value);
int is_value_between_0_and_10(void* value);
int is_value_even(void* value);
int is_commutative(void* elem_ptr);
int is_reflexive(void* elem_ptr);
int is_irreflexive(void* elem_ptr);
#endif