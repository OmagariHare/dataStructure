//线索二叉树的基本概念
/*
线索化：

在普通二叉树中，每个节点有两个指针（left 和 right），分别指向左子节点和右子节点。
如果某个节点没有左或右子节点，则其指针为空（NULL）。
在线索二叉树中，将这些空指针改为指向该节点在遍历序列中的前驱或后继节点的指针。
类型：

前序线索二叉树：空指针指向节点的前序遍历前驱或后继。
中序线索二叉树：空指针指向节点的中序遍历前驱或后继。
后序线索二叉树：空指针指向节点的后序遍历前驱或后继。
标志位：

每个节点需要增加两个标志位：lTag 和 rTag。
lTag == 0：left 指针指向左子树。
lTag == 1：left 指针是线索，指向前驱。
rTag == 0：right 指针指向右子树。
rTag == 1：right 指针是线索，指向后继。
*/

//中序线索二叉树
#include <stdio.h>
#include <stdlib.h>

// 定义线索二叉树节点
typedef struct ThreadedTreeNode {
    int data;
    struct ThreadedTreeNode* left;
    struct ThreadedTreeNode* right;
    int lTag; // 左标志位
    int rTag; // 右标志位
} ThreadedTreeNode;

// 创建新节点
ThreadedTreeNode* createNode(int data) {
    ThreadedTreeNode* newNode = (ThreadedTreeNode*)malloc(sizeof(ThreadedTreeNode));
    if (newNode) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->lTag = 0;
        newNode->rTag = 0;
    }
    return newNode;
}

// 中序线索化二叉树
void inOrderThreading(ThreadedTreeNode* root, ThreadedTreeNode** pre) {
    if (root == NULL) return;

    // 递归左子树
    inOrderThreading(root->left, pre);

    // 处理当前节点
    if (root->left == NULL) {
        root->left = *pre;
        root->lTag = 1; // 左指针是线索
    }
    if (*pre != NULL && (*pre)->right == NULL) {
        (*pre)->right = root;
        (*pre)->rTag = 1; // 右指针是线索
    }
    *pre = root;

    // 递归右子树
    inOrderThreading(root->right, pre);
}

// 创建中序线索二叉树
ThreadedTreeNode* createInOrderThreadedTree(ThreadedTreeNode* root) {
    ThreadedTreeNode* pre = NULL;
    inOrderThreading(root, &pre);
    return root;
}

// 中序遍历线索二叉树
void inOrderTraversal(ThreadedTreeNode* root) {
    ThreadedTreeNode* curr = root;

    // 找到中序遍历的第一个节点
    while (curr != NULL && curr->lTag == 0) {
        curr = curr->left;
    }

    while (curr != NULL) {
        printf("%d ", curr->data);

        // 如果有后继线索，直接跳到后继节点
        if (curr->rTag == 1) {
            curr = curr->right;
        } else {
            // 否则，进入右子树的最左节点
            curr = curr->right;
            while (curr != NULL && curr->lTag == 0) {
                curr = curr->left;
            }
        }
    }
}

int main() {
    // 创建普通二叉树
    ThreadedTreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // 创建中序线索二叉树
    createInOrderThreadedTree(root);

    // 中序遍历线索二叉树
    printf("In-order traversal of threaded binary tree: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}
