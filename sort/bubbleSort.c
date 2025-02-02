#include <stdio.h>
void bubbleSort(int arr[],int n){
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            
        }
        
    }
    
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {6, 3, 9, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前：");
    printArray(arr, n);

    bubbleSort(arr, n);
    printf("排序后");
    printArray(arr, n);
}