#include<stdio.h>
#define N 15

int romanToInt(char* s) {
    int number = 0;
    int ls = strlen(s);

    char romanNum[7] = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
    int value[8] = { 1000, 500, 100, 50, 10, 5, 1, 0 };

    for (int i = 0; i < ls; i++) {
        for (int k = 0; k < 7; k++) {
            if (s[i] == romanNum[k] && i + 1 == ls) {
                number += value[k];
                break;

            }
            else if (s[i] == romanNum[k] && k < 2) {
                number += value[k];
            }

            else if (s[i] == romanNum[k] && (s[i + 1] == romanNum[k - 1] || s[i + 1] == romanNum[k - 2])) {
                number -= value[k];
                break;
            }
            else if (s[i] == romanNum[k] && (s[i + 1] != romanNum[k - 1] || s[i + 1] != romanNum[k - 2])) {
                number += value[k];
                break;
            }

        }

    }
    return number;
}


int main() {
    char s[N];
    printf("Please, enter a roman numeral: ");
    scanf_s("%s", &s, sizeof(s));
    printf("%s converts as %d", s, romanToInt(s));
    return 0;
}