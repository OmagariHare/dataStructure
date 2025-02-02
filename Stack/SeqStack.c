#include <stdio.h>
#include<stdlib.h>
typedef struct Stack{
    int *data;
    int top;
    int capacity;
} Stack;

//创建栈的函数
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("failed to allowcate mem!\n");
        return NULL;
    }
    stack->data = (int*)malloc(sizeof(int) * capacity);
    if (!stack->data) {
        printf("failed to allowcate mem!\n");
        free(stack);
        return NULL;
    }
    stack->top = -1;       // 初始时栈为空
    stack->capacity = capacity;
    return stack;
}
//入栈Push
int push(Stack *stack, int value){
    if (!stack)
    {
        printf("Not Initialized Stack!!%d \n",value);
        return 0;
    }
    if (stack->top == stack->capacity - 1) {
        printf("FULL Stack, failed to push %d!\n", value);
        return 0;
    }
    stack->data[++stack->top] = value;
    printf("Push successfully:%d\n",value);
    return 1;
}

//出栈
int pop(Stack *stack, int *value){
    if (!stack)
    {
        printf("Not Initialized Stack!!%d \n",value);
        return 0;
    }
    if (stack->top == -1)
    {
        printf("NULL Stack, failed to pop %d\n",*value);
        return 0;
    }
    *value = stack->data[stack->top--]; //取出栈顶值，更新栈顶指针(这是两步)，相当于*value = stack->data[stack->top];然后stack->top--; 
    printf("Pop successfully:%d\n",*value);
    return 1;
}

//查找栈顶元素
int peek(Stack *stack,int *value){
    if (!stack)
    {
        printf("Not Initialized Stack!!%d \n",value);
        return 0;
    }
    if (stack->top == -1)
    {
        printf("NULL Stack, failed to peek!\n");
        return 0;
    }
    *value = stack->data[stack->top];
    printf("Peek top: %d\n",*value);
    return 1;
}

// 删除栈
void destroyStack(Stack **stack) {
    if (!stack || !(*stack)) {
        printf("Not Initialized Stack!!\n");
        return;
    }
    free((*stack)->data);  // 释放栈中动态分配的数组
    free(*stack);          // 释放栈结构本身
    *stack = NULL;         // 置空指针，防止悬空指针
    printf("Stack destroied\n");
}


//打印栈的信息
void printStackInfo(Stack *stack) {
    if (!stack) {
        printf("Stack not exist\n");
        return;
    }
    printf("stack capacity: %d, top: %d\n", stack->capacity, stack->top);
}

// 打印栈的内容
void printStack(Stack *stack) {
    if (!stack) {
        printf("Stack NOT initialized!\n");
        return;
    }
    if (stack->top == -1) {
        printf("NULL Stack!!\n");
        return;
    }
    printf("Stack contents:");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

//测试代码和主函数
int main(){
    int capacity = 5;
    Stack *stack = createStack(capacity);
    if (stack)
    {
        printf("successfully created Stack!\n");
        printStackInfo(stack);
    }
    // 入栈操作
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
    push(stack, 40);
    push(stack, 50);
    push(stack, 60); // 尝试超出容量的入栈

    // 打印栈内容
    printStack(stack);

    // 查找栈顶元素
    int value;
    peek(stack, &value); // 栈顶应该是 30
    
    // 出栈操作
    pop(stack, &value); // 出栈：50
    //出栈后查看栈顶
    peek(stack, &value); // 栈顶应该是 20
    pop(stack, &value); // 出栈：40
    pop(stack, &value); // 出栈：30
    pop(stack, &value); // 出栈：20
    pop(stack, &value); // 出栈：10
    pop(stack, &value); // 栈为空，无法出栈

    printStack(stack);

    destroyStack(&stack);
    
    free(stack->data);
    free(stack);
    return 0;
}