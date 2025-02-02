#include <stdio.h>
typedef struct SharedStack
{
    int *data;
    int top1;
    int top2;
    int capacity;
}SharedStack;

//创建共享栈
SharedStack* createSharedStack(int capacity) {
    SharedStack *stack = (SharedStack*)malloc(sizeof(SharedStack));
    stack->data = (int*)malloc(sizeof(int) * capacity);
    stack->top1 = -1;               // 栈1的栈顶初始化为 -1
    stack->top2 = capacity;         // 栈2的栈顶初始化为容量值
    stack->capacity = capacity;    // 设置容量
    return stack;
}

//入栈
// 栈1入栈
int push1(SharedStack *stack, int value) {
    if (stack->top1 + 1 == stack->top2) { // 判断共享栈是否已满
        printf("共享栈满了，无法在栈1入栈 %d！\n", value);
        return 0; // 失败
    }
    stack->data[++stack->top1] = value; // 栈1从左端向右生长
    printf("栈1成功入栈：%d\n", value);
    return 1; // 成功
}

// 栈2入栈
int push2(SharedStack *stack, int value) {
    if (stack->top1 + 1 == stack->top2) { // 判断共享栈是否已满
        printf("共享栈满了，无法在栈2入栈 %d！\n", value);
        return 0; // 失败
    }
    stack->data[--stack->top2] = value; // 栈2从右端向左生长
    printf("栈2成功入栈：%d\n", value);
    return 1; // 成功
}

//出栈
// 栈1出栈
int pop1(SharedStack *stack, int *value) {
    if (stack->top1 == -1) { // 判断栈1是否为空
        printf("栈1为空，无法出栈！\n");
        return 0; // 失败
    }
    *value = stack->data[stack->top1--]; // 从栈1取出栈顶值
    printf("栈1成功出栈：%d\n", *value);
    return 1; // 成功
}

// 栈2出栈
int pop2(SharedStack *stack, int *value) {
    if (stack->top2 == stack->capacity) { // 判断栈2是否为空
        printf("栈2为空，无法出栈！\n");
        return 0; // 失败
    }
    *value = stack->data[stack->top2++]; // 从栈2取出栈顶值
    printf("栈2成功出栈：%d\n", *value);
    return 1; // 成功
}

//打印共享栈
void printSharedStack(SharedStack *stack) {
    printf("栈1内容（从栈底到栈顶）：");
    for (int i = 0; i <= stack->top1; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");

    printf("栈2内容（从栈底到栈顶）：");
    for (int i = stack->capacity - 1; i >= stack->top2; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

int main() {
    int capacity = 10;
    SharedStack *stack = createSharedStack(capacity);

    // 栈1入栈
    push1(stack, 10);
    push1(stack, 20);
    push1(stack, 30);

    // 栈2入栈
    push2(stack, 100);
    push2(stack, 200);
    push2(stack, 300);

    printSharedStack(stack);

    // 栈1出栈
    int value;
    pop1(stack, &value);
    pop1(stack, &value);

    // 栈2出栈
    pop2(stack, &value);
    pop2(stack, &value);

    printSharedStack(stack);

    // 释放内存
    free(stack->data);
    free(stack);

    return 0;
}
