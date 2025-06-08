#include <stdio.h>

int main() {
    int T;
    int R;
    char S[21];
    
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %s", &R, S);
        
        for(int i=0;S[i];i++)
        {
            for(int j=0;j<R;j++)
            {
                putchar(S[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
