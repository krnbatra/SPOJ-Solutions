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
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

const int MAXN = 1e6+5;
int minPrime[MAXN];	
void sieve(){
	minPrime[1] = 1;
	for(int i = 2; i*i <= MAXN; i++){
		if(minPrime[i] == 0){
			if(i*(ll)1*i <= MAXN){
				for(int j = i*i; j <= MAXN; j += (i)){
					if(minPrime[j] == 0)
						minPrime[j] = i;
				}
			}
		}
	}
	for(int i = 2;i <= MAXN; i++){
		if(minPrime[i] == 0)
			minPrime[i] = i;
	}
}
/* Time Complexity - O(logN + nloglogN) */
vector<int> factors;
ll eulerPhi(int n){
	set<int> s;
	ll res = n;
	while(n!=1){
		if(s.empty() || s.find(minPrime[n]) == s.end()){
			res = res-res/minPrime[n];
			s.insert(minPrime[n]);
		}
		n/=minPrime[n];
	}
	return res;
}



int main(int argc, char const *argv[]){
	int t;
	si(t);
	sieve();
	while(t--){
		int n;
		si(n);
		printf("%lld\n", eulerPhi(n));
	}
	return 0;
}