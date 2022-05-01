// binary search
// Runtime: 18 ms, faster than 15.90% of C online submissions for Peak Index in a Mountain Array.
// Memory Usage: 6.6 MB, less than 37.24% of C online submissions for Peak Index in a Mountain Array.
int peakIndexInMountainArray(int* arr, int arrSize){
    int left = 0;
    int right = arrSize - 1;
    while (left <= right) {
        if (left == right) return left;
        if (right - left == 1) {
            if (arr[left] > arr[right]) return left;
            else return right;
        }

        int mid = (left + right) / 2;
        int val_mid = arr[mid];

        if ((val_mid > arr[mid -1]) && (val_mid > arr[mid+1])) {
            return mid;
        } else if (val_mid > arr[mid-1]) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

// binary search with code optimization
// Runtime: 6 ms, faster than 97.07% of C online submissions for Peak Index in a Mountain Array.
// Memory Usage: 6.5 MB, less than 56.07% of C online submissions for Peak Index in a Mountain Array.
int peakIndexInMountainArray(int* arr, int arrSize){
    int left = 0;
    int right = arrSize - 1;
    while (left <= right) {
        //if (left == right) return left;
        if (right - left == 1) {
            if (arr[left] > arr[right]) return left;
            else return right;
        }

        int mid = (left + right) / 2;
        int val_mid = arr[mid];

        if ((val_mid > arr[mid -1]) && (val_mid > arr[mid+1])) {
            return mid;
        } else if (val_mid > arr[mid-1]) {
            left = mid+1;
        } else {
            right = mid-1;
        }
    }
    return -1;
}

// https://leetcode.com/problems/peak-index-in-a-mountain-array/solution/
// Runtime: 8 ms, faster than 90.79% of C online submissions for Peak Index in a Mountain Array.
// Memory Usage: 6.3 MB, less than 99.16% of C online submissions for Peak Index in a Mountain Array.
int peakIndexInMountainArray(int* arr, int arrSize){
    int left = 0;
    int right = arrSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        int val_mid = arr[mid];

        if ((val_mid < arr[mid+1])) {
            left = mid+1;
        } else {
            right = mid;
        }
    }
    return left;
}