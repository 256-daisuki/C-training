#include <stdio.h>
int main(void){
    // 自分の得意な言語で
    // Let's チャレンジ！！
    char str[100];
    char n[100];
    fgets(n, sizeof(n), stdin);
    sscanf(n, "%d", &n);
    printf("%d", n);
    for(int i = 0; i < n; i++) {
        fgets(str, sizeof(str), stdin);
        printf("%s", str);
    }
    return 0;
}