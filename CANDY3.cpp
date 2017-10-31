#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int ppl,i,sum=0,temp;
        scanf("%lld",&ppl);
        for(i=0;i<ppl;i++)
        {
            scanf("%lld",&temp);
            sum=(sum+temp)%ppl;
        }
        if(sum)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}