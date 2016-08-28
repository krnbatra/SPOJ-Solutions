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

const int MAXN = 1e6;
vector<int> primes;
int isPrime[MAXN];	//isPrime[i] = 0 indicates i is prime. 
void sieve(){
	//if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
	isPrime[0] = isPrime[1] = 1;
	primes.pb(2);
	for(int i = 3; i <= MAXN; i+=2){
		if(isPrime[i] == 0){
			primes.pb(i);
			if(i*(ll)1*i <= MAXN){
				for(int j = i*i; j <= MAXN; j += (2*i)){
					isPrime[j] = 1;
				}
			}
		}
	}
}

const int SIZE = (int)1e6+1; 	//define size to be max(B-A+1)
int arr[SIZE];
void segmentedSieve(int a, int b){
	memset(arr, 0, sizeof(arr));
	if(a == 1)	a++;
	int sqrtn = sqrt(b);
	//arr[0] represents a
	for(int i = 0;i < primes.size() && primes[i] <= sqrtn; i++){
		int p = primes[i];
		int j = p*p;

		if(j < a)	j = ((a+p-1)/p)*p;
		for(; j <= b; j+=p)
			arr[j-a] = 1;
	}
	int res = 0;
	for(int i = a; i<= b; i++){
		if(arr[i-a] == 0)
			pi(i);
	}
	return;
}


int main(){
	sieve();
    int t;
    si(t);
    while(t--){
    	int a, b;
    	si(a);
    	si(b);
    	segmentedSieve(a, b);
    	// pi(ans);
    }
    return 0;
}