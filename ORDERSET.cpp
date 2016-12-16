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

vector<pair<char, int> > table;
unordered_map<int,int> M;
vector<int> V;
vector<int> reverseMapping;
const int MAXN = 2e5+5;

int tree[4*MAXN];
int arr[MAXN];

//build has time complexity of O(n)
void build(int node, int start,  int end){
  if(start > end)
    return;
  if(start==end){
    //Leaf node.
    tree[node] = arr[start];
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
int query(int node, int start, int end, int l, int r){
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

//Time Complexity O(log(n))
void updateIndex(int node, int start, int end,int idx, int value){
  if(start == end){
    tree[node] = value;
  }else{
    int mid = (start+end)/2;
    int left = node<<1, right = left+1;
    if(start <= idx && idx <= mid){
      updateIndex(left, start, mid, idx, value);
    }else{
      updateIndex(right, mid+1, end, idx, value);
    }
    tree[node] = tree[left]+tree[right];
  }
}

int main(){
    // io;
    int q;
    si(q);
    while(q--){
        pair<char,int> p;
        scanf(" %c", &p.first);
        si(p.second);
        V.pb(p.second);
        table.pb(p);
    }
    sort(V.begin(), V.end());
    reverseMapping.pb(V[0]);
    for(int i = 1;i < V.size(); i++){
        if(V[i] != V[i-1]){
            reverseMapping.pb(V[i]);
        }
    }

    int idx = 0;
    for(int i = 0;i < V.size(); i++){
        if(M.find(V[i]) == M.end()){
            //not found in map
            M[V[i]] = idx;
            idx++;
        }
    }
    int n = M.size();
    for(int i = 0;i < table.size(); i++){
        char c = table[i].first;
        int mapp = table[i].second;
        if(c == 'I'){
            updateIndex(1, 0, n-1, M[mapp], 1);
        }else if(c == 'D'){
            updateIndex(1, 0, n-1, M[mapp], 0);
        }else if(c == 'C'){
            cout << query(1, 0, n-1, 0, M[mapp]-1) << endl;
        }else{
            //check for validity;
            int qAll = query(1, 0, n-1, 0, n-1);
            if(qAll < mapp){
                cout << "invalid" << endl;
            }else{
                int lo = 0;
                int hi = n-1;
                while(lo < hi){
                    int mid = (lo+hi)/2;
                    //find number of elements present in lo to mid
                    int q1 = query(1, 0, n-1, lo, mid);
                    if(q1 < mapp){
                        //find in upper half
                        lo = mid+1;
                        mapp = mapp-q1;
                    }else{
                        hi = mid;
                    }
                }
                //find inverse mapping of lo
                // for(int i = 0;i < V.size(); i++){
                //     if(M[V[i]] == lo){
                //         cout << V[i] << endl;
                //         break;
                //     }
                // }
                cout << reverseMapping[lo] << endl;
            }
        }
    }
    return 0;
}
