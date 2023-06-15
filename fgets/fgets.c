// 標準入力
#include <stdio.h>

int main(void)
{
    char buf[100];
    fgets(buf, sizeof(buf), stdin);
    
    int n;
    sscanf(buf, "%d", &n);
    printf("%d",n*100);
}