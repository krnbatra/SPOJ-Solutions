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
#define sd(n)  scanf("%d", &n) 

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
 
int t;
int main(){
    sd(t);
    while(t--){
        int n;
        sd(n);
        string input;
        cin>>input;
        int sz = input.size();
        int count[8] = {0};
        for(int i = 0;i < sz-2; i++){
            if(input.substr(i, 3)=="TTT"){
                count[0]++;
            }else if(input.substr(i, 3)=="TTH"){
                count[1]++;
            }else if(input.substr(i, 3)=="THT"){
                count[2]++;
            }else if(input.substr(i, 3)=="THH"){
                count[3]++;
            }else if(input.substr(i, 3)=="HTT"){
                count[4]++;
            }else if(input.substr(i, 3)=="HTH"){
                count[5]++;
            }else if(input.substr(i, 3)=="HHT"){
                count[6]++;
            }else if(input.substr(i, 3)=="HHH"){
                count[7]++;
            }
        }
        cout<<n<<' ';
        FOR(i, 8)   cout<<count[i]<<' ';
        cout<<endl;
    }
	return 0;
}