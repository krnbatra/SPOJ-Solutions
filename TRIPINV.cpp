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
ll BIT1[MAXN], BIT2[MAXN], A[MAXN];
ll ans1[MAXN], ans2[MAXN];

void update(int idx, int val, int bit){
    while(idx <= MAXN){
    	if(bit == 1)
        	BIT1[idx] += val;
        else
        	BIT2[idx] += val;
        idx += idx & -idx;
    }
}

ll query(int idx, int bit){
    ll sum = 0;
    while(idx > 0){
    	if(bit == 1)
        	sum += BIT1[idx];
        else
        	sum += BIT2[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main(){
    io;
 	int n;
 	cin >> n;   
  	for(int i = 0;i < n; i++)
  		cin >> A[i];
  	for(int i = 0;i < n; i++){
  		ans1[i] = (query(100000, 1)-query(A[i], 1));
  		update(A[i], 1, 1);
  	}
  	for(int i = n-1;i >= 0; i--){
  		ans2[i] = (query(A[i]-1, 2));
  		update(A[i], 1, 2);
  	}
  	ll ans = 0;
  	for(int i = 0;i < n; i++){
  		ans += (ans1[i]*ans2[i]);
  	}
  	cout << ans << endl;
    return 0;
}