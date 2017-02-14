/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e4+5;
vector<ii> adj[MAXN], adjRev[MAXN];   //{dist, adjacent_vertex}
ll dist[MAXN];
ll distRev[MAXN];
bool vis[MAXN];
int n, m, k;

void init(){
    FORE(i,1,n){adj[i].clear();dist[i]=MOD;vis[i]=false;distRev[i]=MOD;adjRev[i].clear();}
}

void dijkstra(int st, int finish){
    dist[st] = 0;
    multiset<ii> S; //acts as min priority queue.
    S.insert({0,st});    //{dist, vertex}.
    while(!S.empty()){
        ii p = *(S.begin());
        S.erase(S.begin());
        int currVertex = p.S;
        int weight = p.F;
        if(vis[currVertex])     //according to the algorithm the distance to the visited vertices is minimal.
            continue;
        vis[currVertex] = true;
        for(int i = 0;i < adj[currVertex].size(); i++){
            int adjacent_vertex = adj[currVertex][i].S;
            int weight = adj[currVertex][i].F;
            if(dist[currVertex] + weight < dist[adjacent_vertex]){
                dist[adjacent_vertex] = dist[currVertex] + weight;
                S.insert({dist[adjacent_vertex], adjacent_vertex}); //a vertex can be pushed multiple times do not mark vis as true while pushing instead mark it while popping out.
            }
        }
    }
}

void dijkstraRev(int st, int finish){
    distRev[st] = 0;
    multiset<ii> S; //acts as min priority queue.
    S.insert({0,st});    //{dist, vertex}.
    while(!S.empty()){
        ii p = *(S.begin());
        S.erase(S.begin());
        int currVertex = p.S;
        int weight = p.F;
        if(vis[currVertex])     //according to the algorithm the distance to the visited vertices is minimal.
            continue;
        vis[currVertex] = true;
        for(int i = 0;i < adjRev[currVertex].size(); i++){
            int adjacent_vertex = adjRev[currVertex][i].S;
            int weight = adjRev[currVertex][i].F;
            if(distRev[currVertex] + weight < distRev[adjacent_vertex]){
                distRev[adjacent_vertex] = distRev[currVertex] + weight;
                S.insert({distRev[adjacent_vertex], adjacent_vertex}); //a vertex can be pushed multiple times do not mark vis as true while pushing instead mark it while popping out.
            }
        }
    }
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	int st, finish;
        cin >> n >> m >> k >> st >> finish;
        init();
        FOR(i,m){
            int a, b, w;
            cin >> a >> b >> w;
            adj[a].pb({w, b});
            adjRev[b].pb({w, a});
        }
        dijkstra(st, finish);
        memset(vis, false, sizeof vis);
        dijkstraRev(finish, st);
        ll ans = MOD;
        FOR(i, k){
        	int a, b, l;
        	cin >> a >> b >> l;
        	ans = min(ans, min(dist[finish], min(dist[a]+l+distRev[b], dist[b]+l+distRev[a]) ));
        }
        if(ans != MOD)
        	cout << ans << endl;
        else
        	cout << -1 << endl;
    }
    return 0;
}