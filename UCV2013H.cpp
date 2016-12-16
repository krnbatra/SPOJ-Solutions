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

const int MAXN = 255;
int matrix[MAXN][MAXN];
int visited[MAXN][MAXN];
int rows, cols;

int dx[4] = {0,-1, 0, 1};
int dy[4] = {-1,0, 1, 0};

bool isValid(int x, int y){
    return (x >= 0 && x < rows && y >= 0 && y < cols);
}

int bfs(int x, int y){
    int res = 0;
    queue<ii> Q;
    Q.push({x,y});
    res++;
    while(!Q.empty()){
        ii p = Q.front();
        visited[p.F][p.S] = 1;
        Q.pop();
        for(int i= 0;i < 4; i++){
            if(isValid(p.F+dx[i],p.S+dy[i]) && !visited[p.F+dx[i]][p.S+dy[i]] && matrix[p.F+dx[i]][p.S+dy[i]] == 1){
                Q.push({p.F+dx[i], p.S+dy[i]});
                visited[p.F+dx[i]][p.S+dy[i]] = 1;
                res++;
            }
        }
    }
    return res;
}

int main(){
    io;
    while(1){
        memset(visited, 0, sizeof(visited));
        cin >> rows >> cols;
        if(rows == 0 && cols == 0)
            break;
        FOR(i,rows){
            FOR(j,cols){
                cin >> matrix[i][j];
            }
        }
        int ans = 0;
        map<int, int> M;
        FOR(i,rows){
            FOR(j,cols){
                if(matrix[i][j] == 1 && !visited[i][j]){
                    ans++;
                    int res = bfs(i,j);
                    if(M.find(res) == M.end()){
                        M[res] = 1;
                    }else{
                        int count = M[res];
                        M[res] = count+1;
                    }
                }
            }
        }
        cout << ans << endl;
        for(auto p : M){
            cout << p.F << ' ' << p.S << endl;
        }
    }
    return 0;
}
