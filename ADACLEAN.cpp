#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);


template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}

const int MAXN = 3e5 + 5;

ll MOD1 = MOD;
ll p1 = 43LL;
ll MOD2 = MOD + 2;
ll p2 = 107LL;
ll power1[MAXN], power2[MAXN];
ll prefix1[MAXN], prefix2[MAXN];

ll mod_sub(ll a, ll b, ll mod){
    return (a - b + mod) % mod;
}

ll mod_add(ll a, ll b, ll mod){
    return (a + b) % mod;
}

ll mod_mul(ll a, ll b, ll mod){
    return (a * b) % mod;
}

void init(){
    power1[0] = 1;
    power2[0] = 1;
    for(int i = 1; i < MAXN; i++){
        power1[i] = mod_mul(power1[i - 1], p1, MOD);
        power2[i] = mod_mul(power2[i - 1], p2, MOD2);
    }
}

void prefix_hash1(string &s){
    prefix1[0] = s[0];
    for(int i = 1; i < s.size(); i++)
        prefix1[i] = mod_add(prefix1[i - 1], mod_mul(s[i], power1[i], MOD), MOD);
}

void prefix_hash2(string &s){
    prefix2[0] = s[0];
    for(int i = 1; i < s.size(); i++)
        prefix2[i] = mod_add(prefix2[i - 1], mod_mul(s[i], power2[i], MOD2), MOD2);
}

pair<ll, ll> cal_hash(int l, int r){
    pair<ll, ll> p;
    if(l > 0){
        p.first = mod_mul(mod_sub(prefix1[r], prefix1[l - 1], MOD), invFermat(power1[l], MOD), MOD);
        p.second = mod_mul(mod_sub(prefix2[r], prefix2[l - 1], MOD2), invFermat(power2[l], MOD2), MOD2);
    }
    else{
        p.first = prefix1[r];
        p.second = prefix2[r];
    }

    return p;
}


int main(){
	io;
	init();
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		prefix_hash1(s);
		prefix_hash2(s);
		int l = 0, r = k - 1;
		set<pair<ll, ll> > uni;
		while(r < s.size()){
			pair<ll, ll> p = cal_hash(l, r);
			// cout << p.first << " " << p.second << endl;
			uni.insert(p);
			l++;
			r++;
		}
		cout << uni.size() << "\n";
	}
	return 0;
}