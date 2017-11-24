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
int n, A[MAXN];

bool is_poss(ll mid){
	ll curr = mid;
	for(int i = 0;i < n; i++){
		curr += A[i];
		if(curr <= 0)
			return false;
	}
	return true;
}

int main(){
    io;
    int t;
    cin >> t;
    int tc = 1;
    while(t--){
    	cout << "Scenario #" << tc << ": ";
    	tc++;
    	cin >> n;
    	for(int i = 0;i < n; i++)
    		cin >> A[i];
    	ll lo = 0, hi = (ll)1e13;
    	while(hi-lo > 1){
    		ll mid = (lo+hi)/2;
    		if(is_poss(mid))
    			hi = mid;
    		else
    			lo = mid;
    	}
    	cout << hi << endl;
    }
    return 0;
}