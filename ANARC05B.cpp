/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

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

int main(){
    io;
    int n1,n2;
    while(1){
    	cin>>n1;
    	if(n1 == 0)
    		break;
    	int arr1[n1];
    	FOR(i,n1)	cin>>arr1[i];
    	cin>>n2;
    	int arr2[n2];
    	FOR(i,n2)	cin>>arr2[i];
    	set<int> common;
    	int i = 0, j= 0;
    	while(i < n1 && j < n2){
    		if(arr1[i] == arr2[j]){
    			common.insert(arr1[i]);
    			i++;
    			j++;
    		}else if(arr1[i] < arr2[j]){
    			i++;
    		}else{
    			j++;
    		}
    	}
    	int sizeArr = common.size();
    	ll dp1[sizeArr+1];
    	FOR(i,sizeArr+1)	dp1[i] = 0;
    	int k1 = 0;
    	for(int i = 0;i < n1; i++){
    		if(common.find(arr1[i]) != common.end()){
    			//this element is common
    			dp1[k1]+=arr1[i];
    			k1++;
    		}else{
    			//if it's not common
    			dp1[k1]+=arr1[i];
    		}
    	}
    	ll dp2[sizeArr+1];
    	FOR(i,sizeArr+1)	dp2[i] = 0;
    	int k2 = 0;
    	for(int i = 0;i < n2; i++){
    		if(common.find(arr2[i]) != common.end()){
    			//this element is common
    			dp2[k2]+=arr2[i];
    			k2++;
    		}else{
    			//if it's not common
    			dp2[k2]+=arr2[i];
    		}
    	}
    	ll ans = 0;
    	int size = (int)common.size();
    	for(int i = 0;i < size+1; i++){
    		ans = ans+max(dp1[i],dp2[i]);
    	}
    	// // set<int>::iterator it = ;
    	// int value = *(--common.end());

    	// ll sum1 = 0;
    	// for(int i = n1-1; i>= 0; i--){
    	// 	if(arr1[i] == value)
    	// 		break;
    	// 	sum1+=arr1[i];
    	// }
    	// // int value2 = *(--common.end());

    	// ll sum2 = 0;
    	// for(int i = n2-1; i>= 0; i--){
    	// 	if(arr2[i] == value)
    	// 		break;
    	// 	sum2+=arr2[i];
    	// }
    	// ll maxx = max(sum1,sum2);
    	cout<<ans<<endl;
    }
    return 0;
}
