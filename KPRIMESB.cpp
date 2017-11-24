/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e6+5;

bool isPrime[MAXN];
void sieve(){
	isPrime[0] = isPrime[1] = 1;
	for(int i = 2;i*i <= 1000000; i++){
		if(!isPrime[i]){
			if(i*1LL*i <= 1000000){
				for(int j = i*i;j <= 1000000; j += i)
					isPrime[j] = 1;
			}
		}
	} 
}

int matrix[MAXN];
int primes[55], n, k;

void solve(){
	for(int i = 0;i <= n; i++)
		matrix[i] = 0;

	for(int i = 0;i < k; i++){
		int num = primes[i];
		for(int j = num;j <= n; j += num){
			matrix[j] = 1;
		}
	}
}

int main(){
    sieve();
    int tc = 1;
    int t;
    scanf("%d", &t);
    while(t--){
    	scanf("%d%d", &n, &k);
    	for(int i = 0;i < k; i++)
    		scanf("%d", &primes[i]);
    	solve();
    	int ans = 0;
    	for(int i = 2;i <= n; i++){
    		if(!matrix[i] && isPrime[i]){	
    			ans++;
    		}
    	}
    	printf("Case %d: %d\n", tc, ans);
    	tc++;
    }
    return 0;
}