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
ll BIT1[MAXN], BIT2[MAXN];

void update(int idx, ll val, int bit){
	while(idx <= 100000){
		if(bit == 1)
			BIT1[idx] += val;
		else
			BIT2[idx] += val;
		idx += idx&-idx;
	}
}

void updateQuery(int l, int r, ll val){
	update(l, val, 1);
	update(r+1, -val, 1);
	update(l, val*(l-1), 2);
	update(r+1, -val*r, 2);
}

ll query(int idx, int bit){
	ll sum = 0;
	while(idx > 0){
		sum += ((bit == 1) ? BIT1[idx] : BIT2[idx]);
		idx -= idx&-idx;
	}
	return sum;
}

ll queryUtil(int idx){
	return idx*query(idx, 1) - query(idx, 2);
}

ll queryRange(int l, int r){
	return queryUtil(r) - queryUtil(l-1);
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	memset(BIT1, 0, sizeof BIT1);
    	memset(BIT2, 0, sizeof BIT2);
    	int n, c;
    	cin >> n >> c;
    	for(int i = 0;i < c; i++){
    		int type;
    		cin >> type;
    		if(type == 0){
    			ll p, q, v;
    			cin >> p >> q >> v;
    			updateQuery(p, q, v);
    		}else{
    			int p, q;
    			cin >> p >> q;
    			cout << queryRange(p, q) << endl;
    		}
    	}
    }
    return 0;
}