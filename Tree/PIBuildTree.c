#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    char value;
    struct TreeNode *left;
    struct TreeNode *right;
};

//查找根节点在中序遍历中的位置
int findIndex(char *inorder, int start, int end, char rootValue){
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == rootValue)
        {
            return i;
        }
        
    }
    return -1;
}

//使用前序遍历和中序遍历构建二叉树
struct TreeNode* buildTree(char *preorder, char *inorder,int inStart,int inEnd,int *preIndex){
    if (inStart > inEnd)
    {
        return NULL;
    }
    //从前序遍历中获取当前节点值
    char rootValue = preorder[*preIndex];
    (*preIndex)++;
    //创建根节点
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->value = rootValue;
    root->left = root->right = NULL;

    //在中序遍历中找到根节点的位置
    int inIndex = findIndex(inorder, inStart, inEnd, rootValue);
    // 递归构建左子树和右子树
    root->left = buildTree(preorder, inorder, inStart, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, inEnd, preIndex);

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
    // 假设前序和中序遍历序列
    char preorder[] = {'A', 'B', 'D', 'E', 'C', 'F'};
    char inorder[] = {'D', 'B', 'E', 'A', 'F', 'C'};

    int preIndex = 0;
    struct TreeNode *root = buildTree(preorder, inorder, 0, 5, &preIndex);

    // 中序遍历输出重建的二叉树
    printf("Inorder traversal of the constructed tree: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}