#include <stdio.h>

#define MAX_SIZE 10
//定义队列
typedef struct {
    int data[MAX_SIZE];
    int front; //头索引
    int rear;  //尾索引
} Queue;

//初始化队列
void initQueue(Queue *q){
    q->front = 0;
    q->rear = 0;
}

//判断队列是否为空
int isEmpty(Queue *q){
    return q->front == q->rear;
}

//判断队列是否已满
int isFull(Queue *q){
    return (q->rear + 1)% MAX_SIZE == q->front;
}

//入队
int enqueue(Queue *q,int value){
    if (isFull(q))
    {
        printf("Full Queue!\n");
        return 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = value;
    return 1;
}

//出队
int dequeue(Queue *q, int *value){
    if (isEmpty(q))
    {
        printf("NULL Queue!\n");
        return 0;
    }
    q->front = (q->front + 1) % MAX_SIZE;
    *value = q->data[q->front];
    return 1;       
}

int main() {
    Queue q = {{0}, 0, 0};  // 初始化队列
    int value;

    // 入队操作
    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    // 尝试插入超出容量的元素
    enqueue(&q, 50);

    // 出队操作
    if (dequeue(&q, &value)) {
        printf("出队元素：%d\n", value);
    }
    if (dequeue(&q, &value)) {
        printf("出队元素：%d\n", value);
    }

    // 再次入队
    enqueue(&q, 50);
    enqueue(&q, 60);

    // 遍历队列
    printf("队列状态：");
    int i = (q.front + 1) % MAX_SIZE;
    while (i != (q.rear + 1) % MAX_SIZE) {
        printf("%d ", q.data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");

    return 0;
}
