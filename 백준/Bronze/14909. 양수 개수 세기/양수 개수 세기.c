#include <stdio.h>

int main(void) {
    int x;
    int count = 0;

    while (scanf("%d", &x) == 1) {
        if (x > 0) {
            count++;
        }
    }

    printf("%d", count);
    return 0;
}
