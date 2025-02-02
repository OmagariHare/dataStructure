#include <stdio.h>
#include <string.h>

// 朴素模式匹配算法
int BruteForceMatch(const char *text, const char *pattern) {
    int n = strlen(text);     // 主串长度
    int m = strlen(pattern);  // 模式串长度

    for (int i = 0; i <= n - m; i++) {  // 主串的每个可能起点
        int j;
        for (j = 0; j < m; j++) {       // 比较模式串每个字符
            if (text[i + j] != pattern[j]) {
                break;                  // 如果字符不匹配，退出当前循环
            }
        }
        if (j == m) {                   // 如果模式串全部匹配成功
            return i;                   // 返回匹配起始位置
        }
    }

    return -1;                          // 匹配失败
}

int main() {
    const char *text = "Hello, Data Structures and Algorithms!";
    const char *pattern = "Data";

    int position = BruteForceMatch(text, pattern);

    if (position != -1) {
        printf("模式串在主串中的起始位置: %d\n", position);
    } else {
        printf("模式串未找到！\n");
    }

    return 0;
}
