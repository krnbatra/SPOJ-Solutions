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

const int MAXN = 1e2+5;
vector<int> topo;
bool vis[MAXN];
int in_degree[MAXN];    //in_degree[i] denotes the number of vertices that are still not added to topo and there is an edge from them to i.
int n;
vector<int> adj[MAXN];

void topoSort(){
    for(int i = 1;i <= n; i++){
        for(int j = 0;j < adj[i].size(); j++){
            in_degree[adj[i][j]]++;
        }
    }
    set<int> S;  
    for(int i = 1;i <= n; i++){
        if(in_degree[i] == 0){
            S.insert(i);
            vis[i] = true;
        }
    }
    // cout << Q.front() << endl;
    while(!S.empty()){
        int curr = *(S.begin());
        S.erase(S.begin());
        // Q.pop();
        topo.pb(curr);
        for(int j = 0;j < adj[curr].size(); j++){
            if(!vis[adj[curr][j]]){
                in_degree[adj[curr][j]]--;
                if(in_degree[adj[curr][j]] == 0){
                    S.insert(adj[curr][j]);
                    vis[adj[curr][j]] = 1;
                }
            }
        }
    }
}


int main(){
    io;
    cin >> n;
    int m;
    cin >> m;
    for(int i = 1;i <= m; i++){
        int a;
        cin >> a;
        int num;
        cin >> num;
        for(int j = 0;j < num; j++){
            int b;
            cin >> b;
            adj[b].pb(a);
        }
    }
    topoSort();
    for(int i = 0;i < topo.size(); i++)
        cout << topo[i] << sp;
    cout << endl;
    return 0;
}
