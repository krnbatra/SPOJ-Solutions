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

const int MAXN = 5e5+5;
int BIT[MAXN], A[MAXN];

void update(int idx, int val){
    while(idx <= MAXN){
        BIT[idx] += val;
        idx += idx & -idx;
    }
}

ll query(int idx){
    ll sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int main(){
    io;
    int n, p;
    cin >> n >> p;
    for(int i = 0;i < n; i++)
    	cin >> A[i];
    int T[n];
    for(int i = 0;i < n; i++)
    	T[i] = A[i];
    sort(T, T+n);
    for(int i = 0;i < n; i++){
    	int idx = lower_bound(T, T+n, A[i])-T;
    	A[i] = idx+1;
    }
    int l = 0, r = 0;
    ll max_inv = 0, max_l = -1;
    ll inv = 0;
    while(r < p){
    	inv += (query(500000)-query(A[r]));
    	update(A[r], 1);
    	if(inv > max_inv){
    		max_inv = inv;
    		max_l = l;
    	}
    	r++;
    }
    while(r < n){
    	inv -= query(A[l]-1);
    	update(A[l], -1);
    	l++;
    	inv += (query(500000)-query(A[r]));
    	update(A[r], 1);
    	if(inv > max_inv){
    		max_inv = inv;
    		max_l = l;
    	}
    	r++;
    }
    cout << max_l+1 << " " << max_inv << endl;
    return 0;
}