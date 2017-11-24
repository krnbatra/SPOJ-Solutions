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

const int MAXN = 1e5+5;

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	ll arr[n];
    	for(int i= 0;i < n; i++)
    		cin >> arr[i];
    	sort(arr, arr+n);
    	bool possible = true;
    	ll ans = 1;
    	for(int i = 0;i < n; i++){
    		ll mult = (arr[i]-i);
    		if(mult <= 0)	possible = false;
    		else	ans = (ans*mult) % MOD;
    	}
    	if(!possible)
    		cout << 0 << endl;
    	else
    		cout << ans << endl;
    }
    cout << "KILL BATMAN" << endl;
    return 0;
}