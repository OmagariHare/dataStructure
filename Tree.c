/*

一、树的基础知识
树的定义：
树是一种层次结构的非线性数据结构，由一个根节点和若干子树组成。

根节点：树的起点。
子节点：直接连接到上层节点的节点。
叶子节点：没有子节点的节点。
常见术语

节点的度：节点拥有的直接子节点数量。
树的度：树中最大节点度的值。
深度：从根节点到当前节点的路径长度（层数）。
高度：从当前节点到叶子节点的最长路径长度。
常见类型

普通树：没有限制的层次结构。
二叉树：每个节点最多有两个子节点（左、右）。
二叉搜索树（BST）：满足左子树的所有节点值 < 根节点值 < 右子树的所有节点值。
完全二叉树：所有层都是满的，最后一层从左到右依次填充。
平衡二叉树：所有子树的高度差不超过1。

*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

//这里从二叉树讲起
typedef struct TreeNode {
    int data; // 节点数据
    struct TreeNode* left; // 左子节点
    struct TreeNode* right; // 右子节点
} TreeNode;

//创建一个新节点
TreeNode* createNode(int data){
    TreeNode* newNode = (TreeNode *) malloc(sizeof(TreeNode));
    if (newNode)
    {
        newNode -> data = data;
        newNode -> left = NULL;
        newNode -> right = NULL;
    }
    return newNode;
}

//二叉树的遍历
/*
前序遍历：根 -> 左 -> 右
中序遍历：左 -> 根 -> 右
后序遍历：左 -> 右 -> 根
层序遍历：逐层从左到右遍历（需要队列）
*/
//前序遍历
void preorder(TreeNode *root){
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

//中序遍历
void inorder(TreeNode *root){
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

//后序遍历
void postorder(TreeNode* root){
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
}

//层序遍历（需亚队列）
/*
初始化一个队列，将根节点入队。
从队列中取出一个节点（出队），访问该节点。
如果该节点有左子节点，将左子节点入队。
如果该节点有右子节点，将右子节点入队。
重复以上步骤直到队列为空。
*/
typedef struct Queue {
    TreeNode* data[MAX_SIZE];
    int front, rear;
} Queue;

// 初始化队列
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}

// 判断队列是否为空
int isEmpty(Queue* q) {
    return q->front == q->rear;
}

// 入队
void enqueue(Queue* q, TreeNode* node) {
    if ((q->rear + 1) % MAX_SIZE == q->front) return; // 队列满
    q->data[q->rear] = node;
    q->rear = (q->rear + 1) % MAX_SIZE;
}

// 出队
TreeNode* dequeue(Queue* q) {
    if (isEmpty(q)) return NULL; // 队列空
    TreeNode* node = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    return node;
}

// 层序遍历
void levelOrder(TreeNode* root) {
    if (root == NULL) return;

    typedef struct Queue {
        TreeNode* data[MAX_SIZE];
        int front, rear;
    } Queue;

    Queue q;
    initQueue(&q);
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        TreeNode* node = dequeue(&q);
        printf("%d ", node->data);

        if (node->left != NULL) enqueue(&q, node->left);
        if (node->right != NULL) enqueue(&q, node->right);
    }
}

int main() {
    // 创建二叉树
    TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    printf("Level Order Traversal: ");
    levelOrder(root);
    printf("\n");

    return 0;
}