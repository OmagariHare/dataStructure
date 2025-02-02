#include <stdio.h>

#define MAX_SIZE 100

//堆的下称操作
void heapify(int arr[], int n, int i){
    int largest = i; //假设当前节点是最大值
    int left = 2 * i + 1; //左子节点
    int right = 2 * i + 2; //右子节点

    //如果左子节点比根节点大
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    //如果右子节点比当前最大节点还大
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    //如果最大值发生变化，交换并递归调整堆
    if (largest != i)
    {
        //交换arr[i]和arr[largest]
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        //递归地调整被交换的子树
        heapify(arr,n,largest);
    }
    
}

//堆排序主函数
void heapSort(int arr[],int n){
    //建堆
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr,n,i);
    }
    //排序
    for (int i = n - 1; i >=1 ; i--)
    {
        // 将堆顶元素（最大值）与最后一个元素交换
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 调整剩余堆
        heapify(arr, i, 0);
    }
}

// 打印数组
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
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("原始数组：\n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("排序后的数组：\n");
    printArray(arr, n);

    return 0;
}