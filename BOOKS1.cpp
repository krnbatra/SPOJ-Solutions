/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD 				1000000007LL
#define pb   				push_back
#define EPS 				1e-9
#define FOR(i,n) 			for(int i = 0;i < n; i++)
#define FORE(i,a,b) 		for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io 					ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl 				'\n'
#define F 					first
#define S 					second
#define sp 					' '
#define M_PI   				3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 505;
ll m, k;
ll arr[MAXN];

bool isPossible(int mid){
	// maxpossible pages assigned can be mid
	ll persons = 0;
	int i = 0;
	ll sum = 0;
	while(i < m){
		sum += arr[i];
		if(sum > mid){
			if(arr[i] > mid)
				return 0;
			sum = arr[i];
			persons++;
		}
		i++;
	}
	if(sum != 0)
		persons++;
	// cout << mid << sp << persons << endl;
	return (persons <= k);
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	cin >> m >> k;
    	FOR(i, m)	cin >> arr[i];
    	ll minn = INT_MAX;
    	FOR(i, m)
    		minn = min(minn, arr[i]);
    	ll maxx = 0;
    	FOR(i, m)	maxx += arr[i];
    	ll lo = minn-1, hi = maxx;
    	// cout << lo << sp << hi << endl;
    	while(hi-lo > 1){
    		int mid = (lo+hi)/2;
    		if(isPossible(mid))
    			hi = mid;
    		else
    			lo = mid;
    	}
    	// cout << hi << endl;
    	int i = m-1;
		ll sum = 0;
		vector<int> V;
		int numSlashes = 0;
		while(i >= 0){
			sum += arr[i];
			if(sum > hi){
				sum = arr[i];
				if(i != m-1){
					numSlashes++;
					V.pb(-1);
				}
			}
			V.pb(arr[i]);
			i--;
		}
		// cout << numSlashes << sp << k-1 << endl;
		for(int i = V.size()-1; i >= 0; i--){
			if(V[i] == -1){
				cout << "/ ";
			}
			else{
				cout << V[i] << sp;
				if((i-1) >= 0 && V[i-1] != -1 && numSlashes < (k-1)){
					// cout << "YSE" << endl;
					cout << "/ ";
					numSlashes++;
				}
			}
		}
		cout << endl;
    }
    return 0;
}
