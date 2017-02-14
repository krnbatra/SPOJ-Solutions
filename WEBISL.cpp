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
#define FILL(arr, val)  memset(arr, val, sizeof(arr))
#define read(arr, n)    for(int i = 0;i < n; i++)cin>>arr[i];
#define sp ' '

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

const int MAXN = 1e5+5;
vector<int> adj[MAXN];
vector<int> adjReverse[MAXN];
int n;
bool vis[MAXN];
stack<int> stk;
vector<int> components[MAXN];
int number;
int ans[MAXN];

void dfs(int src){
    vis[src] = 1;
    FOR(i, adj[src].size()){
        if(!vis[adj[src][i]]){
            dfs(adj[src][i]);
        }
    }
    stk.push(src);
}

void dfsF(int src){
    vis[src] = 1;
    components[number].pb(src);
    FOR(i, adjReverse[src].size()){
        if(!vis[adjReverse[src][i]]){
            dfsF(adjReverse[src][i]);
        }
    }
}

void reverse(){
    for(int i = 0;i < n; i++){
        int st = i;
        for(int j = 0;j < adj[i].size(); j++){
            int to = adj[i][j];
            adjReverse[to].pb(st);
        }
    }
}

void scc(){
    while(!stk.empty()){
        int ele = stk.top();
        stk.pop();
        if(!vis[ele]){
            dfsF(ele);
            number++;
        }
    }
}

int main(){
    io;
    cin >> n;
    int m;
    cin >> m;
    for(int i = 0;i < m; i++){
        int a, b;
        cin >> a >> b;
        adj[a].pb(b);
    }
    for(int i = 0;i < n; i++){
        if(!vis[i]){
            dfs(i);
        }
    }
    FOR(i,n) vis[i] = false;
    reverse();
    scc();
    FOR(i,number){
        //find min in components[i];
        int minn = INT_MAX;
        for(int j = 0;j < components[i].size(); j++){
            minn = min(minn, components[i][j]);
        }
        for(int j = 0;j < components[i].size(); j++){
            ans[components[i][j]] = minn;
        }
    }
    FOR(i,n){
        cout << ans[i] << endl;
    }
    return 0;
}