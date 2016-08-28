/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define MOD (ll)1e9+7
#define pb push_back
#define EPS 1e-9

template <typename T> T mod(T a, T b){return (a%b>0)?(a%b) : mod(a+b, b);}
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=mod((x*b),m);b=mod((b*b),m);p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

int t;
int n;

int MAXN = 100000;
vector<bool> prime(MAXN+1, true);
vector<int> primes;
void sieve(){
	prime[0] = prime[1] = false;
	for(int i = 2; i <= MAXN; i++){
		if(prime[i]){
      primes.pb(i);
			if(i*(ll)1*i <= MAXN){
				for(int j = i*i;j <= MAXN; j+=i)
					prime[j] = false;
			}
		}
	}
}

int arr[100001];
void segmented_sieve(int a, int b){
  if(a==1)
    a++;
  int sqrtn = sqrt(b);
  memset(arr, 0, sizeof arr);
  for(int i = 0; i<primes.size() && primes[i]<=sqrtn; i++){
    int p = primes[i];
		// cout<<p<<endl;
    int j = p * p;
   ///If j is smaller than a, then shift it inside of segment [a,b]
    if ( j < a ) j = ( ( a + p - 1 ) / p ) * p;

    for ( ; j <= b; j += p ) {
       arr[j-a] = 1; ///mark them as not prime
    }

  }
	for ( int i = a; i <= b; i++ ) {
			///If it is not marked, then it is a prime
			if( arr[i-a] == 0 ) cout<<i<<endl;
	}
}

int main(){
  cin>>t;
  sieve();
  while(t--){
    int a, b;
    cin>>a>>b;
    segmented_sieve(a, b);
  }
	return 0;
}
