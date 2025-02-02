#include <stdio.h>
#include <stdlib.h>

// 获取最大值的函数
int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

// 按位排序（计数排序实现）
void countSort(int arr[], int n, int exp)
{
    int output[n];       // 临时数组存储排序结果
    int count[10] = {0}; // 计数数组，处理0~9这10个数字

    // 统计当前位的出现频率
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // 计算前缀和，确定当前位的数字在结果数组中的范围
    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // 倒序遍历原数组，确保排序的稳定性
    for (int i = n - 1; i >= 0; i--)
    {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 将结果拷贝回原数组
    for (int i = 0; i < n; i++)
    {
        arr[i] = output[i];
    }
}

// 基数排序
void radixSort(int arr[], int n)
{
    // 找到最大值，确定要排序的位数
    int max = getMax(arr, n);

    // 从个位到最高位逐位排序
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
    }
}

// 测试代码
int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    radixSort(arr, n);

    printf("排序后数组: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
