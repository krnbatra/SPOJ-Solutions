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
ll arr[MAXN];
ll tree[4*MAXN];

void build(int node, int start, int end){
  if(start > end)
    return;
  if(start == end){
    tree[node] = arr[start];
    return;
  }
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  build(left, start, mid);
  build(right, mid+1, end);
  tree[node] = tree[left]+tree[right];
}

//query
ll query(int node, int start, int end, int l, int r){
  if(start > end || start > r || end < l)
      return 0;
  if(l <= start && end <= r)
    return tree[node];
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  return query(left, start, mid, l, r)+query(right, mid+1, end, l, r);
}

//update
void update(int node, int start, int end, int l, int r){
  ll segmentSum = (end-start+1);
  if(segmentSum == tree[node])
    return;
  if(start > end || start > r || end < l)
    return;
  if(start == end){
    tree[node] = sqrt(tree[node]);
    return;
  }
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  update(left, start, mid, l, r);
  update(right, mid+1, end, l, r);
  tree[node] = tree[left]+tree[right];
}

int main(){
    int kase = 0;
    while(scanf("%d", &n) != EOF){
      kase++;
      FOR(i, n) scanf("%lld", &arr[i]);
      build(1, 0, n-1);
      int q;
      si(q);
      printf("Case #%d:\n", kase);
      while(q--){
        int type;
        si(type);
        int l, r;
        sdi(l, r);
        if(l > r){
          int temp = l;
          l = r;
          r = temp;
        }
        if(type == 0){
          //update
          update(1, 0, n-1, l-1, r-1);
        }else{
          //query
          printf("%lld\n", query(1, 0, n-1, l-1, r-1));
        }
      }
      printf("\n");
    }
    return 0;
}