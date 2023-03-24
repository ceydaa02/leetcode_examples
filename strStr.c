#include <stdio.h>
#include <string.h>
int strStr(char* haystack, char* needle) {
    if (needle == NULL) return 0;
    //int k = 0;
    int a = strlen(haystack);
    for (int i = 0, k = 0; i < strlen(haystack);i++) {
        int j = i;
        if (haystack[i] == needle[k]) {
            while (haystack[i] == needle[k]) {
                k++;
                if (k == strlen(needle)) return i - k + 1;
                i++;
            }
            i = j;
            k = 0;
        }
    }

    return -1;
}
int main() {

    char h[12] = "mississippi";
    char n[6] = "issip";
    int a = strStr(h, n);
    printf("%d", a);
    return 0;
}