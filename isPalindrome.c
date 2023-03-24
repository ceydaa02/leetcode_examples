#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) return false;
    if (x == 0) return true;
    int original = x;
    int reminder, reversed = 0;
    while (x != 0) {
        reminder = x % 10;
        reversed = reversed * 10 + reminder;
        x /= 10;
    }
    if (reversed == original) return true;
    else return false;
}