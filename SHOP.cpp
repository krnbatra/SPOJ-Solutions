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

const int MAXN = 27;
char matrix[MAXN][MAXN];
int w, h;
int vis[MAXN][MAXN];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

bool isValid(int x, int y){
    return (x >= 0 && x < h && y >= 0 && y < w && matrix[x][y] != 'X');
}

void bfs(int x, int y){
    queue<ii> Q;
    Q.push({x, y});
    vis[x][y] = 0;
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

            if(matrix[tempX][tempY] == 'D'){
                vis[tempX][tempY] = min(vis[tempX][tempY], vis[x][y]);
                continue;
            }
            // cout << tempX << sp << tempY << endl;
            if(vis[tempX][tempY] >= vis[x][y]+(matrix[tempX][tempY]-'0'))
                vis[tempX][tempY] = vis[x][y] + (matrix[tempX][tempY]-'0');
            else
                continue;

           
            Q.push({tempX, tempY});
        }
    }
}

int main(){
    io;
    while(1){
        cin >> w >> h;    
        if(w== 0 && h == 0)
            break;
        FOR(i,MAXN){
            FOR(j, MAXN){
                vis[i][j] = 1000;
            }
        }
        FOR(i, h){
            FOR(j, w){
                cin >> matrix[i][j];
            }
        }
        int flag = 0;
        FOR(i, h){
            FOR(j, w){
                if(matrix[i][j] == 'S'){
                    bfs(i, j);
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
        flag = 0;
        FOR(i, h){
            FOR(j, w){
                if(matrix[i][j] == 'D'){
                    cout << vis[i][j] << endl;
                    flag = 1;
                    break;
                }
            }
            if(flag)
                break;
        }
    }
    return 0;
}
