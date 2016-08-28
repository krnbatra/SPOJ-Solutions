/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb 	push_back
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)
#define si(a)   scanf("%d", &a) 
#define pi(a)   printf("%d\n", a)
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

int main(){
	int n;
	si(n);
	ll ans = 0;
	multiset<int> s;
	multiset<int>::iterator it;
	for(int i = 1;i <= n; i++){
		int k;
		si(k);
		for(int j = 1;j <= k; j++){
			int l;
			si(l);
			s.insert(l);
    	}
		int val1 = *(s.begin());
		set<int>::iterator it1 = s.begin();
		it = s.end();
		it--;
		int val2 = *(it);
		ans+=(val2-val1);
// 		cout<<val1<<' '<<val2<<endl;
		s.erase(it);
		s.erase(it1);
// 		cout<<s.size()<<endl;
	}
	printf("%lld\n", ans);
	return 0;
}