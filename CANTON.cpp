#include<stdio.h>
#include<math.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int i,num,sum=0;
        scanf("%d",&num);
        for(i=1;;i++)
        {
            sum+=i;
            if(sum>=num)
                break;
        }
        int temp=num-(sum-i);
        int total=i+1;
        if(i%2==0)
            printf("TERM %d IS %d/%d\n",num,temp,total-temp);
        else
            printf("TERM %d IS %d/%d\n",num,total-temp,temp);
    }
    return 0;
}
