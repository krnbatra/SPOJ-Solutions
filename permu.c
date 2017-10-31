#include <stdio.h>
int find(int arr[],int num,int n){
	int i,ans;
	for(i=0;i<n;i++)
	{
		if(arr[i]==num)
		return i+1;
	}
	return 0;
	}
int main(void) {
int n,i;
scanf("%d",&n);
while(n>0)
{
	int arr[100000];
	int ans[100000];
	int j,k;
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	for(i=0;i<n;i++)
		{
			ans[i]=find(arr,i+1,n);
			if(ans[i]!=arr[i])
			{
				printf("not ambiguous\n");
				break;
			}
		}
	if(i==n)
	printf("ambiguous\n");
	
	scanf("%d",&n);
}

	// your code goes here
	return 0;
}
