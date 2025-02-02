// 将数据按照一定的规则分配到多个桶中，分别对每个桶内的数据进行排序，
// 最后将各个桶中的数据依次合并
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n){
    //创建n个桶
    int bucketCount = n;
    float buckets[n][n]; //假设每个桶最多存n个元素
    int bucketSizes[n];  //记录每个桶中元素的个数

    //初始化每个桶的大小为0
    for (int i = 0; i < bucketCount; i++)
    {
        bucketSizes[i] = 0;
    }
    // 1.将元素分配到对应的桶中
    for (int i = 0; i < n; i++)
    {
        int bucketIndex = (int)(arr[i] * bucketCount);
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }
    // 2.对每个桶内部进行排序（使用插入排序）
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 1; j < bucketSizes[i]; j++)
        {
            float temp = buckets[i][j];
            int k = j - 1;
            while (k >= 0 && buckets[i][k] > temp)
            {
                buckets[i][k + 1] = buckets[i][k];
                k--;
            }
            buckets[i][k + 1] = temp;
        }
    }
    // 3. 合并所有桶中的元素
    int index = 0;
    for (int i = 0; i < bucketCount; i++)
    {
        for (int j = 0; j < bucketSizes[i]; j++)
        {
            arr[index++] = buckets[i][j];
        }
    }
}

int main()
{
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%.2f ", arr[i]);
    }
    return 0;
}