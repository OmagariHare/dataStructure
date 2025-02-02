#include <stdio.h>
#include <stdlib.h>

//定义结构体
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

//创建双链表
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

//创建空链表
Node* createList(){
    return NULL;
}

//插入操作
//在链表头插入
void insertAtHead(Node** head,int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }
    *head = newNode;
}
//在链表尾插入
void insertAtTail(Node** head,int data){
    Node* newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
}
//查找操作
Node* search(Node* head, int data){
    Node* temp = head;
    while (temp != NULL){
        if (temp->data == data)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
//删除头节点
void deleteHead(Node** head){
    if (*head == NULL)
    {
        printf("List is empty\n");
    }
    Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    
    free(temp);
}

//删除指定节点
void deleteNode(Node** head,int data){
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
//如果删除的是头节点
if (temp->data == data)
{
    *head = temp->next;
    if (*head != NULL)
    {
        (*head)->prev = NULL;
    }
    free(temp);
    return;
}
//遍历链表查找目标节点
    while (temp != NULL && temp->data != data)
    {
        temp = temp->next;
    }
    
if (temp == NULL)
{
    printf("Node with data %d not found\n", data);
}
//更新相邻节点的指针
if (temp->prev != NULL)
{
    temp->prev->next = temp->next;
}
if (temp->next != NULL)
{
    temp->next->prev = temp->prev;
}
free(temp);
}

//打印链表
void printList(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
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
