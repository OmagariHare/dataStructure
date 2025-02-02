#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 动态串结构
typedef struct {
    char *data;  // 指向字符数组的指针
    int length;  // 串的实际长度
} String;

// 初始化动态串
void InitString(String *str, const char *chars) {
    int len = strlen(chars);
    str->data = (char *)malloc((len + 1) * sizeof(char));  // 分配内存
    if (!str->data) {
        printf("内存分配失败！\n");
        return;
    }
    strcpy(str->data, chars);  // 复制内容
    str->length = len;
    printf("动态串已初始化为: %s\n", str->data);
}

// 释放动态串
void FreeString(String *str) {
    if (str->data) {
        free(str->data);  // 释放内存
        str->data = NULL;
        str->length = 0;
    }
}

int main() {
    String myString;
    InitString(&myString, "Hello, Dynamic String!");
    printf("动态串的长度为: %d\n", myString.length);
    FreeString(&myString);
    return 0;
}
