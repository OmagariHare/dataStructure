#include <stdio.h>
#include <stdlib.h>

// 计数排序函数
void countingSort(int arr[], int n)
{
    // 找出数组中的最小值和最大值
    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }

    // 初始化计数数组
    int range = max - min + 1; // 值域范围
    int *count = (int *)calloc(range, sizeof(int));

    // 统计每个元素的出现次数
    for (int i = 0; i < n; i++)
    {
        count[arr[i] - min]++;
    }

    // 构造前缀和数组
    for (int i = 1; i < range; i++)
    {
        count[i] += count[i - 1];
    }

    // 创建输出数组
    int *output = (int *)malloc(n * sizeof(int));

    // 从原数组的末尾开始，将元素放入正确的位置
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    // 将排序结果拷贝回原数组
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }

    // 释放动态内存
    free(count);
    free(output);
}

// 测试函数
int main()
{
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}
