/*input
2
808
2133
*/
#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0)	
#define FOR(i, a, b) for(long long i = a;i < b; i++)		
#define rev(i, a, b) for(long long i = a;i > b; i--)		
#define si(a)   scanf("%d", &a) 					
#define pi(a)   printf("%d\n", a)					
typedef long long ll;
#define dbl long double		
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int> 
#define pll pair< ll , ll >
#define vpll vector< pll >		
#define all(v) v.begin(),v.end()				
#define pb push_back									//^
#define ff first										//^
#define ss second										//^
#define MOD (ll)1000000007								//^
#define M_PI 3.14159265358979323846
#define ednl endl
#define N 1000005
#define MAX 100005
#define EPS 1e-12
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
using namespace std;

bool Check1(vector<int> s)
{
	for(auto i:s)
	{
		if(i!=9)
			return 0;
	}

	return 1;

}


int main()
{
	fio;
	ll t;
	cin>>t;
	while(t--)
	{
		string tmp;
		cin>>tmp;
		vector<int> s;
		for(int i=0;i<tmp.size();i++)
			s.pb(tmp[i]-'0');

		//case1
		if(Check1(s))
		{
			cout<<'1';
			for(int i=0;i<s.size()-1;i++)
				cout<<'0';
			cout<<'1'<<endl;
		}
		else
		{
			// string s = to_string(a);
			int n = s.size();
			int mid = n/2;
			// cout<<n<<" "<<mid<<"asda";
			int left = mid-1;
			int right;
			if(n&1)
				right = mid+1;
			else
				right = mid;
			while(left>=0 && s[left]==s[right])
			{
				left--;
				right++;
			}
			bool leftsmaller;
			if(left<0 || s[left]<=s[right])
				leftsmaller = true;
			else
				leftsmaller = false;

			while(left>=0)
			{
				s[right] = s[left];
				right++;
				left--;
			}

			if(leftsmaller)
			{
				int carry = 1;
				int i = mid-1;
				int j;
				if(n&1)
				{
					j = mid+1;
					if(s[mid]!=9)
					{
						// cout<<s[mid]<<" ---";
						s[mid]+=carry;
						carry = 0;
					}
					else
					{
						s[mid] = 0;
						carry = 1;
					}
				}
				else
					j = mid;
				while(i>=0)
				{
					s[i] +=carry;
					if(s[i]==10)
					{
						carry = 1;
						s[i] = 0;
					}
					else
						carry = 0;
					s[j] = s[i];
					j++;
					i--;
				}

			}
			for(auto i:s)
				cout<<i;
			cout<<endl;
		}

	}

	return 0;
}
