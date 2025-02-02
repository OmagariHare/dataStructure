#include <stdio.h>

void insertionSort(int arr[],int n){
    int i,key,j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        //插入key元素
        arr[j+1] = key;
    }
}

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

    printf("排序前：");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("排序后");
    printArray(arr, n);

    return 0;
}