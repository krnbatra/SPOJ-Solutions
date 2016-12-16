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

int t;
int n;
ll tree[400000];
ll arr[100000];

void build(int node, int start,  int end){
  if(start > end)
    return;
  if(start==end){
    //Leaf node.
    tree[node] = arr[start]*arr[start];
    return;
  }
  //Recurse on the left child.
  int mid = (start+end)>>1;
  int left = node<<1, right = left+1;
  build(left, start, mid);
  //Recurse on the right child.
  build(right, mid+1, end);
  //Internal node will have the sum of both its children.
  tree[node] = tree[left] + tree[right];
}


//Time Complexity O(log(n))
ll query(int node, int start, int end, int l, int r){
  if(start > end || start > r || end < l)
    return 0; 
    //complete overlap
  if(l <= start && end <= r)
    return tree[node];
    //partial overlap
  int mid = (start+end)/2;
  int left = node<<1, right = left+1;
  return query(left, start, mid, l, r) + query(right, mid+1, end, l, r);
}

//Worst case complexity is O(n)
void update1(int node, int start, int end, int l, int r, int value){
  //increase values from l to r by value
  //no overlap of the l to r segment on the current segment
  if(start > end || start > r || end < l)
    return;
  if(start==end){
    //Leaf node
    arr[start]+=value;
    tree[node] = arr[start]*arr[start];
    return;
  }
  int mid = (start+end)/2;
  int left = node<<1, right = left+1;
  update1(left, start, mid, l, r, value);
  update1(right, mid+1, end, l, r, value);
  tree[node] = tree[left] + tree[right]; 
}

void update2(int node, int start, int end, int l, int r, int value){
  //increase values from l to r by value
  //no overlap of the l to r segment on the current segment
  if(start > end || start > r || end < l)
    return;
  if(start==end){
    //Leaf node
    arr[start] = value;
    tree[node] = arr[start]*arr[start];
    return;
  }
  int mid = (start+end)/2;
  int left = node<<1, right = left+1;
  update2(left, start, mid, l, r, value);
  update2(right, mid+1, end, l, r, value);
  tree[node] = tree[left] + tree[right]; 
}



int main(){
    io;
    cin >> t;
    int kase = 1;
    while(t--){
      memset(arr, 0, sizeof(arr));
      memset(tree, 0, sizeof(tree));
      cin >> n;
      int q;
      cin >> q;
      for(int i = 0;i < n; i++){
        cin >> arr[i];
      }
      build(1, 0, n-1);
      int flag = 0;
      while(q--){
        int type;
        cin >> type;
        if(type == 0){
          int st, end, x;
          cin >> st >> end >> x;
          update2(1, 0, n-1, st-1, end-1, x);
        }else if(type == 1){
          int st, end, x;
          cin >> st >> end >> x;
          update1(1, 0, n-1, st-1, end-1, x);
        }else{
          int st, end;
          cin >> st >> end;
          if(flag == 0){
            cout << "Case " << kase << ":" << endl;
            flag = 1;
          }
          cout << query(1, 0, n-1, st-1, end-1) << endl;
        }
      }
      kase++;
    }
    return 0;
}
