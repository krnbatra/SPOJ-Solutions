#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
		ll x[100001];
		ll n, c;
		cin>>n>>c;
		for(ll i=0;i<n;i++)
		{
			cin>>x[i];
		}
		sort(x, x+n);
		ll lo = 0;
		ll hi = x[n-1] - x[0];
		while(lo<hi)
		{
			ll mid = lo + (hi-lo+1)/2;
			ll req = 1;
			//cout<<mid<<endl;
			
			ll bam = 0;
			for(ll i=1;i<n;i++)
			{
				if(x[bam] + mid <= x[i])
				{
					bam = i;
					req++;
				}
			}
			//cout<<req<<endl;
			if(req >= c)
				lo = mid;
			else
				hi = mid-1;
		}
		cout<<lo<<endl;
		}
		// your code goes here
		return 0;
}		
