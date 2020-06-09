#include<stdio.h>
int main()
{
    int t,i,j,x,y,z;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d",&x,&y);
        for(j=1;j<=x;j++)
        {
            for(z=1;z<=y;z++)
            {
                if((j+z)%2==0)
                {
                printf("*");
                }
                else
                {
                printf(".");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
