#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void){
    srand((unsigned int)time(NULL));
    int omikuji = rand() % 10 + 1;
    if (omikuji == 1) {
        printf("大吉");
    } else if (omikuji == 2) {
        printf("中吉");
    } else if (omikuji <= 4) {
        printf("小吉");
    } else if (omikuji <= 7) {
        printf("凶");
    } else {
        printf("大凶");
    }
}