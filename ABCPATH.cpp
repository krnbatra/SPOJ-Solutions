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

char matrix[55][55];
int visited[55][55];
int n, m;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};

bool isValid(int x, int y){
    if(x >= 0 && x < n && y >= 0 && y < m)
        return true;
    return false;
}


int maxx = 0;
void dfs(int x, int y, char current){
    // cout<<current<<endl;
    visited[x][y] = 1;
    char next = current+1;
    maxx = max(maxx, current-'A'+1);
    if(current == 'Z')
        return;
    for(int i = 0;i < 8; i++){
        int tempX = x+dx[i];
        int tempY = y+dy[i];
        if(isValid(tempX, tempY) && !visited[tempX][tempY] && matrix[tempX][tempY] == next){
            dfs(tempX, tempY, next);
        }
    }
}

int main(){
    io;
    int kase = 1;
    while(1){
        cin>>n>>m;
        if(n == 0 && m == 0)
            break;
        for(int i = 0;i < n; i++){
            for(int j = 0;j < m; j++){
                cin>>matrix[i][j];
            }
        }
        maxx = 0;
        for(int i = 0;i < n; i++){
            for(int j = 0;j < m; j++){
                if(matrix[i][j] == 'A'){
                    memset(visited, 0, sizeof(visited));
                    dfs(i,j, 'A');
                }
            }
        }
        cout<<"Case "<<kase<<": ";
        cout<<maxx<<endl;
        kase++;
    }
    return 0;
}
