void sort2(int * a, int * b){
    int max = (*a > *b) ? *a : *b;
    int min = (*a < *b) ? *a : *b;
    *b = max;
    *a = min;
}

void sort3(int * x, int * y, int * z){
    sort2(x, y);
    sort2(y, z);
    sort2(x, y);
}
