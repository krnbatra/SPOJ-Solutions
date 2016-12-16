/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb 	push_back
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked

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
char matrix[1001][1001];
int visited[1001][1001];
// int count1;
int ans = INT_MIN;
int r, c;
int newX, newY;
int isValid(int i, int j){
	return (i >= 0 && i < r && j >= 0 && j < c);
}
void dfs(int i, int j, int count1){
	// cout<<i<<' '<<j<<' '<<count1<<endl;
	// ans = max(ans, count1);
	if(count1 > ans){
		ans = count1;
		newX = i;
		newY = j;

	}
	visited[i][j] = 1;
	if(isValid(i+1, j) && !visited[i+1][j] && matrix[i+1][j] == '.'){
		dfs(i+1, j, count1+1);
	}
	if(isValid(i-1, j) && !visited[i-1][j] && matrix[i-1][j] == '.'){
		dfs(i-1, j, count1+1);
	}
	if(isValid(i, j+1) && !visited[i][j+1] && matrix[i][j+1] == '.'){
		dfs(i, j+1, count1+1);
	}
	if(isValid(i, j-1) && !visited[i][j-1] && matrix[i][j-1] == '.'){
		dfs(i, j-1, count1+1);
	}
}

int main(){
    int t;
    si(t);
    while(t--){
    	// count1 = 0;
    	// int c, r;
    	ans = INT_MIN;
    	int flag = 0;
    	newX = -1;
    	newY = -1;
    	memset(visited, 0, sizeof(visited));
    	scanf("%d%d", &c, &r);
    	for(int i = 0;i < r; i++){
    		for(int j = 0;j < c; j++){
    			cin>>matrix[i][j];
    		}
    	}
    	// int ans = INT_MIN;
    	for(int i = 0;i < r; i++){
    		// cout<<"HI"<<endl;
    		for(int j = 0;j < c; j++){
    			if(matrix[i][j] == '.'){
    				// memset(visited, 0, sizeof(visited));
    				dfs(i, j, 0);
    				flag = 1;
    				break;
    				// ans = max(ans, count1-1);
    				// count1 = 0;
    			}
    			if(flag)
    				break;
    		}
    	}
    	// cout<<newX<<' '<<newY<<endl;
    	memset(visited, 0, sizeof(visited));
    	ans = INT_MIN;
    	dfs(newX, newY, 0);
    	printf("Maximum rope length is %d.\n", ans);
    }
    return 0;
}