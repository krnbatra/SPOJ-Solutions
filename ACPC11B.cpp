/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
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
int n;
int main(){
    cin>>t;
    while(t--){
        int n1, n2;
        cin>>n1;
        int arr1[n1];
        for(int i = 0;i < n1; i++){
            cin>>arr1[i];
        }
        cin>>n2;
        int arr2[n2];
        FOR(i, n2)  cin>>arr2[i];
        int min = INT_MAX;
        for(int i = 0;i < n1; i++){
            for(int j = 0;j < n2; j++){
                if(abs(arr1[i]-arr2[j]) < min){
                    min = abs(arr1[i]-arr2[j]);
                }
                
            }
            
        }
        cout<<min<<endl;
    }
	return 0;
}