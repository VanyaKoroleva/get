#include<stdio.h>

struct Card {
    char rank;    // достоинство
    char suit;    // масть
};

int check(struct Card hand[]){
    char rank[] = "23456789TJQKA"; // достоинство
    unsigned int i, j, res = -1;
    int m[100] = {};
    for (i = 0; hand[i].rank != 0; i++) {
        for (j = 0; j < 13; j ++){
            if (hand[i].rank == rank[j]){
                m[j] ++;
                break;
            }
        }
    }
    for (i = 0; i < 13; i ++){
        if (m[i] == 3){
            if (res != -1){
                return -1;
            }
            res = i;
        }
    }
    return res;
}

int main(){
    struct Card hand [] = {{'Q', 's'}, {'A','h'}, {'9', 'd'}, {0, 0}};
    int i;
    // напечатает QsAh9d
    for (i=0; hand[i].rank != 0; i++) {
        printf("%c%c", hand[i].rank, hand[i].suit);
    }
    printf("\n");
    // проверяем
    printf("%d\n", check(hand));

    return 0;
}