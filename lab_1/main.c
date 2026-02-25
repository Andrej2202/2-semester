#include <stdio.h>
#include <stdlib.h>


int summation(int num, int addit) {
    return num + addit;
}


int multiplication(int num, int mult) {
    return num * mult;
}


int main() {
    const int funcs_ammount = 2;
    int index = 0;
    int (**f)(int, int) = malloc(funcs_ammount * sizeof(int (*)(int, int)));
    f[0] = &summation;
    f[1] = &multiplication;
    
    int result = f[index](10, 10);
    printf("%d", result);
    free(f);
    
    return 0;
}