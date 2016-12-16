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
const int MAXN = 105;
char matrix[MAXN][MAXN];
int visited[MAXN][MAXN];
int n,m;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0};
int minn = INT_MAX;
bool isValid(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m)
		return true;
	return false;
}
void dfs(int a, int b, int count){
	// cout<<a<<' '<<b<<' '<<count<<endl;
	for(int i = 0;i < 4; i++){
		int x = a+dx[i];
		int y = b+dy[i];
		// if(isValid(x,y))
		// 	cout<<matrix[x][y]<<endl;
		if(isValid(x,y) && matrix[x][y] == '#'){
			// cout<<x<<' '<<y<<endl;
			minn = min(minn, count+1);
			// cout<<minn<<endl;
		}
	}
	visited[a][b] = 1;
	for(int i = 0;i < 4; i++){
		int x = a+dx[i];
		int y = b+dy[i];
		if(isValid(x,y) && matrix[x][y] == 'O' && !visited[x][y]){
			dfs(x,y,count+1);
			visited[x][y] = 0;
		}
	}
}

int main(){
    int t;
    si(t);
    while(t--){
    	minn = INT_MAX;
    	memset(visited, 0, sizeof(visited));
    	sdi(n,m);
    	FOR(i,n){
    		FOR(j,m){
    			scanf(" %c", &matrix[i][j]);
    		}
    	}
    	for(int i = 0;i < n; i++){
    		for(int j = 0;j < m; j++){
    			if(matrix[i][j] == '$'){
    				dfs(i,j,0);
    			}
    		}
    	}
    	if(minn == INT_MAX)
    		minn = -1;
    	cout<<minn<<endl;
    }
    return 0;
}
