// http://alrightchiu.github.io/SecondRound/comparison-sort-heap-sortdui-ji-pai-xu-fa.html
// version with insertion 0 at the beginnig of array
void swap_int(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void max_heapify_insertion(int *nums, int size, int idx_root)
{
    // locate indeces for left and right node
    int idx_l = idx_root * 2;
    int idx_r = idx_root * 2 + 1;
    int idx_largest;

    // find largest node in root, left, and right nodes
    if ((idx_l < size) && (nums[idx_l] > nums[idx_root]))  {
        idx_largest = idx_l;
    } else {
        idx_largest = idx_root;
    }

    if ((idx_r < size) && (nums[idx_r] > nums[idx_largest]))  {
        idx_largest = idx_r;
    }

    if (idx_largest != idx_root) {
        // only swap largest nodes when root is not largest node
        swap_int(&nums[idx_root], &nums[idx_largest]);
        // go down left or right node
        max_heapify_insertion(nums, size, idx_largest);
    }
}

void max_heap_build_insertion(int *nums, int size)
{
    // bottom up to build tree
    // index 0 is not used
    for (int i = size / 2; i >= 1; i--) {
        max_heapify_insertion(nums, size, i);
    }
}

void heap_sort_insertion(int *nums, int size)
{
    int size_x = size + 1;
    int *nums_x = (int *)malloc(sizeof(int) * size_x);

    // insert 0 at the beginning by memcpy
    memcpy(nums_x + 1, nums, size * sizeof(int));

    // build max heap
    max_heap_build_insertion(nums_x, size_x);

    for (int i = size_x - 1; i >= 2; i--) {
        // swap last node with node 1 (not 0)
        swap_int(&nums_x[i], &nums_x[1]);
        // do sort from node 0
        max_heapify_insertion(nums_x, i, 1);
    }

    // copy back
    memcpy(nums, nums_x + 1, size * sizeof(int));

    free(nums_x);
}

// https://zh.wikipedia.org/wiki/%E5%A0%86%E6%8E%92%E5%BA%8F
// version without insertion 0 at the beginnig of array
void max_heapify_no_insertion(int *nums, int size, int idx_root)
{
    // locate indeces for left and right node
    int idx_l = idx_root * 2 + 1;
    int idx_r = idx_root * 2 + 2;
    int idx_largest;

    // find largest node in root, left, and right nodes
    if ((idx_l < size) && (nums[idx_l] > nums[idx_root]))  {
        idx_largest = idx_l;
    } else {
        idx_largest = idx_root;
    }

    if ((idx_r < size) && (nums[idx_r] > nums[idx_largest]))  {
        idx_largest = idx_r;
    }

    if (idx_largest != idx_root) {
        // only swap largest nodes when root is not largest node
        swap_int(&nums[idx_root], &nums[idx_largest]);
        // go down left or right node
        max_heapify_no_insertion(nums, size, idx_largest);
    }
}

void max_heap_build_no_insertion(int *nums, int size)
{
    // bottom up to build tree
    for (int i = size / 2; i >= 0; i--) {
        max_heapify_no_insertion(nums, size, i);
    }
}

void heap_sort_no_insertion(int *nums, int size)
{
    // build max heap
    max_heap_build_no_insertion(nums, size);

    // index 0 is not needed to sort
    for (int i = size - 1; i >= 1; i--) {
        // swap last node with node 0
        swap_int(&nums[i], &nums[0]);
        // do sort from node 0
        max_heapify_no_insertion(nums, i, 0);
    }
}


void test_X0007_heap_sort(void)
{
    int nums_1[] = {1, 2, 3, 4, 5};
    heap_sort_insertion(nums_1, 5);
    print_int_array(nums_1, 5);

    heap_sort_no_insertion(nums_1, 5);
    print_int_array(nums_1, 5);

    int nums_2[] = {1, 2, 3, 4, 5, 6};
    heap_sort_no_insertion(nums_2, 6);
    print_int_array(nums_2, 6);
}