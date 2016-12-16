#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,ans=0;
    scanf("%d",&n);
    while(n!=0)
    {
        ans=0;
        for(i=1;i<=n;i++)
        {
            ans=ans+pow(i,2);
        }
        printf("%d\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
