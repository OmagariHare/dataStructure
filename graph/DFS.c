#include <stdio.h>

#define MAX 100 // 最大顶点数

int adjMatrix[MAX][MAX]; // 邻接矩阵表示图
int visited[MAX];        // 访问标记数组
int n;                   // 顶点数

// 深度优先搜索函数
void DFS(int v)
{
    printf("%c ", 'A' + v); // 访问当前顶点
    visited[v] = 1;         // 标记为已访问

    // 遍历所有邻接顶点
    for (int i = 0; i < n; i++)
    {
        if (adjMatrix[v][i] == 1 && !visited[i])
        {
            DFS(i); // 递归访问未访问的邻接顶点
        }
    }
}

int main()
{
    n = 6; // 顶点数量（A-F）

    // 初始化邻接矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjMatrix[i][j] = 0;
        }
    }

    // 添加边 A-B, A-D, B-C, D-E, E-F, C-F
    adjMatrix[0][1] = adjMatrix[1][0] = 1; // A-B
    adjMatrix[0][3] = adjMatrix[3][0] = 1; // A-D
    adjMatrix[1][2] = adjMatrix[2][1] = 1; // B-C
    adjMatrix[3][4] = adjMatrix[4][3] = 1; // D-E
    adjMatrix[4][5] = adjMatrix[5][4] = 1; // E-F
    adjMatrix[2][5] = adjMatrix[5][2] = 1; // C-F

    // 初始化访问标记数组
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    // 从顶点 A 开始 DFS
    printf("DFS 遍历顺序：");
    DFS(0); // 从顶点 0（即 A）开始
    printf("\n");

    return 0;
}
