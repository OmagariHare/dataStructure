/*
遍历序列：

前序遍历：根 -> 左子树 -> 右子树。
中序遍历：左子树 -> 根 -> 右子树。
后序遍历：左子树 -> 右子树 -> 根。
构建二叉树的要求：

前序 + 中序 或 后序 + 中序 可以唯一确定一棵二叉树。
单独的前序或后序遍历无法确定唯一的二叉树。
*/
#include <stdio.h>
//先写由前序和中序构建二叉树
//定义二叉树节点
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
}TreeNode;

//创建节点
TreeNode* createNode(int data){
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    if (newNode) {
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

/// 从前序和中序序列构建二叉树
TreeNode* buildTree(int* preorder, int* inorder, int start, int end, int* preorderIndex) {
    if (start > end) return NULL;

    // 创建当前的根节点
    TreeNode* root = createNode(preorder[*preorderIndex]);
    (*preorderIndex)++;

    // 如果只有一个节点，直接返回
    if (start == end) return root;

    // 在中序序列中找到根节点的位置
    int inorderIndex;
    for (inorderIndex = start; inorderIndex <= end; inorderIndex++) {
        if (inorder[inorderIndex] == root->data) break;
    }

    // 构建左子树和右子树
    root->left = buildTree(preorder, inorder, start, inorderIndex - 1, preorderIndex);
    root->right = buildTree(preorder, inorder, inorderIndex + 1, end, preorderIndex);

    return root;
}

// 前序遍历二叉树验证结果
void preorderTraversal(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6, 7}; // 前序序列
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};  // 中序序列
    int n = sizeof(preorder) / sizeof(preorder[0]);

    int preorderIndex = 0;
    TreeNode* root = buildTree(preorder, inorder, 0, n - 1, &preorderIndex);

    printf("Constructed Tree Preorder Traversal: ");
    preorderTraversal(root);
    printf("\n");

    return 0;
}