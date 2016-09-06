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
#define FOR(i, n)  for(int i = 0;i < n; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
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

int n;
const int MAXN = 1e5+5;
// int arr[MAXN];
ll tree[4*MAXN];
ll lazy[4*MAXN];

//do lazy updates
void update(int node, int start, int end, int l, int r, int value){
  if(lazy[node] != 0){
    tree[node] += (ll)(end-start+1)*lazy[node];
    if(start!=end){
      lazy[2*node] += lazy[node];
      lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > end || start > r || end < l){
    return;
  }
  if(l <= start && end <= r){
    tree[node] += (ll)(end-start+1)*value;
    if(start != end){
      lazy[2*node]+=value;
      lazy[2*node+1]+=value;
    }
    return;
  }
  int mid = (start+end)>>1;

  int left = node<<1, right = left+1;

  update(left, start, mid, l, r, value);
  update(right, mid+1, end, l, r, value);
  tree[node] = tree[left] + tree[right];
}

//query Lazy
ll query(int node, int start, int end, int l, int r){
  if(lazy[node] != 0){
    tree[node] += (ll)(end-start+1)*lazy[node];
    if(start!=end){
      lazy[2*node] += lazy[node];
      lazy[2*node+1] += lazy[node];
    }
    lazy[node] = 0;
  }
  if(start > end || start > r || end < l)
    return 0;
  if(l <= start && end <= r){
    return tree[node];
  }
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  return (ll)query(left, start, mid, l, r) + (ll)query(right, mid+1, end, l, r);
}

int main(){
    int t;
    si(t);
    while(t--){
      si(n);
      int q;
      si(q);
      memset(lazy, 0, sizeof(lazy));
      memset(tree, 0, sizeof(tree));
      while(q--){
        int type;
        si(type);
        int l, r;
        sdi(l,r);
        if(type==0){
          int value;
          si(value);
          update(1, 0, n-1, l-1, r-1, value);
        }else{
          printf("%lld\n", query(1, 0, n-1, l-1, r-1));
        }
      }
    }
    return 0;
}