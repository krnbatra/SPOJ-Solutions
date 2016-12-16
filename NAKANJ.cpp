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

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int visited[8][8];

bool isValid(int x, int y){
    return (x >= 0 && x < 8 && y >= 0 && y < 8);
}

int bfs(int x1, int y1, int x2, int y2){
    queue<pair<int, ii > > Q;
    Q.push({0,{x1,y1}});
    visited[x1][y1] = 1;
    while(!Q.empty()){
        pair<int, ii >  p = Q.front();
        Q.pop();
        if(p.S.F == x2 && p.S.S == y2)
            return p.F;
        int currX = p.S.F;
        int currY = p.S.S;
        int currCount = p.F;
        for(int i = 0;i < 8; i++){
            if(isValid(currX+dx[i], currY+dy[i]) && !visited[currX+dx[i]][currY+dy[i]]){
                Q.push({currCount+1,{currX+dx[i], currY+dy[i]}});
                visited[currX+dx[i]][currY+dy[i]] = 1;
            }
        }
    }
    return -1;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        memset(visited, 0, sizeof(visited));
        string start;
        string end;
        cin >> start >> end;
        int startRow = start[1]-'1';
        int startCol = start[0]-'a';
        int endRow = end[1]-'1';
        int endCol = end[0]-'a';
        int ans = bfs(startRow, startCol, endRow, endCol);
        cout << ans << endl;
    }   
    return 0;
}