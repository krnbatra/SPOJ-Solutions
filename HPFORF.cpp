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
const int MAXN = 505;
int visited[MAXN][MAXN];
char matrix[MAXN][MAXN];
int count1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
set<pair<int, int> > s;
int V[MAXN][MAXN];
void dfs(int a, int b){
	if(V[a][b] != INT_MIN && V[a][b] != INT_MAX){
		count1 += V[a][b];
		return;
	}
	visited[a][b] = 1;
	s.insert(make_pair(a,b));
	for(int i= 0;i < 4; i++){
		int x = a+dx[i];
		int y = b+dy[i];
		if(matrix[x][y] == '*'){
			count1++;
		}
	}
	for(int i= 0;i < 4; i++){
		int x = a+dx[i];
		int y = b+dy[i];
		if(!visited[x][y] && matrix[x][y] == '.'){
			dfs(x,y);
		}
	}
}

int main(){
    int t;
    si(t);
    while(t--){
    	int n,m,k;
    	si(n);
    	si(m);
    	si(k);
    	for(int i = 1;i <= n; i++){
    		for(int j = 1;j <= m; j++){
    			scanf(" %c", &matrix[i][j]);
    			V[i][j] = INT_MIN;
    			visited[i][j] = 0;
    		}
    	}
    	for(int i = 0;i < k; i++){
    		s.clear();
    		count1 = 0;
    		int a, b;
    		sdi(a,b);
    		dfs(a,b);
    		for(auto k : s){
    			V[k.first][k.second] = count1;
    		}
    		printf("%d\n", count1);
    	}
    }
    return 0;
}