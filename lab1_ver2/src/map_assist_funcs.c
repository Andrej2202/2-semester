#include <float.h>
#include <map_assist_funcs.h>

double summation(double num, double addit) {
    if(num > 0 && addit > 0 && num >= DBL_MAX - addit){
        return DBL_MAX;
    }
    if(num < 0 && addit < 0 && num < -DBL_MAX - addit){
        return -DBL_MAX;
    }
    return num + addit;
}


double multiplication(double num, double addit) {
    if((num > 1 && addit > 1) && num > DBL_MAX / addit){
        return DBL_MAX;
    }
    if((num < -1 && addit < -1) && -1 * num > DBL_MAX / (-1 * addit)){
        return DBL_MAX;
    }
    if(num < -1 && addit > 1 && -1 * num > DBL_MAX / addit){
        return -DBL_MAX;
    }
    if((num > 1 && addit < -1) &&  num > DBL_MAX / (-1 * addit)){
        return -DBL_MAX;
    }
    return num * addit;
}