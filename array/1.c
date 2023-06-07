#include <stdio.h>
#include <string.h> //strcpy()を使うためのやつ

int main() {
    char s[] = "Hello world";
    printf("%s\n", s);
    strcpy(s, "Good Bye");
    printf("%s\n", s);
    return 0;
}