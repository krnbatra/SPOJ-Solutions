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


const int MAXN = 9e3+5;
vector<int> adj[MAXN], adjReverse[MAXN];
int components[MAXN];   //components[i] indicates to which component i belongs to.
int reachability[MAXN];
int in_degree[MAXN];
int n;
bool vis[MAXN];
stack<int> stk;
int numberOfComponents;
int ver = 0;
void initialize(){
    FORE(i,1,n){vis[i] = false;adj[i].clear();adjReverse[i].clear();in_degree[i]=0;components[i]=0;numberOfComponents=0;reachability[i]=0;ver=0;}
}

void dfs(int src){
    vis[src] = 1;
    FOR(i, adj[src].size()){
        if(!vis[adj[src][i]]){
            dfs(adj[src][i]);
        }
    }
    //ordering the vertices according to the finish times, the vertex finishing last will be at the top of stack.
    stk.push(src);
}

void dfsF(int src){
    vis[src] = 1;
    components[src] = numberOfComponents;
    FOR(i, adjReverse[src].size()){
        if(!vis[adjReverse[src][i]]){
            dfsF(adjReverse[src][i]);
        }
    }
}

void scc(){
    while(!stk.empty()){
        int ele = stk.top();
        stk.pop();
        if(!vis[ele]){
            numberOfComponents++;
            dfsF(ele);
        }
    }
}

void dfsCheck(int src){
    vis[src] = 1;
    ver++;
    // cout << ver << sp << src << endl;
    for(int i = 0;i < adj[src].size(); i++){
        // cout << adj[src][i] << sp << vis[adj[src][i]] << endl;
        if(!vis[adj[src][i]]){
            dfsCheck(adj[src][i]);
        }
    }
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int m;
        cin >> m;
        initialize();
        FOR(i,m){
            int a, b;
            cin >> a >> b;
            adj[b].pb(a);
            adjReverse[a].pb(b);
        }
        for(int i = 1;i <= n; i++){
            if(!vis[i])
                dfs(i);
        }
        FORE(i,1,n) vis[i] = false;
        scc();
        //DAG of SCC is formed calculate indegree of components
        for(int i = 1;i <= n; i++){
            for(int j = 0;j < adj[i].size(); j++){
                int adjacentVertex = adj[i][j];
                if(components[i] != components[adjacentVertex]){
                    in_degree[components[adjacentVertex]]++;
                }
            }
        }
        int maxx = INT_MIN;
        FORE(i,1,n){
            if(in_degree[components[i]] == 0){
                memset(vis, false, sizeof(vis));
                dfsCheck(i);
                reachability[i] = ver;
                // cout << i << sp << ver << endl;
                ver = 0;
                maxx = max(maxx, reachability[i]);

            }
        }
        FORE(i,1,n){
            if(reachability[i] == maxx){
                cout << i << sp;
            }
        }
        cout << endl;
    }
    return 0;
}
