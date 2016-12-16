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
	for(int i = 0;i < 4; i++){
		int x = a+dx[i];
		int y = b+dy[i];
		if(isValid(x,y) && matrix[x][y] == '#'){
			minn = min(minn, count+1);
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
	io;
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    while(k--){
    	int mx, my, c1x,c1y, c2x,c2y;
    	cin>>mx>>my>>c1x>>c1y>>c2x>>c2y;
    	int fo = abs(mx-1);
    	int so = abs(n-mx);
    	int to = abs(my-1);
    	int fouro = abs(my-m);

    	int foc1 = abs(c1x-1)+abs(c1y-my);
    	int soc1 = abs(n-c1x)+abs(c1y-my);
    	int toc1 = abs(c1y-1)+abs(c1x-mx);
    	int fouroc1 = abs(c1y-m)+abs(c1x-mx);

    	int foc2 = abs(c2x-1)+abs(c2y-my);
    	int soc2 = abs(n-c2y)+abs(c2y-my);
    	int toc2 = abs(c2y-1)+abs(c2x-mx);
    	int fouroc2 = abs(c2y-m)+abs(c2x-mx);
    	// cout<<fouro<<' '<<fouroc1<<' '<<fouroc2<<endl;
    	if(fo < min(foc1, foc2) || so < min(soc1,soc2) || to < min(toc1,toc2) || fouro < min(fouroc1,fouroc2)){
    		cout<<"YES"<<endl;
    	}else {
    		cout<<"NO"<<endl;
    	}
    }
    return 0;
}