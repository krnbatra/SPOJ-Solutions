/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb 	push_back
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

int n, k;
int arr[(int)1e6+5];

int isPossible(int val){
	//make greedy approach.
	//val is the min distance between two cows
	int lastCowIdx = 0;
	int cows = 1;
	int i = 0;
	while(i < n){
		if(arr[i]-arr[lastCowIdx] < val){
			i++;
		}
		else{
			lastCowIdx = i;
			cows++;
		}
	}
	// if(val == 2)
	// 	cout<<cows<<endl;
	if(cows >= k)
		return 1;
	return 0;
}

int binSearch(){
	int lo = 0;
	int hi = arr[n-1]-arr[0]+1;
	int mid;
	while(hi-lo > 1){
		mid = (lo+hi)/2;
		// cout<<mid<<endl;
		if(isPossible(mid))
			lo = mid;
		else
			hi = mid;
	}
	return lo;
}

int main(){
	int t;
	si(t);
	while(t--){
		si(n);
		si(k);
		FOR(i, n)	si(arr[i]);
		sort(arr, arr+n);
		int ans = binSearch();
		cout<<ans<<endl;
	}
    return 0;
}