#include <stdio.h>
#include <time.h>
int main(int argc, char **argv) {
    time_t t = time(NULL);
    printf("%ld\n", t);
    printf("%zd\n", sizeof(time_t));
    return 0;
}