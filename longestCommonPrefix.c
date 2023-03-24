#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* longestCommonPrefix(char** strs, int strsSize) {
    if (!strsSize) return "";
    if (strsSize == 1) return strs[0];

    int min = 100;
    int c = 0;
    for (int i = 0;i < strsSize;i++) {

        c = strlen(strs[i]);
        if (c < min) min = c;
    }
    if (min == 0) return "";

    //  char* common_pref = malloc(sizeof(char) *( min+1));
   //   common_pref[0] = '\0';
    int count = 0, j = 0;
    while (j < min) {
        for (int i = 0;i < strsSize - 1;i++) {

            if (strs[i][j] == strs[i + 1][j]) // comparing corresponding vertical elements
                count++;                           // for each true value count is incremented
            else break;
        }

        if (count == (j + 1) * (strsSize - 1))          // checking if count was incremented for all comparisons
            j++;
        else break;
    }


    strs[0][j] = '\0';
    return strs[0];



}

int main() {
    char* strs[2] = { "ab","a" };
    char* a = longestCommonPrefix(strs, 2);
    printf("%c\n", *a);
}