#include <stdio.h>
int main()
{
    int a,b,c,d;
    scanf("%d %d %d %d", &a,&b,&c,&d);
    
    if (a+c < b+d)
        printf("Hanyang Univ.");
    else if (a+c > b+d)
        printf("Yongdap");
    else
        printf("Either");
    return 0;
}