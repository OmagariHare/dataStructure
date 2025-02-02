//在C语言中，链表定义如下：
#include <stdio.h>
#include <stdlib.h>

//定义结构体
typedef struct Node {
    int data;           //数据部分
    struct Node* next;  //指针部分，指向下一个节点
} Node;

//创建单链表
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//创建链表，初始化为空
Node* createList(){
    return NULL;
}

//插入操作
//在链表头插入
void insertAtHead(Node ** head,int data){
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
//在链表尾插入
void insertAtTail(Node* head,int data){
    Node* newNode = createNode(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
//查找操作
Node* search(Node* head,int data){
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
//删除操作
//删除头节点
void deleteHead(Node** head){
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
//删除指定节点
void deleteNode(Node** head,int data){
    if (*head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    //特殊情况，如果删除的是头
    if ((*head)->data == data)
    {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL && temp->next->data!=data)
    {
        temp = temp->next;
    }
    //如果找到了要删除的节点
    if (temp->next != NULL)
    {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
    else{
        printf("Node with data %d not found\n",data);
    }    
}
//打印链表
void printList(Node* head){
    Node* temp = head;
    while (temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//主函数
int main() {
    Node* head = createList();  // 创建空链表

    insertAtHead(&head, 10);  // 插入节点
    insertAtHead(&head, 20);
    insertAtTail(head, 30);

    printf("Current List: ");
    printList(head);

    deleteNode(&head, 20);  // 删除节点
    printf("List after deletion: ");
    printList(head);

    Node* found = search(head, 30);  // 查找节点
    if (found != NULL) {
        printf("Node with value 30 found\n");
    } else {
        printf("Node with value 30 not found\n");
    }

    deleteHead(&head);  // 删除头节点
    printf("List after deleting head: ");
    printList(head);

    return 0;
}
