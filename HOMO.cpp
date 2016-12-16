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
#define F first
#define S second

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

int flag = 0;
vector<pair<string, int> > table;
vector<int> V;
map<int, int> M;

const int MAXN = 1e5+5;
int tree1[4*MAXN];

//Time Complexity O(log(n))
int query1(int node, int start, int end, int l, int r){
  if(start > end || start > r || end < l)
    return 0; 
    //complete overlap
  if(l <= start && end <= r)
    return tree1[node];
    //partial overlap
  int mid = (start+end)/2;
  int left = node<<1, right = left+1;
  return query1(left, start, mid, l, r) + query1(right, mid+1, end, l, r);
}

//Time Complexity O(log(n))
void updateIndex1(int node, int start, int end,int idx, int value){
  if(start == end){
    tree1[node] = value;
  }else{
    int mid = (start+end)/2;
    int left = node<<1, right = left+1;
    if(start <= idx && idx <= mid){
      updateIndex1(left, start, mid, idx, value);
    }else{
      updateIndex1(right, mid+1, end, idx, value);
    }
    tree1[node] = tree1[left]+tree1[right];
  }
}


int tree2[4*MAXN];

//Time Complexity O(log(n))
int query2(int node, int start, int end, int l, int r){
  if(start > end || start > r || end < l)
    return INT_MIN; 
    //complete overlap
  if(l <= start && end <= r)
    return tree2[node];
    //partial overlap
  int mid = (start+end)/2;
  int left = node<<1, right = left+1;
  return max(query2(left, start, mid, l, r), query2(right, mid+1, end, l, r));
}

//Time Complexity O(log(n))
void updateIndex2(int node, int start, int end,int idx, int value){
  if(start == end){
    tree2[node] += value;
    if(tree2[node] == 0){
        flag = 1;
    }
  }else{
    int mid = (start+end)/2;
    int left = node<<1, right = left+1;
    if(start <= idx && idx <= mid){
      updateIndex2(left, start, mid, idx, value);
    }else{
      updateIndex2(right, mid+1, end, idx, value);
    }
    tree2[node] = max(tree2[left], tree2[right]);
  }
}


int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        string input;
        cin >> input;
        int n;
        cin >> n;
        pair<string, int> p;
        p.F = input;
        p.S =  n;
        table.pb(p);
        V.pb(n);
    }
    sort(V.begin(), V.end());
    int value = 0;
    for(int i = 0;i < V.size(); i++){
        if(M.find(V[i]) == M.end()){
            //not found
            M[V[i]] = value;
            value++;
        }
    }
    int n = M.size();
    for(int i = 0;i < table.size(); i++){
        string output = table[i].F;
        int idx = M[table[i].S];
        if(output == "insert"){
            updateIndex1(1, 0, n-1, idx, 1);
            updateIndex2(1, 0, n-1, idx, 1);
        }else{
            updateIndex2(1, 0, n-1, idx, -1);
            if(flag){
                updateIndex1(1, 0, n-1, idx, 0);
                flag = 0;
            }
            
        }
        int ans1 = query1(1, 0, n-1, 0, n-1);
        int ans2 = query2(1, 0, n-1, 0, n-1);
        int homo = 0, hetero = 0;
        if(ans1 >= 2){
            hetero = 1;
        }
        if(ans2 >= 2){
            homo = 1;
        }
        if(homo & hetero){
            cout << "both" << endl;
        }else if(homo){
            cout << "homo" << endl;
        }else if(hetero){
            cout << "hetero" << endl;
        }else{
            cout << "neither" << endl;
        }
    }
    return 0;
}
