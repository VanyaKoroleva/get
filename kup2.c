#include<stdio.h>
    
int delim(int a[], int i, int j){
    return (a[i] + a[j]) % 2;
}

int all_equal(int a[], int n){
    int i = 0;
    for (i = 0; i < n - 1; i ++){
        if (a[i] != a[i + 1])
            return 0;
    }
    return 1;
}

int make_all_happy(int a[], int n){
    int i = 0, k = 0, j;
    while(all_equal(a, n) == 0){
        for(i = 0; i < n; i++){
            j = (i + 1) % n;
            k += delim(a, i, j);
            a[i] = (a[i] + a[j]) / 2;
            a[j] = a[i];
        }
    }
    return k;
}
    // Дети делят конфеты, "лишние" конфеты возвращают

int main()
{
    int a[100];     // ребенок i имеет a[i] конфет
    int n;
    int i;          // всего детей

    scanf("%d", &n);                        // читаем входные данные
    for(i = 0; i < n; i++)
        scanf("%d", a+i);
    
    int schoolboy = make_all_happy(a, n);   // делим
    printf("%d %d\n", schoolboy, a[0]);     // печатаем ответ

    return 0;
}