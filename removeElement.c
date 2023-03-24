#include<stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == val) {
            nums[i] = '\0';
            count--;

        }

    }       
    for (int k = 0; k < numsSize; k++) {
        if (nums[k] == '\0') {
            for (int j = k + 1; j < numsSize; j++) {
                if (nums[j] != '\0') {
                    int temp = nums[j];
                    nums[j] = '\0';
                    nums[k] = temp;
                    break;
                }
            }
        }
    }

    return numsSize + count;
}