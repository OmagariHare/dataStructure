#include <stdio.h>
#include <stdlib.h>

int arr[5] = {1,2,5,4}; // 1,2,'3',->4,5

void insert(int *nums,int size,int num,int index){
    for (int i = size - 1; i > index; i--)
    {
        nums[i] = nums[i - 1];
    }
    nums[index] = num;
}