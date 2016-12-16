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


vector<int> boy, girl;
int lcs_dp(){
  int table[girl.size()+1][boy.size()+1]; //table[i][j] contains lcs of input1[0...i-1], input2[0.....j-1]
  //table[i][j] lcs of first i integers of girl and first j integers of boy.
  memset(table, 0, sizeof(table));
  for(int i = 0;i <= girl.size(); i++){
    for(int j = 0;j <= boy.size(); j++){
      if(i == 0 || j == 0){
        table[i][j] = 0;
      }
      else if(girl[i-1] == boy[j-1])
        table[i][j] = 1+table[i-1][j-1]; 
      else
        table[i][j] = max(table[i-1][j], table[i][j-1]);
    }   
  }
  // for(int i = 0;i <= girl.size(); i++){
  //   for(int j = 0;j <= boy.size(); j++){
  //       cout<<table[i][j]<<' ';
  //   }
  //   cout<<endl;
  // }
  return table[girl.size()][boy.size()];
}

int main(){
    int t;
    si(t);
    while(t--){
        girl.clear();
        int n;
        while(1){
            si(n);
            if(n == 0)
                break;
            girl.pb(n);
        }
        int maxx = INT_MIN;
        while(1){
            si(n);
            if(n == 0){
                break;
            }
            boy.pb(n);
            while(1){
                cin>>n;
                if(n == 0){
                    break;
                }
                boy.pb(n);
            }   
            maxx = max(maxx, lcs_dp());
            boy.clear();
        }
        
        cout<<maxx<<endl;
    }
    return 0;
}
