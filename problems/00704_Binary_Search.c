// 26% faster
int search(int* nums, int numsSize, int target){
    int l = 0;
    int r = numsSize - 1;
    while (l <= r) { // must be <= for l=r case
        int mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

void test_704_Binary_Search(void)
{
    int nums_1[] = {-1,0,3,5,9,12};
    int nums_2[] = {-1,0,3,5,9,12};
    int nums_3[] = {5};
    printf("%d\n", search(nums_1, 6, 9)); // 4
    printf("%d\n", search(nums_2, 6, 2)); // -1
    printf("%d\n", search(nums_3, 1, 5)); // 0
    printf("%d\n", search(nums_3, 1, 0)); // -1
}
