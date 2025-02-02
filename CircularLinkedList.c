#include <stdio.h>
#include <malloc.h>
//单向循环链表的结构和普通单链表的节点结构相似，只是最后一个next指针指向头节点

//定义单项列表的结构体
typedef struct Node{
    int data;
    struct Node* next;
}Node;

//创建一个新的节点
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode;  // 新节点的next指向自己，形成环
    return newNode;
}

//创建空循环链表
Node* create(){
    return NULL;
}

//头插
void insertAtHead(Node** head,int data){
    Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else{
        Node* temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
    
}

//尾插
void insertAtTail(Node** head,int data){
    Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
    }
    else{
        Node* temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
}

//查找操作
Node* search(Node* head,int data){
    if (head == NULL)
    {
        return NULL;
    }
    Node* temp = head;
    do
    {
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    } while (temp != head);
    return NULL;
}

//删除头
void deleteHead(Node** head){
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    if (temp->next == *head)
    {
        *head = NULL;
        free(temp);
    }
    else{
        Node* last = *head;
        while (last->next != *head)
        {
            last = last->next;
        }
        *head = temp->next;
        last->next = *head;
        free(temp);
    }
}

// 删除指定节点
void deleteNode(Node** head, int data) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = *head;
    if (temp->data == data) {
        deleteHead(head);
        return;
    }

    Node* prev = NULL;
    while (temp->next != *head && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == data) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Node with data %d not found\n", data);
    }
}

// 打印循环链表
void printList(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  // 遍历一圈，回到头节点
    printf("(head)\n");
}

int main() {
    Node* head = NULL;  // 创建空链表

    insertAtHead(&head, 10);  // 在头部插入
    insertAtHead(&head, 20);
    insertAtTail(&head, 30);  // 在尾部插入

    printf("Current List: ");
    printList(head);

    deleteNode(&head, 20);  // 删除节点
    printf("List after deletion: ");
    printList(head);

    deleteHead(&head);  // 删除头节点
    printf("List after deleting head: ");
    printList(head);

    Node* found = search(head, 30);  // 查找节点
    if (found != NULL) {
        printf("Node with value 30 found\n");
    } else {
        printf("Node with value 30 not found\n");
    }

    return 0;
}
