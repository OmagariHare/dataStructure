#include <stdio.h>

// 快速排序的分区函数，返回基准元素的索引
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // 选择最右侧的元素作为基准
    int i = low - 1;       // i 用于记录小于基准的元素的最后一个位置

    for (int j = low; j < high; j++)
    {
        // 如果当前元素小于基准
        if (arr[j] < pivot)
        {
            i++; // 增加 i 的位置
            // 交换 arr[i] 和 arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // 交换基准元素和 arr[i + 1]，使基准元素放到正确的位置
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1; // 返回基准元素的位置
}

// 快速排序函数
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // 获取分区位置
        int pi = partition(arr, low, high);

        // 对基准元素左侧的子数组进行递归排序
        quickSort(arr, low, pi - 1);

        // 对基准元素右侧的子数组进行递归排序
        quickSort(arr, pi + 1, high);
    }
}

// 打印数组的函数
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {6, 3, 9, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    // 对数组进行快速排序
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
