#include <stdio.h>
int main(void){

    char str[100];
    char buf[100];
    int n;
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d", &n);
    for(int i = 0; i < n; i++) {
        fgets(str, sizeof(str), stdin);
        printf("%s", str);
    }
    return 0;
}