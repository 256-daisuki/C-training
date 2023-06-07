#include <stdio.h>
#include <string.h> //strcpy()を使うためのやつ

int main() {
    char s[] = "Hello";
    printf("%c\n", s[1]);
    
    s[3] = 'p';     //Helloを無理やりHelpに変換する。
    s[4] = '\0';
    printf("%s\n", s);

    return 0;
}