#include <stdio.h>
#include <stdlib.h>

// 定义树节点结构体
struct TreeNode
{
    char value;
    struct TreeNode *left;
    struct TreeNode *right;
};

// 查找根节点在中序遍历中的位置
int findIndex(char *inorder, int start, int end, char rootValue)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == rootValue)
        {
            return i;
        }
    }
    return -1;
}

// 使用后序遍历和中序遍历递归构建二叉树
struct TreeNode *buildTree(char *postorder, char *inorder, int inStart, int inEnd, int *postIndex)
{
    if (inStart > inEnd)
    {
        return NULL;
    }

    // 从后序遍历中获取当前节点值（后序遍历的根节点是最后一个元素）
    char rootValue = postorder[*postIndex];
    (*postIndex)--; // 后序遍历递减

    // 创建当前根节点
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->value = rootValue;
    root->left = root->right = NULL;

    // 在中序遍历中找到根节点的位置
    int inIndex = findIndex(inorder, inStart, inEnd, rootValue);

    // 递归构建右子树
    root->right = buildTree(postorder, inorder, inIndex + 1, inEnd, postIndex);

    // 递归构建左子树
    root->left = buildTree(postorder, inorder, inStart, inIndex - 1, postIndex);

    return root;
}

// 中序遍历输出树的节点
void inorderTraversal(struct TreeNode *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%c ", root->value);
        inorderTraversal(root->right);
    }
}

int main()
{
    // 假设后序和中序遍历序列
    char postorder[] = {'D', 'E', 'B', 'F', 'C', 'A'};
    char inorder[] = {'D', 'B', 'E', 'A', 'F', 'C'};

    int postIndex = 5; // 后序遍历的最后一个索引
    struct TreeNode *root = buildTree(postorder, inorder, 0, 5, &postIndex);

    // 中序遍历输出重建的二叉树
    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
