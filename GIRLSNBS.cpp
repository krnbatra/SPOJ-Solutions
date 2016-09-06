/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;

#define MOD (int)1e9+7
#define ll long long
#define pb push_back

template <typename T> T mod(T a, T b){return (a%b>0)?(a%b):mod((a+b),b);}
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=mod((x*b),m);b=mod((b*b),m);p=p>>1;}return x;}	//use only for unsigned numbers

int main(){
	int g, b;
	cin>>g>>b;

	while(g!=-1 && b!=-1){
		if(g<b){swap(g, b);}
		if(g==0)
			cout<<b<<endl;
		else if(b==0)
			cout<<g<<endl;
		else
			cout<<ceil((float)g/(b+1))<<endl;
		cin>>g>>b;
	}
	return 0;
}
