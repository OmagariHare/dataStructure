//数据分成若干个块，每个块中的数据是有序的，但块与块之前不要求有序，
//通过块的索引表确定目标值的位置，在这个块中使用顺序查找（或者别的方法）
#include <stdio.h>

// 索引结构体
typedef struct
{
    int maxValue; // 当前块的最大值
    int start;    // 当前块的起始索引
    int end;      // 当前块的结束索引
} BlockIndex;

// 顺序查找函数（在块中查找）
int linearSearch(int arr[], int start, int end, int target)
{
    for (int i = start; i <= end; i++)
    {
        if (arr[i] == target)
        {
            return i; // 找到目标值，返回索引
        }
    }
    return -1; // 未找到目标值
}

// 分块查找函数
int blockSearch(int arr[], BlockIndex index[], int blockCount, int target)
{
    for (int i = 0; i < blockCount; i++)
    {
        if (target <= index[i].maxValue)
        { // 根据索引定位块
            return linearSearch(arr, index[i].start, index[i].end, target);
        }
    }
    return -1; // 未找到目标值
}

int main()
{
    // 数据和块信息
    int arr[] = {2, 4, 5, 8, 10, 14, 18, 21, 28, 30}; // 有序数组
    int size = sizeof(arr) / sizeof(arr[0]);

    // 创建索引表
    BlockIndex index[] = {
        {10, 0, 4}, // 第 1 块，最大值 10，索引范围 [0, 4]
        {21, 5, 7}, // 第 2 块，最大值 21，索引范围 [5, 7]
        {30, 8, 9}  // 第 3 块，最大值 30，索引范围 [8, 9]
    };

    int blockCount = sizeof(index) / sizeof(index[0]); // 块数目
    int target = 18;

    int result = blockSearch(arr, index, blockCount, target);

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
