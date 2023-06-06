// whileによるループ処理
#include <stdio.h>

int main(void)
{
    int i = 0;
    while (i < 5) {
        printf("hello world %d\n", i);
        i = i + 1;
    }
}