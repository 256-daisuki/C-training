#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void) {
    int number = 100;
    srand((unsigned int)time(NULL));
    int randnum = rand() % 6 + 1;
    printf("%d", randnum);
}
//サイコロ