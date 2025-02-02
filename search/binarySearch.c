//二分查找要求数组是有序的（从小到大或者从大到小都行）
//基本就是每次计算中间的索引，如果大了就找右半部分（更新左索引），小了相反
#include <stdio.h>

int binarySearch(int arr[], int size, int target)
{
    int left = 0, right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2; // 防止整数溢出

        if (arr[mid] == target)
        {
            return mid; // 找到目标值，返回索引
        }
        else if (arr[mid] < target)
        {
            left = mid + 1; // 缩小到右半部分
        }
        else
        {
            right = mid - 1; // 缩小到左半部分
        }
    }

    return -1; // 未找到目标值
}

int main()
{
    int arr[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;

    int result = binarySearch(arr, size, target);

    if (result != -1)
    {
        printf("目标值 %d 的索引是: %d\n", target, result);
    }
    else
    {
        printf("未找到目标值 %d\n", target);
    }

    return 0;
}
