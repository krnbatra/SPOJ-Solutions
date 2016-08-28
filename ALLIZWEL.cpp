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
int visited[105][105];
char matrix[105][105];
int r, c;
char arr[10] = {'A', 'L', 'L', 'I', 'Z', 'Z', 'W', 'E', 'L', 'L'};
bool isValid(int i, int j){
	if(i >= 0 && i < r && j >= 0 && j < c)
		return true;
	return false;
}
bool res = false;
bool dfs(int i, int j, int k){
	// cout<<i<<' '<<j<<' '<<k<<endl;
	if(k == 10){
		res = true;
		return true;
	}
	if(isValid(i+1, j) && !visited[i+1][j] && matrix[i+1][j] == arr[k]){
		visited[i+1][j] = 1;
		dfs(i+1, j, k+1);
		visited[i+1][j] = 0;
	}
	if(isValid(i-1, j) && !visited[i-1][j] && matrix[i-1][j] == arr[k]){
		visited[i-1][j] = 1;
		dfs(i-1, j, k+1);
		visited[i-1][j] = 0;
	}
	if(isValid(i, j+1) && !visited[i][j+1] && matrix[i][j+1] == arr[k]){
		visited[i][j+1] = 1;
		dfs(i, j+1, k+1);
		visited[i][j+1] = 0;
	}
	if(isValid(i, j-1) && !visited[i][j-1] && matrix[i][j-1] == arr[k]){
		visited[i][j-1] = 1;
		dfs(i, j-1, k+1);
		visited[i][j-1] = 0;
	}
	if(isValid(i+1, j+1) && !visited[i+1][j+1] && matrix[i+1][j+1] == arr[k]){
		visited[i+1][j+1] = 1;
		dfs(i+1, j+1, k+1);
		visited[i+1][j+1] = 0;
	}
	if(isValid(i-1, j+1) && !visited[i-1][j+1] && matrix[i-1][j+1] == arr[k]){
		visited[i-1][j+1] = 1;
		dfs(i-1, j+1, k+1);
		visited[i-1][j+1] = 0;
	}
	if(isValid(i+1, j-1) && !visited[i+1][j-1] && matrix[i+1][j-1] == arr[k]){
		visited[i+1][j-1] = 1;
		dfs(i+1, j-1, k+1);
		visited[i+1][j-1] = 0;
	}
	if(isValid(i-1, j-1) && !visited[i-1][j-1] && matrix[i-1][j-1] == arr[k]){
		visited[i-1][j-1] = 1;
		dfs(i-1, j-1, k+1);
		visited[i-1][j-1] = 0;
	}
	return false;
}

int main(){
    int t;
    si(t);
    while(t--){
    	si(r);
    	si(c);
    	for(int i = 0;i < r; i++){
    		for(int j = 0;j < c; j++){
    			cin>>matrix[i][j];
    			visited[i][j] = 0;
    		}
    	}
    	int flag = 0;
    	for(int i = 0;i < r; i++){
    		for(int j = 0;j < c; j++){
    			if(matrix[i][j] == 'A'){
    				for(int k = 0; k < r; k++){
    					for(int l = 0;l < c; l++){
    						visited[k][l] = 0;
    					}
    				}
    				res = false;
    				visited[i][j] = 1;
    				dfs(i, j, 1);
    				if(res){
    					cout<<"YES"<<endl;
    					flag = 1;
    					break;
    				}
    			}
    		}
    		if(flag)
    			break;
    	}
    	if(!flag)
    		cout<<"NO"<<endl;
    }
    return 0;
}