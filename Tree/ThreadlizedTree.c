#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

    struct TreeNode {
    char value;
    struct TreeNode* left;
    struct TreeNode* right;
    int leftThreaded;
    int rightThreaded;
};

// 创建节点
struct TreeNode* newNode(char value)
{
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = node->right = NULL;
    node->leftThreaded = node->rightThreaded = 0;
    return node;
};

//中序线索化
struct TreeNode* inorderThreading(struct TreeNode* root,struct TreeNode *prev){
    if (root == NULL)
    {
        return prev;
    }
    prev = inorderThreading(root->left, prev);

    //设置左指针线索
    if (root->left == NULL)
    {
        root->left = prev;
        root->leftThreaded = 1;
    }
    //设置右指针线索
    if (prev != NULL && prev->right == NULL)
    {
        prev->right = root;
        prev->rightThreaded = 1;
    }
    prev = root;

    return inorderThreading(root->right, prev);
}

//中序遍历线索二叉树
void inorderTraversal(struct TreeNode* root){
    struct TreeNode* current = root;

    while(current!=NULL){
        // 找到最左边的节点
        while (current->leftThreaded == 0 && current->left != NULL)
        {
            current = current->left;
        }
        printf("%c", current->value);

        // 如果右指针是线索，直接跳到后继节点
        if (current->rightThreaded)
        {
            current = current->right;
        }
        else
        {
            current = current->right;
        }
    }
}

int main(){
    // 构建普通二叉树
    struct TreeNode *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->left = newNode('F');

    // 线索化
    inorderThreading(root, NULL);

    // 中序遍历线索二叉树
    printf("Inorder traversal of threaded binary tree: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}