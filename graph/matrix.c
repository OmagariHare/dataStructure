#include <stdio.h>
#define MAX 100

int main(){
    int n = 3;
    int adjMatrix[MAX][MAX] = {0};

    //添加边A-B和B-C
    adjMatrix[0][1] = 1; 
    adjMatrix[1][0] = 1;
    adjMatrix[1][2] = 1;
    adjMatrix[2][1] = 1;

    //打印邻接矩阵
    printf("邻接矩阵： \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ",adjMatrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}