#include <bits/stdc++.h>
using namespace std;

int n;
int counter;
int is_prime(int x)
{
	if(x==0||x==1)
		return 0;
	if(x==2)
		return 1;
	int y=sqrt(x);
	for (int i = 2; i < y; ++i)
	{
		if(x%i==0)
			return 0;
		/* code */
	}
	return 1;
}
void prime_xor(int i,int cval,int num[])
{
	if(i==n)
		return;
	bool flag=false;
	 if(is_prime(cval^num[i])==1)
	 {
	 	counter++;
	 	flag=false;
	 }
	 if(i+1<n&&num[i]==num[i+1])
	 {
	 	prime_xor(i+1,cval^num[i],num);
	 	int a=i;
	 	while(i<n&&num[i]==num[a])
	 		i++;
	 	prime_xor(i,cval,num);
	 }
	 else
	 {
	 	prime_xor(i+1,cval^num[i],num);
	 	prime_xor(i+1,cval,num);
	 }

}
int main() {
	//code
	int test;
	cin>>test;
	for(int i=0;i<test;i++)
	{
		
		cin>>n;
		int num[n];
		for (int x = 0; x < n; ++x)
		{
			cin>>num[x];
			/* code */
		}
		counter=0;
		prime_xor(0,0,num);
		cout<<counter<<"\n";

	}
	return 0;
}