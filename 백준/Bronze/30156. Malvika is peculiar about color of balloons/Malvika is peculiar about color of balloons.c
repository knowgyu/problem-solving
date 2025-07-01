#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        char s[105];
        scanf("%s", s);
        int a=0, b=0, i;
        for(i=0; s[i]; i++){
            if(s[i]=='a') a++;
            else b++;
        }
        printf("%d\n", a<b ? a : b);
    }
    return 0;
}
