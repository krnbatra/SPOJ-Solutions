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

const int MAXN = 25;
char matrix[MAXN][MAXN];
bool vis[MAXN][MAXN];
bool res = false;
int r, c;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int stRow = -1,stCol = -1, enRow, enCol;

bool isValid(int x, int y){
    return (x >= 0 && x < r && y >= 0 && y < c);
}

void dfs(int a, int b){
    if(enRow == a && enCol == b)
        res = true;
    vis[a][b] = true;
    for(int i = 0;i < 4; i++){
        int x = a+dx[i];
        int y = b+dy[i];
        if(isValid(x,y) && matrix[x][y] == '.' && !vis[x][y]){
            dfs(x, y);
        }
    }
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        cin >> r >> c;
        FOR(i,r){
            FOR(j,c){
                cin >> matrix[i][j];
                vis[i][j] = false;
            }
        }
        //count dots in the edges
        set<pair<int, int> > S;
        res = false;
        int count = 0;
        if(r == 1){
            for(int i = 0;i < c; i++){
                if(matrix[0][i] == '.'){
                    count++;
                    if(count == 1){
                        stRow = 0;
                        stCol = i;
                    }
                    if(count == 2){
                        enRow = 0;
                        enCol = i;
                    }
                }
            }
        }else if(c == 1){
            for(int i = 0;i < r; i++){
                if(matrix[i][0] == '.'){
                    count++;
                    if(count == 1){
                        stRow = i;
                        stCol = 0;
                    }
                    if(count == 2){
                        enRow = i;
                        enCol = 0;
                    }
                }
            }
        }else{
            for(int i = 0;i < c; i++){
                if(matrix[0][i] == '.' && S.find({0, i}) == S.end()){
                    count++;
                    S.insert({0,i});
                    if(count == 1){
                        stRow = 0;
                        stCol = i;
                    }
                    if(count == 2){
                        enRow = 0;
                        enCol = i;
                    }
                }
                if(matrix[r-1][i] == '.' && S.find({r-1, i}) == S.end()){
                    count++;
                    S.insert({r-1, i});
                    if(count == 1){
                        stRow = r-1;
                        stCol = i;
                    }
                    if(count == 2){
                        enRow = r-1;
                        enCol = i;
                    }
                }
            }
            for(int i = 0;i < r; i++){
                if(matrix[i][0] == '.' && S.find({i, 0}) == S.end()){
                    count++;
                    S.insert({i, 0});
                    if(count == 1){
                        stRow = i;
                        stCol = 0;
                    }
                    if(count == 2){
                        enRow = i;
                        enCol = 0;
                    }
                }
                if(matrix[i][c-1] == '.' && S.find({i, c-1}) == S.end()){
                    count++;
                    S.insert({i, c-1});
                    if(count == 1){
                        stRow = i;
                        stCol = c-1;
                    }
                    if(count == 2){
                        enRow = i;
                        enCol = c-1;
                    }
                }
            }   
        }
        // cout << stRow << sp << stCol << sp << enRow << sp << enCol << endl;
        if(count != 2){
            cout << "invalid" << endl;
        }else{
            dfs(stRow, stCol);
            if(res)
                cout << "valid" << endl;
            else
                cout << "invalid" << endl;
        }
    }
    return 0;
}
