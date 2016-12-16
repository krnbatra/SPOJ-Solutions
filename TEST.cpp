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
	int input;
	cin>>input;
	while(input!=42){
		cout<<input<<endl;
		cin>>input;
	}
	return 0;
}
