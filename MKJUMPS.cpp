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

const int MAXN = 15;
bool vis[MAXN][MAXN], matrix[MAXN][MAXN];
int ans;

int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

void dfs(int x, int y, int len){
    // cout << x << sp << y << sp << len << endl;
    ans = max(ans, len);
    vis[x][y] = 1;
    for(int i = 0; i < 8; i++){
        int tempX = x+dx[i];
        int tempY = y+dy[i];
        if(matrix[tempX][tempY] && !vis[tempX][tempY]){
            dfs(tempX, tempY, len+1);
            vis[tempX][tempY] = 0;
        }
    }
}



int main(){
    io;
    int kase = 1;
    while(1){
        ans = INT_MIN;
        FILL(vis, false);
        int numRows;
        cin >> numRows;
        if(numRows == 0)
            break;
        int maxx = INT_MIN;
        vector<ii> table;
        table.clear();
        for(int i = 1;i <= numRows; i++){
            int offset;
            cin >> offset;
            int cols;
            cin >> cols;
            maxx = max(maxx, cols+offset);
            table.pb({offset, cols});
        }
        for(int i = 0;i < MAXN; i++){
            for(int j = 0;j < MAXN; j++){
                matrix[i][j] = false;
            }
        }
        ll count = 0;
        int flag = 0;
        int startR = -1, startC = -1;
        for(int i = 0;i < numRows; i++){
            int start = table[i].F;
            int end = start+table[i].S;
            for(int j = start; j < end; j++){
                if(flag == 0){
                    startR = i;
                    startC = j;
                }
                flag = 1;
                matrix[i][j] = true;
                count++;
            }
        }
        dfs(startR, startC, 1);
        // for(int i = 0;i < numRows; i++){
        //     FOR(j, maxx)
        //         cout << matrix[i][j] << sp;
        //     cout << endl;
        // }
        cout << "Case " << kase << ", ";
        if(count-ans == 1){
            cout << "1 square can not be reached." << endl;
        }else{
            cout << count-ans << " squares can not be reached." << endl;
        }
        kase++;
    }
    return 0;
}