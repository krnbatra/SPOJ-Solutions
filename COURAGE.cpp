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
struct Tree{ ll sum, minn; };
int arr[MAXN];
Tree T[4*MAXN];

void build(int node, int start, int end){
  if(start > end)
    return;
  if(start == end){
    T[node].minn = T[node].sum = arr[start];
    return;
  }
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  build(left, start, mid);
  build(right, mid+1, end);
  T[node].sum = T[left].sum + T[right].sum;
  T[node].minn = min(T[left].minn, T[right].minn);
}

//point update
void update(int node, int start, int end, int idx, int value){
  if(start > end)
    return;
  if(start == end){
    T[node].minn += (ll)value;
    T[node].sum = T[node].minn;
    return;
  }
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  if(idx <= mid){
    update(left, start, mid, idx, value);
  }
  else if(idx > mid){
    update(right, mid+1, end, idx, value);
  }
  T[node].sum = T[left].sum + T[right].sum;
  T[node].minn = min(T[left].minn, T[right].minn);
}

//query
Tree query(int node, int start, int end, int l, int r){
  if(start > end || start > r || end < l){
    Tree res;
    res.sum = 0;
    res.minn = INT_MAX;
    return res;
  }
  if(l <= start && end <= r){
    return T[node];
  }
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  Tree leftRet = query(left, start, mid, l, r);
  Tree rightRet = query(right, mid+1, end, l, r);
  Tree res;
  res.sum = leftRet.sum+rightRet.sum;
  res.minn = min(leftRet.minn, rightRet.minn);
  return res;
}

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    si(n);
    FOR(i, n) si(arr[i]);
    build(1, 0, n-1);
    int q;
    si(q);
    while(q--){
      char str[10];
      scanf("%s", str);
      int l, r;
      sdi(l,r);
      if(str[0] == 'C'){
        Tree res = query(1, 0, n-1, l, r);
        printf("%lld\n", res.sum-res.minn);
      }else if(str[0] == 'E'){
        update(1, 0, n-1, r, -l);
      }else{
        update(1, 0, n-1, r, l);
      }
    }
    return 0;
}