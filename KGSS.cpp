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

struct Tree{ int maxx, secondMax; };
int n;
Tree T[400005];
int arr[100005];

//build has time complexity of O(n)
void build(int node, int start,  int end){
  if(start > end)
    return;
  if(start==end){
    //Leaf node.
    T[node].maxx = arr[start];
    T[node].secondMax = INT_MIN;
    return;
  }
  //Recurse on the left child.
  int mid = (start+end)/2;
  build(2*node, start, mid);
  //Recurse on the right child.
  build(2*node+1, mid+1, end);
  //Internal node will have the sum of both its children.
  int left=  2*node, right = 2*node+1;
  if(T[left].maxx > T[right].maxx){
    T[node].maxx = T[left].maxx;
    T[node].secondMax = max(T[right].maxx, T[left].secondMax);
  }else{
    T[node].maxx = T[right].maxx;
    T[node].secondMax = max(T[left].maxx, T[right].secondMax);
  }
}

Tree query(int node, int start, int end, int l, int r){
  if(start > end || start > r || end < l){
    Tree temp;
    temp.maxx = INT_MIN;
    temp.secondMax = INT_MIN;
    return temp; 
  }
  
  if(l <= start && end <= r){
    // cout<<start<<' '<<end<<endl;
    Tree res = T[node];
    // ans = max(ans, res.maxx+res.secondMax);
    // cout<<ans<<endl;
    return res;
  }
  int mid = (start+end)/2;
  Tree left = query(2*node, start, mid, l, r);
  Tree right = query(2*node+1, mid+1, end, l, r);
  // ans = max(ans, left.maxx+right.maxx);
  // cout<<ans<<endl;
  Tree ans;
  if(left.maxx > right.maxx){
    ans.maxx = left.maxx;
    ans.secondMax = max(right.maxx, left.secondMax);
  }else{
    ans.maxx = right.maxx;
    ans.secondMax = max(left.maxx, right.secondMax);
  }
  return ans;
}

void updateIndex(int node, int start, int end,int idx, int value){
  if(start == end){
    T[node].maxx = value;
    T[node].secondMax = INT_MIN;
    return;
  }else{
    int mid = (start+end)/2;
    if(start <= idx && idx <= mid){
      updateIndex(2*node, start, mid, idx, value);
    }else{
      updateIndex(2*node+1, mid+1, end, idx, value);
    }
    int left=  2*node, right = 2*node+1;
    if(T[left].maxx > T[right].maxx){
      T[node].maxx = T[left].maxx;
      T[node].secondMax = max(T[right].maxx, T[left].secondMax);
    }else{
      T[node].maxx = T[right].maxx;
      T[node].secondMax = max(T[left].maxx, T[right].secondMax);
    }
  }
}

int main(){
    si(n);
    FOR(i, n) si(arr[i]);
    build(1, 0, n-1);
    int q;
    si(q);
    while(q--){
      char c;
      cin>>c;
      int a, b;
      sdi(a, b);
      if(c == 'U'){
        //update
        updateIndex(1, 0, n-1, a-1, b);
      }else{
        //query
        Tree ans = query(1, 0, n-1, a-1, b-1);
        printf("%d\n", ans.maxx+ans.secondMax);
      }
    }
    return 0;
}