int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    shuffle(nums, numsSize);
   // returnSize = (int*)malloc(2 * sizeof(int));
    quickSort(nums, 0, numsSize-1);
    for (int i = 0; i < numsSize; i++) {
        int t = target - nums[i];
        int index = binary_search(nums, i, numsSize - 1, t);
        if (index != -1 && index != i) {
            if (i < index) {
                *returnSize = i;
                *(returnSize + 1) = index;
            }
            else {
                *returnSize = index;
                *(returnSize + 1) = i;
            }
            break;
        }
        else returnSize = (int*)NULL;
    }
    return returnSize;
}
int main() {
    int nums[] = { 3, 3 };
    int target = 6;
    int lenghtOfNums = sizeof(nums)/sizeof(nums[0]); 
    int returned[2];
    int* value = twoSum(nums, lenghtOfNums, target, &returned[0]);
    if (value!=NULL)
        printf("indices of the two numbers such that they add up to target: [%d, %d] ", returned[0], returned[1]);
    else printf("There are not such numbers.");
    return 0;
}