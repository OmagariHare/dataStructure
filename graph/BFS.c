#include <stdio.h>
#define MAX 100

int adjMatrix[MAX][MAX];
int visited[MAX];
int n;

typedef struct{
    int data[MAX];
    int front, rear;
}Queue;

void initQueue(Queue*q){
    q->front = 0;
    q->rear = 0;
}

int isEmpty(Queue* q){
    return q->front == q->rear;
}

void enqueue(Queue* q, int v){
    q->data[q->rear++] = v;
}

int dequeue(Queue* q){
    return q->data[q->front++];
}

//BFS函数
void BFS(int start){
    Queue q;
    initQueue(&q);

    enqueue(&q,start);
    visited[start] = 1;

    printf("BFS遍历顺序");
    while (!isEmpty(&q))
    {
        int v = dequeue(&q);
        printf("%c",'A'+v);

        //遍历所有邻接顶点
        for (int i = 0; i < n; i++)
        {
            if (adjMatrix[v][i] == 1 && !visited[i])
            {
                enqueue(&q,i);
                visited[i] = 1;
            }
            
        }
        
    }
    printf("\n");

}

int main(){
    n = 6;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
        
    }
    // 添加边 A-B, A-D, B-C, D-E, E-F, C-F
    adjMatrix[0][1] = adjMatrix[1][0] = 1; // A-B
    adjMatrix[0][3] = adjMatrix[3][0] = 1; // A-D
    adjMatrix[1][2] = adjMatrix[2][1] = 1; // B-C
    adjMatrix[3][4] = adjMatrix[4][3] = 1; // D-E
    adjMatrix[4][5] = adjMatrix[5][4] = 1; // E-F
    adjMatrix[2][5] = adjMatrix[5][2] = 1; // C-F

    // 初始化访问标记数组
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // 从顶点 A 开始 BFS
    BFS(0); // 从顶点 0（即 A）开始

    return 0;
}