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

const int MAXN = 1e7+5;

bool isPrime[MAXN];

void sieve(){
	isPrime[0] = isPrime[1] = 1;
	for(int i = 2;i*i <= 10000000; i++){
		if(isPrime[i] == 0){
			if(i*1LL*i <= 10000000){
				for(int j = i*i;j <= 10000000; j+=i)
					isPrime[j] = 1;
			}
		}
	}
}

int answers[10005];

void precompute(){
	for(int i = 2;i <= 10000; i++){
		answers[i] = answers[i-1];
		int num = 2*i*i - 1;
		if(num <= 10000000 && isPrime[num] == 0)
			answers[i]++;
	}
}

int main(){
    io;
    sieve();
    precompute();
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	cout << answers[n] << endl;
    }
    return 0;
}