// stack overflow version
int brokenCalc(int startValue, int target){
    int val_max = startValue * 2;
    int val_min = (startValue - 1) * 2;
    if (target == startValue) return 0;
    if (target == val_min) return 2;
    if (target == val_max) return 1;
    if (target > val_max) {
        if (target & 1) {
            return 2 + brokenCalc(startValue, (target + 1) / 2);
        } else {
            return 1 + brokenCalc(startValue, target / 2);
        }
    }
    if (target < val_min) {
        return 1 + brokenCalc(startValue - 1, target);
    }
    return 2;
}

// TLE version
int brokenCalc(int startValue, int target){
    int result = 0;
    while (1) {
        int val_max = startValue * 2;
        int val_min = (startValue - 1) * 2;
        if (target == startValue) { return result; }
        if (target == val_min) { return result + 2; }
        if (target == val_max) { return result + 1; }
        if (target > val_max) {
            if (target & 1) {
                // for odd target, the shortest step number is from (target + 1) / 2, 2 steps
                result += 2;
                target = (target + 1) / 2;
            } else {
                // for even target, the shortest step number is from (target) / 2, 1 steps
                result += 1;
                target = target / 2;
            }
            continue;
        }
        // taregt is smaller
        if (target < val_min) {
            result += 1;
            startValue -= 1;
            continue;
        }
        return result += 2;
    }
    return result;
}

// https://leetcode.com/problems/broken-calculator/solution/
int brokenCalc(int startValue, int target){
    int result = 0;
    while (target > startValue) {
        if (target & 1) {
            // for odd target, the shortest step number is from (target + 1) / 2, 2 steps
            result += 2;
            target = (target + 1) / 2;
        } else {
            // for even target, the shortest step number is from (target) / 2, 1 steps
            result += 1;
            target = target / 2;
        }
    }
    // here target will be smaller than startValue, it needs x steps to reach from startValue
    return result + startValue - target;
}

void test_00991_Broken_Calculator(void)
{

    printf("%d\n", brokenCalc(5, 101));
    printf("%d\n", brokenCalc(2, 3));
    printf("%d\n", brokenCalc(5, 8));
    printf("%d\n", brokenCalc(3, 10));
    printf("%d\n", brokenCalc(5, 7));
    printf("%d\n", brokenCalc(1, 1));
    printf("%d\n", brokenCalc(1, 1000000000));
}
