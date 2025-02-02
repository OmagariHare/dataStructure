#include <stdio.h>

void selectionSort(int arr[], int n){
    int i,j, minIndex, temp;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i; //假设当前元素是最小的
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j; //找到最小元素的索引
            }
        }
        
        //交换当前位置元素和找到的最小元素
        if (minIndex != i)
        {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
        
    }
    
}

void printArray(int arr[],int n){
    for (int  i = 0; i < n; i++)
    {
        printf("%d",arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {6,3,9,2,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("排序前：");
    printArray(arr,n);

    selectionSort(arr,n);
    printf("排序后");
    printArray(arr,n);
}