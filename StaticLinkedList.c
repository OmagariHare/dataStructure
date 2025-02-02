#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// 定义静态链表的节点结构体
typedef struct {
    int data;
    int next;
} Node;

// 定义静态链表结构体
typedef struct {
    Node nodes[MAX_SIZE];
    int head;
    int free;
} StaticList;

// 初始化静态链表
void initList(StaticList* list) {
    list->head = -1;  // 初始化头指针为-1，表示链表为空
    list->free = 0;   // 空闲链表从数组的第一个位置开始

    // 初始化所有节点
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        list->nodes[i].next = i + 1;
    }
    list->nodes[MAX_SIZE - 1].next = -1;
}

// 创建一个新节点，返回该节点的下标
int createNode(StaticList* list, int data) {
    if (list->free == -1) {
        printf("No more space available!\n");
        return -1;
    }

    // 获取空闲链表的头节点
    int newNodeIndex = list->free;
    list->free = list->nodes[newNodeIndex].next;

    // 初始化新节点
    list->nodes[newNodeIndex].data = data;
    list->nodes[newNodeIndex].next = -1;

    return newNodeIndex;
}

// 在链表头插入新节点
void insertAtHead(StaticList* list, int data) {
    int newNodeIndex = createNode(list, data);  // 创建新节点
    if (newNodeIndex == -1) return;  // 如果没有空闲节点，返回

    // 新节点的next指向当前的头节点
    list->nodes[newNodeIndex].next = list->head;
    list->head = newNodeIndex;  // 更新头指针
}

// 在链表尾插入新节点
void insertAtTail(StaticList* list, int data) {
    int newNodeIndex = createNode(list, data);  // 创建新节点
    if (newNodeIndex == -1) return;  // 如果没有空闲节点，返回

    if (list->head == -1) {  // 如果链表为空
        list->head = newNodeIndex;
    } else {
        int temp = list->head;
        while (list->nodes[temp].next != -1) {  // 遍历到链表的最后一个节点
            temp = list->nodes[temp].next;
        }
        list->nodes[temp].next = newNodeIndex;  // 最后一个节点的next指向新节点
    }
    list->nodes[newNodeIndex].next = -1;  // 新节点的next指向-1，表示尾节点
}

// 查找指定值的节点
int search(StaticList* list, int data) {
    int temp = list->head;
    while (temp != -1) {  // 遍历链表
        if (list->nodes[temp].data == data) {
            return temp;  // 返回节点的下标
        }
        temp = list->nodes[temp].next;
    }
    return -1;  // 没有找到
}

// 删除头节点
void deleteHead(StaticList* list) {
    if (list->head == -1) {
        printf("List is empty\n");
        return;
    }

    int temp = list->head;
    list->head = list->nodes[temp].next;  // 更新头指针
    list->nodes[temp].next = list->free;  // 将删除的节点放回空闲链表
    list->free = temp;  // 更新空闲链表
}

// 删除指定节点
void deleteNode(StaticList* list, int data) {
    if (list->head == -1) {
        printf("List is empty\n");
        return;
    }

    int temp = list->head;
    int prev = -1;

    // 查找目标节点
    while (temp != -1 && list->nodes[temp].data != data) {
        prev = temp;
        temp = list->nodes[temp].next;
    }

    if (temp == -1) {
        printf("Node not found\n");
        return;  // 没有找到节点
    }

    if (prev == -1) {  // 删除的是头节点
        list->head = list->nodes[temp].next;
    } else {
        list->nodes[prev].next = list->nodes[temp].next;  // 前一个节点的next指向目标节点的next
    }

    list->nodes[temp].next = list->free;  // 将目标节点放回空闲链表
    list->free = temp;  // 更新空闲链表
}

// 打印链表
void printList(StaticList* list) {
    if (list->head == -1) {
        printf("List is empty\n");
        return;
    }

    int temp = list->head;
    while (temp != -1) {
        printf("%d -> ", list->nodes[temp].data);
        temp = list->nodes[temp].next;
    }
    printf("NULL\n");
}


int main() {
    StaticList list;
    initList(&list);  // 初始化链表

    insertAtHead(&list, 10);
    insertAtHead(&list, 20);
    insertAtTail(&list, 30);
    insertAtTail(&list, 40);

    printf("Current List: ");
    printList(&list);
}
