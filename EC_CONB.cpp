/*My First Template :D*/
#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define INF 1000000000
#define MOD (ll)10000007
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
    int arr[1000];
    while(t--){
        int n;
        cin>>n;
        if(n&1){    //odd
            cout<<n<<endl;
        }else{
            int count = 0;
            while(n > 0){
                arr[count] = n%2;
                n/=2;
                count++;
            }
            count-=1;
            int i = 0;
            ll num = 0;
            while(count >= 0){
                if(arr[count]==1)
                    num+=(ll)exp(2, i);
                count--;
                i++;
            }
            cout<<num<<endl;
        }
    }
	return 0;
}