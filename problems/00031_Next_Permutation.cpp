// https://leetcode.com/problems/next-permutation/solution/
void reverse(int *nums, int numsSize, int start)
{
    int end = numsSize - 1;
    while (start < end) {
        // swap start and end
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        start++;
        end--;
    }
}
void nextPermutation(int* nums, int numsSize){
    int target = -1;
    for (int i = numsSize - 2; i >= 0; i--) {
        if (nums[i] >= nums[i+1]) {
            // no action
        } else {
            target = i;
            break;
        }
    }

    if (target >= 0) {
        for (int i = numsSize - 1; i > target; i--) {
            if (nums[i] > nums[target]) {
                // swap i and target
                int tmp = nums[i];
                nums[i] = nums[target];
                nums[target] = tmp;
                break;
            }
        }
    } else {
        // target = -1 means the nums are descending like [3, 2, 1]
        // we need to reverse whole array
    }
    reverse(nums, numsSize, target + 1);
}

void print_int_array(int *arr, int size)
{
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }
    printf("]\n");
}

void test_00031_Next_Permutation(void)
{
    int nums_1[] = {3, 2, 1};
    for (int i = 0; i < 10; i++) {
        nextPermutation(nums_1, sizeof(nums_1)/sizeof(int));
        print_int_array(nums_1, sizeof(nums_1)/sizeof(int));
    }

    int nums_2[] = {1, 1, 5};
    for (int i = 0; i < 10; i++) {
        nextPermutation(nums_2, sizeof(nums_2)/sizeof(int));
        print_int_array(nums_2, sizeof(nums_2)/sizeof(int));
    }

}