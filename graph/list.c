#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// 定义链表节点
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// 添加节点到链表
Node *addNode(Node *head, int vertex)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = vertex;
    newNode->next = head;
    return newNode;
}

int main()
{
    int n = 3;                   // 顶点数量
    Node *adjList[MAX] = {NULL}; // 邻接表初始化为 NULL

    // 添加边 A-B 和 B-C
    adjList[0] = addNode(adjList[0], 1); // A -> B
    adjList[1] = addNode(adjList[1], 0); // B -> A
    adjList[1] = addNode(adjList[1], 2); // B -> C
    adjList[2] = addNode(adjList[2], 1); // C -> B

    // 打印邻接表
    printf("邻接表：\n");
    for (int i = 0; i < n; i++)
    {
        printf("%c: ", 'A' + i);
        Node *temp = adjList[i];
        while (temp)
        {
            printf("%c ", 'A' + temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    // 释放内存
    for (int i = 0; i < n; i++)
    {
        Node *temp = adjList[i];
        while (temp)
        {
            Node *toFree = temp;
            temp = temp->next;
            free(toFree);
        }
    }

    return 0;
}
