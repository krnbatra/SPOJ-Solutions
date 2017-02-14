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

const int MAXN = 1e3+5;
vector<ii> topo;
bool vis[MAXN];
int in_degree[MAXN];    //in_degree[i] denotes the number of vertices that are still not added to topo and there is an edge from them to i.
int n;
vector<int> adj[MAXN];

void topoSort(){
    for(int i = 0;i < n; i++){
        for(int j = 0;j < adj[i].size(); j++){
            in_degree[adj[i][j]]++;
        }
    }
    set<ii> S;  //value and level
    for(int i = 0;i < n; i++){
        if(in_degree[i] == 0){
            S.insert({i, 1});
            vis[i] = true;
        }
    }
    // cout << Q.front() << endl;
    while(!S.empty()){
        ii curr = *(S.begin());
        S.erase(S.begin());
        // Q.pop();
        topo.pb(curr);
        int currValue = curr.F;
        int currLevel = curr.S;
        for(int j = 0;j < adj[currValue].size(); j++){
            if(!vis[adj[currValue][j]]){
                in_degree[adj[currValue][j]]--;
                if(in_degree[adj[currValue][j]] == 0){
                    S.insert({adj[currValue][j], currLevel+1});
                    vis[adj[currValue][j]] = 1;
                }
            }
        }
    }
}


int main(){
    io;
    int kase = 1;
    int t;
    cin >> t;
    while(t--){
        int m;
        cin >> n >> m;
        topo.clear();
        for(int i = 0;i < n; i++){
            vis[i] = false;
            in_degree[i] = 0;
            adj[i].clear();
        }
        for(int i = 1;i <= m; i++){
            int a, b;
            cin >> a >> b;
            adj[b].pb(a);
        }
        topoSort();
        cout << "Scenario #" << kase << ":" << endl;
        vector<ii> final;
        for(int i = 0;i < n; i++){
            final.pb({topo[i].S, topo[i].F});
        }
        sort(final.begin(), final.end());
        for(int i = 0;i < topo.size(); i++)
            cout << final[i].F << sp << final[i].S << endl;
        kase++;
    }
    return 0;
}
