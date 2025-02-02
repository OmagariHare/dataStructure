/*堆的定义
完全二叉树
堆是一棵完全二叉树（complete binary tree）。这意味着所有层的节点都是满的，只有最后一层可能不是满的，但从左到右是连续填充的。

堆性质（Heap Property）
    堆分为两种类型：
        大顶堆（Max Heap）： 每个节点的值都不小于其子节点的值。
        小顶堆（Min Heap）： 每个节点的值都不大于其子节点的值。
*/
#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int size;
} Heap;

//初始化堆
void initHeap(Heap *heap){
    heap -> size = 0;
}

//输入元素
void insert(Heap *heap,int value){
    int i = heap->size;
    heap->data[i] = value;
    heap->size++;
    //上浮操作
    while (i > 0)
    {
        int parent = (i-1) / 2;
        if (heap->data[i] > heap->data[parent])
        {
            //交换
            int temp = heap->data;
            heap->data[i] = heap->data[i];
            heap->data[parent] = temp;
        }else{
            break;
        }
        
    }
    
}

// 打印堆
void printHeap(Heap *heap)
{
    for (int i = 0; i < heap->size; i++)
    {
        printf("%d ", heap->data[i]);
    }
    printf("\n");
}

int main()
{
    Heap heap;
    initHeap(&heap);

    insert(&heap, 50);
    insert(&heap, 30);
    insert(&heap, 20);
    insert(&heap, 15);
    insert(&heap, 10);

    printHeap(&heap);
    return 0;
}