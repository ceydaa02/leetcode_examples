#include<stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int k = 1;
    int j=1;


    for (int i = 1;i < numsSize; i++) {
        if (nums[i] != nums[i-j]) {
            k++;
            j = 1;

        }
        else {
            j ++;
            nums[i] = -1000;
        }
    }

    for (int k = 0; k < numsSize; k++) {
        if (nums[k] == -1000) {
            for (int j = k + 1; j < numsSize; j++) {
                if (nums[j] != -1000) {
                    int temp = nums[j];
                    nums[j] = -1000;
                    nums[k] = temp;
                    break;
                }
            }
        }
    }

    return k;
}
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) { return 0; }
    int count = 1;  // counts the number of unique elements
    int j = 0;      // counts the number of duplicates between unique elements

    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] != nums[i + 1]) {
            count++;
            nums[i + 1 - j] = nums[i + 1];
        }
        else j++;
    }
    return count;
}

int main() {

    int nums[10] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
    int k = removeDuplicates(nums, 10);
    printf("%d\n", k);
    for (int i = 0; i < 10; i++) {
        printf("%d ", nums[i]);
    }
}