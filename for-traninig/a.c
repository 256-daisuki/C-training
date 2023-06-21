// 特定期間の西暦年と令和年の対応表を作る
#include <stdio.h>

int main(void)
{
    char buf[100];
    int n;
    int m;
    
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);
    
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &m);
    
    for(int i = 1; i <= m; i++) {
        printf("西暦%d年 令和%2d年\n", n, i);
        n++;
    }
}