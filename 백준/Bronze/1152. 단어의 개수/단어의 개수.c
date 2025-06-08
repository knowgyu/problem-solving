#include <stdio.h>

int main() {
    char str[1000005];
    
    int ans = 0;
    while(scanf("%s", str) == 1)
    {
        ++ans;
    }
    
    printf("%d", ans);
    
    return 0;
}
