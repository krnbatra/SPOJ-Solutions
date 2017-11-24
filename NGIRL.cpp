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
vector<ll> primes;
ll isPrime[MAXN];
vector<ll> primes_squares;

void sieve(){
	isPrime[0] = isPrime[1] = 1;
	for(int i = 2;i <= 1000000; i++){
		if(isPrime[i] == 0){
			primes.push_back(i);
			if(i*1LL*i <= 1000000){
				for(int j = i*i;j <= 1000000; j+=i)
					isPrime[j] = 1;
			}
		}
	}
}

void pre(){
	for(auto i : primes){
		primes_squares.push_back(i*1LL*i);
	}
}

int main(){
    io;
    sieve();
    pre();
    int t;
    cin >> t;
    while(t--){
    	ll n, k;
    	cin >> n >> k;
    	// ans1 is numbers which have 3 divisors less than equal to n
    	if(n <= 3)
    		cout << 0 << " " << 0 << endl;
    	else{
    		ll ans1 = upper_bound(primes_squares.begin(), primes_squares.end(), n) - primes_squares.begin() - 1;
    		ans1+=1;
    		ll ans2 = upper_bound(primes_squares.begin(), primes_squares.end(), k) - primes_squares.begin() - 1;
    		ans2+=1;
    		cout << ans1 << " ";
    		if(ans1 >= ans2)
    			cout << (ans1-ans2) << endl;
    		else
    			cout << 0 << endl;
    	}
    }
    return 0;
}