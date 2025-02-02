#include <stdio.h>

void merge(int arr[], int left, int mid, int right){
    int n1 = mid - left + 1; //左子树的大小
    int n2 = right - mid; //右子树的大小

    //创建临时数组
    int L[n1],R[n2];

    //将数据复制到临时数组
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[mid + 1 + j];
    }
    //合并临时数组到原数组
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    //如果左子树组还有剩余
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    //如果右子树组还有剩余
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    
}

//归并排序函数
void mergeSort(int arr[], int left, int right){
    if (left < right)
    {
        //计算中间位置
        int mid = left + (right - left) / 2;
        //递归排序左半部分
        mergeSort(arr,left,mid);
        //递归排序右半部分
        mergeSort(arr,mid + 1,right);
        //合并两个已排序的子数组
        merge(arr,left,mid,right);
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

    // 对数组进行归并排序
    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}