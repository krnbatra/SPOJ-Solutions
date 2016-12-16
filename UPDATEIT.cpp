/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define INF 1000000000
#define MOD (ll)1000000007
#define pb 	push_back
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
 
int t;
int main(){
    cin>>t;
    while(t--){
        int n, u;
        // cin>>n>>u;
        scanf("%d%d", &n, &u);
        ll arr[n];
        FOR(i, n)   arr[i] = 0;
        ll diff[n+1];
        FOR(i, n+1) diff[i] = 0;
        for(int i = 0;i < u; i++){
            int l, r, val;
            // cin>>l>>r>>val;
            scanf("%d%d%d", &l, &r, &val);
            diff[l]+=val;
            diff[r+1]-=val;
        }
        arr[0] = diff[0];
        for(int i = 1;i < n; i++){
            arr[i] = arr[i-1]+diff[i];
        }
        int q;
        // cin>>q;
        scanf("%d", &q);
        FOR(i, q){
            int num;
            // cin>>num;
            scanf("%d", &num);
            // cout<<arr[num]<<endl;
            printf("%d\n", arr[num]);
        }
    }
	return 0;
}