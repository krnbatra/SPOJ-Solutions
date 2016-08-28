/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)10000007
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
int n;

int mergeTwo(int left[], int right[], int leftSize, int rightSize, int arr[]){
	int i = 0, j = 0, k = 0;
	int count = 0;
	while(i < leftSize && j < rightSize){
		if(left[i] > right[j]){
			arr[k] = right[j];
			j++;
			count = (count + leftSize-i)%MOD;
		}else if(right[j] >= left[i]){
			arr[k] = left[i];
			i++;
		}
		k++;
	}
	while(i < leftSize){
		arr[k] = left[i];
		i++;
		k++;
	}
	while(j < rightSize){
		arr[k] = right[j];
		j++;
		k++;
	}
	return count;
}

int inversionCount(int arr[], int size){
	if(size <= 1)
		return 0;
	int leftSize = size/2;
	int rightSize = size-leftSize;
	int left[leftSize];
	for(int i = 0;i < leftSize; i++){
		left[i] = arr[i];
		// cout<<left[i]<<endl;
	}
	// cout<<"HELLO"<<endl;
	int right[rightSize];
	for(int i = 0;i < rightSize; i++){
		right[i] = arr[i+leftSize];
	}
	int count = 0;
	count = (count + inversionCount(left, leftSize))%MOD;
	count = (count + inversionCount(right, rightSize))%MOD;
	count = (count + mergeTwo(left, right, leftSize, rightSize, arr))%MOD;
	return count;
}

int main(){
    int t;
    si(t);
    int kase = 1;
    while(t--){
    	si(n);
    	int arr[n];
    	FOR(i, n)	si(arr[i]);
    	ll ans = inversionCount(arr, n);
    	printf("Case %d: %lld\n", kase, ans);
    	kase++;
    }
    return 0;
}