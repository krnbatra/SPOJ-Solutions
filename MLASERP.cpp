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
char matrix[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
int sr, sc, er, ec, r, c;
int d[MAXN][MAXN];

// 0 means left, 1 means up, 2 means right, 3 means down


bool isValid(int x, int y){
    return (x >= 0 && x < r && y >= 0 && y < c);
}

int bfs(){
	int r1, c1, r2, c2, dir;
	queue<int> Q;
	memset(d, 0x3f, sizeof d);
	d[sr][sc] = -1;
	Q.push(sr); Q.push(sc);
	while(!Q.empty()){
		r1 = Q.front(); Q.pop();
		c1 = Q.front(); Q.pop();
		for(int i = 0;i < 4; i++){
			r2 = r1 + dx[i];
			c2 = c1 + dy[i];
			while(isValid(r2, c2) && matrix[r2][c2] != '*'){
				if(d[r2][c2] > d[r1][c1] + 1){
					d[r2][c2] = d[r1][c1] + 1;
					if(r2 == er && c2 == ec)	return d[r2][c2];
					Q.push(r2); Q.push(c2);
				}
				r2 += dx[i];
				c2 += dy[i];
			}
 		}
	}
	return d[er][ec];
}

int main(){
    io;
    cin >> c >> r;
    FOR(i,r){
        FOR(j,c){
            cin >> matrix[i][j];
        }
    }                                                              
    int cnt = 0;
    for(int i = 0;i < r; i++){
        for(int j = 0;j < c; j++){
            if(matrix[i][j] == 'C'){
                if(cnt == 0){
                	sr = i;sc = j;cnt++;
                }else{
                	er = i;ec = j;cnt++;
                }
            }
        }
    }
    // cout << sr << sp << sc << sp << er << sp << ec << endl;
    cout << bfs() << endl;
    return 0;
}