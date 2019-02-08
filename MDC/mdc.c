#include <stdio.h>

int mdc(int n, int n2)
{
    if(n == 0)
    {
        return n2;
    }else if(n2 == 0)
    {
        return n;
    }
    
    return mdc(n2 % n, n % n2);
}

int main()
{
    int n, n2;

    scanf("%d\n%d", &n, &n2);

    printf("MDC: %d\n", mdc(n, n2));

    return 0;
}