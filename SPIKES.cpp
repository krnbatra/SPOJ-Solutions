/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 45;
int n, m, bear;
char matrix[MAXN][MAXN];
bool possible = false;
bool vis[MAXN][MAXN];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool isValid(int x, int y){
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs1(int x, int y, int rem){
	vis[x][y] = 1;
	for(int i = 0;i < 4; i++){
		int tempX = x+dx[i];
		int tempY = y+dy[i];
		if(isValid(tempX, tempY) && !vis[tempX][tempY]){
			if(matrix[tempX][tempY] == '.'){
				dfs1(tempX, tempY, rem);
				vis[tempX][tempY] = 0;
			}
			if(matrix[tempX][tempY] == '@'){
				dfs1(tempX, tempY, rem);
				vis[tempX][tempY] = 0;
			}
			if(matrix[tempX][tempY] == 's'){
				// cout << tempX << " " << tempY << endl;
				dfs1(tempX, tempY, rem-1);
				vis[tempX][tempY] = 0;	
			}
			if(matrix[tempX][tempY] == 'x'){
				int consumed = bear - rem;
				// cout << consumed << endl;
				if(rem >= consumed)
					possible = true;
				return;
			}
		}
	}
}

int main(){
    io;
    cin >> n >> m >> bear;
    for(int i = 0;i < n; i++){
    	for(int j = 0;j < m; j++)
    		cin >> matrix[i][j];
    }
    for(int i = 0;i < n; i++){
    	for(int j = 0;j < n; j++){
    		if(matrix[i][j] == '@'){
    			memset(vis, false, sizeof vis);
    			// cout << i << " " << j << endl;
    			dfs1(i, j, bear);
    		}
    	}
    }
    if(possible)	cout << "SUCCESS" << endl;
    else			cout << "IMPOSSIBLE" << endl;
    return 0;
}