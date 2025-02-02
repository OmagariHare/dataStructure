#include <stdio.h>
#include <string.h>
//计算 next 数组
void ComputeNext(const char *pattern, int *next, int m){
    next[0] = 0;
    int j = 0;

    for (int i = 0; i < m; i++)
    {
        while (j > 0 && pattern[i]!=pattern[j])
        {
            j = next[j - i];
        }
        if (pattern[i] == pattern[j])
        {
            j++;
        }
        next[i] = j;
    }
}

//KMP字符串匹配
int KMPMatch(const char *text, const char *pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    int next[m];

    //得到next数组
    ComputeNext(pattern,next,m);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        while (j>0 && text[i] != pattern[j])
        {
            j = next[j - i];
        }
        if (text[i] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            return i - m + 1;
        }
    }
    return -1;
}

int main(){
    const char *text = "ABABDABACDABABCABAB";
    const char *pattern = "ABABCABAB";

    int result = KMPMatch(text, pattern);

    if (result != -1) {
        printf("Pattern found at index %d\n", result);
    } else {
        printf("Pattern not found\n");
    }

    return 0;
}