/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
int n;
int BIT[MAXN+1];

void update(int idx, int val){
  while(idx <= MAXN){
    BIT[idx] += val;
    idx += idx&-idx;
  }
}

int query(int idx){
  int sum = 0;
  while(idx > 0){
    sum += BIT[idx];
    idx -= idx&-idx;
  }
  return sum;
}


int main(){
    io;
    cin >> n;
    string input[n];
    string rev[n];
    FOR(i,n){
      cin >> input[i];
      rev[i] = input[i];
      reverse(rev[i].begin(), rev[i].end());
    }
    sort(input, input+n);
    sort(rev, rev+n);
    ll ans = 0;
    unordered_map<string, int> M;
    FOR(i, n){
      reverse(input[i].begin(), input[i].end());
      M[rev[i]] = (i+1);
    }
    FOR(i, n){
      // cout << input[i] << endl;
      // cout << M[input[i]] << endl;
      ans += query((int)1e5+1) - query(M[input[i]]);
      // cout << ans << endl;
      update(M[input[i]], 1);
    }
    cout << ans << endl;  
    return 0;
}