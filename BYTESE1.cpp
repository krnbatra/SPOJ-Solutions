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

const int MAXN = 105;
int matrix[MAXN][MAXN];
int w, h;
int vis[MAXN][MAXN];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int destX, destY;

bool isValid(int x, int y){
    return (x >= 0 && x < h && y >= 0 && y < w);
}

void bfs(int x, int y){
    queue<ii> Q;
    Q.push({x, y});
    vis[x][y] = matrix[x][y];
    while(!Q.empty()){
        ii P = Q.front();
        Q.pop();
        int x = P.F;
        int y = P.S;
        // cout << x << sp << y << sp << vis[x][y] << endl;
        for(int i = 0;i < 4; i++){
            int tempX = x+dx[i];
            int tempY = y+dy[i];
            
            if(!isValid(tempX, tempY)){
                continue;
            }

            if(tempX == destX && tempY == destY){
                vis[tempX][tempY] = min(vis[tempX][tempY], vis[x][y]+matrix[tempX][tempY]);
                continue;
            }
            // cout << tempX << sp << tempY << endl;
            if(vis[tempX][tempY] > vis[x][y]+matrix[tempX][tempY])
                vis[tempX][tempY] = vis[x][y] + matrix[tempX][tempY];
            else
                continue;

            Q.push({tempX, tempY});
        }
    }
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        cin >> h >> w;    
        // FOR(i,MAXN){
        //     FOR(j, MAXN){
        //         vis[i][j] = 1000;
        //     }
        // }
        FOR(i, h){
            FOR(j, w){
                cin >> matrix[i][j];
                vis[i][j] = 1000;
            }
        }
        int time;
        cin >> destX >> destY >> time;
        destX--;destY--;
        bfs(0, 0);
        if(vis[destX][destY] <= time){
            cout << "YES" << endl;
            cout << time-vis[destX][destY] << endl;
        }else
            cout << "NO" << endl;
    }
    return 0;
}
