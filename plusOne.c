#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 4

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int valeur = 0;
    int power = 1;
    *returnSize = digitsSize;
    int* arr = (int*)malloc((*returnSize) * sizeof(int));

    if (arr == NULL) {
        puts("Yetersiz bellek alanı");
        exit(1);
    }
    for (int i = digitsSize - 1; i >= 0; i--) {
        valeur += digits[i] * power;
        power *= 10;
    }
    valeur++;

    for (int i = *returnSize - 1; i >= 0; i--) {
        arr[i] = valeur % 10;
        valeur /= 10;


    }
    if (!arr[1]) {
        (*returnSize)++;
        arr[0] = 1;
    }
 
    return arr;

}