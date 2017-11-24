#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define GC getchar_unlocked()
int scan()
{
    int ret=0,sign=1;
    int ip=GC;
    for(;ip<'0'||ip>'9';ip=GC);
    for(;ip>='0'&&ip<='9';ip=GC)
        ret=ret*10+ip-'0';
    return (ret*sign);
}


const int maxnodes = 5010;
const int _INF = 1000000000;
int nodes, src, dest;
int dist[maxnodes], work[maxnodes];

struct Edge {
    int to, rev;
    int f, cap;
};

vector<Edge> g[maxnodes];

// Adds bidirectional edge
void addEdge(int s, int t, int cap){
    Edge a = {t, (int)g[t].size(), 0, cap};
    Edge b = {s, (int)g[s].size(), 0, cap};
    g[s].push_back(a);
    g[t].push_back(b);
}

bool dinic_bfs() {
    fill(dist, dist + nodes, -1);
    dist[src] = 0;
    queue<int> Q;
    Q.push(src);
    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();
        for (int j = 0; j < (int) g[u].size(); j++) {
            Edge &e = g[u][j];
            int v = e.to;
            if (dist[v] < 0 && e.f < e.cap) {
                dist[v] = dist[u] + 1;
                Q.push(v);
            }
        }
    }
    return dist[dest] >= 0;
}

int dinic_dfs(int u, int f) {
    if (u == dest)
        return f;
    for (int &i = work[u]; i < (int) g[u].size(); i++) {
        Edge &e = g[u][i];
        if (e.cap <= e.f) continue;
        int v = e.to;
        if (dist[v] == dist[u] + 1) {
            int df = dinic_dfs(v, min(f, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
    }
    return 0;
}

ll maxFlow(int _src, int _dest) {
    src = _src;
    dest = _dest;
    ll result = 0;
    int delta = 0;
    while (dinic_bfs()) {
        fill(work, work + nodes, 0);
        while ((delta = dinic_dfs(src, _INF)))
            result += delta;
    }
    return result;
}

int main()
{
   
    int m,u,v,c;
    nodes=scan();
    m=scan();
    while(m--)
    {
        u=scan();
        v=scan();
        --u,--v;
        c=scan();
        addEdge(u,v,c);
    }
    cout<<maxFlow(0,nodes-1)<<"\n";
    return 0;
}
