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
ll freq[MAXN];

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	memset(freq, 0, sizeof freq);
    	ll n;
    	cin >> n;
    	int arr[n];
    	for(int i = 0;i < n; i++)
    		cin >> arr[i];
    	for(int i = 0;i < n; i++){
    		freq[arr[i]]++;
    	}
    	ll ans = (n*(n-1))/2;
    	bool swaps_done = false;
    	for(int i = 1;i <= 100000; i++){
    		if(freq[i] >= 2){
    			swaps_done = true;
    			ans -= (freq[i]*(freq[i]-1))/2;
    		}
    	}
    	if(swaps_done)
    		ans += 1;
    	cout << ans << endl;
    }
    return 0;
}