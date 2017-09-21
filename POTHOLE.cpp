/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 2e2+5;
vector<int> adj[MAXN];
int residual[MAXN][MAXN], from[MAXN], n;
bool vis[MAXN];

int find_path(int src, int dest){
    memset(vis, false, sizeof vis);
    memset(from, -1, sizeof from);
    queue<int> Q;
    Q.push(src);
    vis[src] = true;
    bool done = false;
    while(!Q.empty()){
        int u = Q.front(); Q.pop();
        for(auto v : adj[u]){
            if(!vis[v] && residual[u][v] > 0){
                Q.push(v);
                vis[v] = true;
                from[v] = u;
                if(v == dest){
                    done = true;
                    break;
                }
            }
        }
        if(done)    break;
    }
    // find min from path
    int current = dest, path_capacity = INT_MAX;
    while(from[current] != -1){
        int parent = from[current];
        path_capacity = min(path_capacity, residual[parent][current]);
        current = parent;
    }
    // update residual
    current = dest;
    while(from[current] != -1){
        int parent = from[current];
        residual[parent][current] -= path_capacity;
        residual[current][parent] += path_capacity;
        current = parent;
    }
    if(path_capacity == INT_MAX)
        return 0;
    return path_capacity;
}

int max_flow(){
    int res = 0;
    while(1){
        int path_capacity = find_path(1, n);
        if(path_capacity == 0)
            break;
        res += path_capacity;
    }
    return res;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        for(int i = 1;i < MAXN; i++)
            adj[i].clear();
        memset(residual, 0, sizeof residual);
        cin >> n;
        for(int i = 1;i < n; i++){
            int m;
            cin >> m;
            int a = i;
            for(int j = 0;j < m; j++){
                int b;
                cin >> b;
                adj[a].push_back(b);
                adj[b].push_back(a);
                if(a == 1 || b == n)
                    residual[a][b] = 1;
                else
                    residual[a][b] = n;
            }
        }
        cout << max_flow() << endl;
    }
    return 0;
}