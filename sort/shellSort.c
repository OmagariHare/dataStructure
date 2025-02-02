//分组：讲整个数组按照gap分组，对每一组进行插入排序，然后逐步减小gap，重复上述过程直到gap=1

#include <stdio.h>

// 希尔排序函数
void shellSort(int arr[], int n)
{
    // 初始步长设定为数组长度的一半
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // 对每组元素进行插入排序
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i]; // 保存当前元素
            int j;

            // 插入排序逻辑
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap]; // 将较大的元素向后移动
            }

            arr[j] = temp; // 将当前元素插入到正确位置
        }
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
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
