//就是很普通的，遍历检查整个数组，如果相等就找到了，很ez
#include <stdio.h>

int linearSearch(int arr[],int size, int target){
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
        
    }
    return -1;
}

int main(){
    int arr[] = {4,2,7,1,8,5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 7;
    int result = linearSearch(arr, size, target);

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