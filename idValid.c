#include<stdbool.h>
#include<stdio.h>
#include<string.h>


bool isValid(char* s) {
    char tempList[];
    // char** ptrTempList = &tempList;
   //  printf("%p %p %p", tempList, ptrTempList, *ptrTempList);
    int k = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            tempList[k] = s[i];
            k++;
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if (!k)return false;
            if (s[i] == ')' && tempList[k - 1] == '(')
                k--;
            else if (s[i] == ']' && tempList[k - 1] == '[')
                k--;
            else if (s[i] == '}' && tempList[k - 1] == '{')
                k--;
            else return false;

        }

    }
    if (!k) return true;
    else return false;

}

int main() {
    char* s = "(]";
    if (isValid(s)) printf("is valid");
    else printf("not valid");
}