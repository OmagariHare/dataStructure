#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    char value;
    struct TreeNode *left;
    struct TreeNode *right;
    int leftThreaded;
    int rightThreaded;
};

// 创建新节点
struct TreeNode *newNode(char value)
{
    struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    node->value = value;
    node->left = node->right = NULL;
    node->leftThreaded = node->rightThreaded = 0; // 初始时不是线索
    return node;
}

// 中序遍历并设置线索
struct TreeNode *inorderThreading(struct TreeNode *root, struct TreeNode *prev)
{
    if (root == NULL)
        return prev; // 返回前驱节点

    // 递归左子树
    prev = inorderThreading(root->left, prev);

    // 设置线索
    if (root->left == NULL)
    {
        root->left = prev;
        root->leftThreaded = 1; // 表示左指针是线索
    }
    if (prev != NULL && prev->right == NULL)
    {
        prev->right = root;
        prev->rightThreaded = 1; // 表示右指针是线索
    }

    // 更新前驱节点
    prev = root;

    // 递归右子树
    return inorderThreading(root->right, prev);
}

// 中序遍历线索二叉树
void inorderTraversal(struct TreeNode *root)
{
    struct TreeNode *current = root;

    // 找到最左边的节点
    while (current != NULL)
    {
        // 找到最左边的节点，跳过所有左孩子指针
        while (current->leftThreaded == 0 && current->left != NULL)
        {
            current = current->left;
        }

        // 打印当前节点的值
        printf("%c ", current->value);

        // 如果右指针是线索，直接跳到后继节点
        if (current->rightThreaded)
        {
            current = current->right;
        }
        else
        {
            current = current->right;
        }

        // 如果右指针为空且没有线索，跳出循环
        if (current == NULL)
            break;
    }
}

int main()
{
    // 构建二叉树
    struct TreeNode *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->left = newNode('F');

    // 设置线索
    inorderThreading(root, NULL);

    // 中序遍历线索二叉树
    printf("Inorder traversal of threaded binary tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
