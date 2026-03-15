int divide(double num, double numer){
    if((int)numer == 0){
        return 0;
    }
    return ((int)num % (int)numer == 0);
}

int not_divide(double num, double numer){
    if((int)numer == 0){
        return 0;
    }
    return ((int)num % (int)numer != 0);
}

int upper_bound(double num, double bound){
    return num <= bound;
}

int lower_bound(double num, double bound){
    return num >= bound;
}

int equal(double num, double bound){
    return num == bound;
}