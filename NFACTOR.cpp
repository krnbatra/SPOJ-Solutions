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

int numFactors[1000005];
vector<int> arr[11];	//arr[0] contains numbers which are 0 factorful.

void precal(){
	for(int i = 2;i < 1000005; i++){
		if(numFactors[i] == 0){
			numFactors[i] = 1;
			for(int j = 2*i; j < 1000005; j+=i){
				numFactors[j]++;
			}
		}
	}
}

int main(){
    int t;
    si(t);
    precal();
    for(int i = 1; i < 1000001; i++){
    	if(numFactors[i] <= 10){
    		// cout<<"HE"<<endl;
    		arr[numFactors[i]].pb(i);
    	}
    }
    while(t--){
    	int a, b, n;
    	si(a);
    	si(b);
    	si(n);
    	int res = 0;
    	//do binary search on arr[n] to find the number of numbers that lies between a and b.
    	//find first occurence of a
    	int begin = lower_bound(arr[n].begin(), arr[n].end(), a)-arr[n].begin();
    	int end = upper_bound(arr[n].begin(), arr[n].end(), b)-arr[n].begin();
    	res = end-begin;
    	pi(res);
    	// cout<<"karan"<<endl;
    }
    return 0;
}