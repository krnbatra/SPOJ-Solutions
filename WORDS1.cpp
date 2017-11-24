/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '
# define M_PI   3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 27;

int adj[MAXN][MAXN];
int indegree[MAXN], outdegree[MAXN];
int adjCopy[MAXN][MAXN];
int vis[MAXN];
int found[MAXN];

void dfs(int u){
	for(int i = 0;i < MAXN; i++){
		if(adj[u][i] > 0){
			adj[u][i]--;
			dfs(i);
		}
	}
}
int count1, count2;
bool isEuler(){
	count1 = count2 = 0;
	for(int i = 0;i < MAXN; i++){
		if(outdegree[i]-indegree[i] == 1)	count1++;
		else if(indegree[i]-outdegree[i] == 1)	count2++;
		else if(indegree[i] != outdegree[i])	return false;
	}
	if((count1 == 1 && count2 == 1) || (count1 == 0 && count2 == 0))
		return true;
	return false;
}



int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	int n;
    	cin >> n;
    	for(int i = 0;i < MAXN; i++){
    		for(int j = 0;j < MAXN; j++){
    			adj[i][j] = 0;
    			adjCopy[i][j] = 0;
    		}
    		indegree[i] = outdegree[i] = vis[i] = 0;
    	}
    	FOR(i, n){
    		string s;
    		cin >> s;
    		int first = (int)(s[0]-'a');
    		int last = (int)(s[(int)s.size()-1]-'a');
    		adj[first][last]++;
    		adjCopy[first][last]++;
    		outdegree[first]++;
    		indegree[last]++;
    	}
		bool checkEulerPath = isEuler();
		int flag = 1;
		if(checkEulerPath){
			if(count1){
				int i;
				for(i = 0;i < MAXN; i++){
					flag = 1;
					if(indegree[i] != outdegree[i]){
						dfs(i);
						for(int j = 0;j < MAXN; j++){
							for(int k = 0;k < MAXN; k++){
								if(adj[j][k] != 0){
									flag = 0;
									break;
								}
							}
							if(!flag)
								break;
						}
						if(flag){
							cout << "Ordering is possible." << endl;
							break;
						}else{
							FOR(i, MAXN){
								vis[i] = 0;
								FOR(j, MAXN)
									adj[i][j] = adjCopy[i][j];
							}
						}
					}
				}
				if(i == MAXN)
					cout << "The door cannot be opened." << endl;
			}else{
				flag = 1;
				for(int i = 0;i < MAXN; i++){
					if(outdegree[i]){
						dfs(i);
						break;
					}
				}
				for(int j = 0;j < MAXN; j++){
					for(int k = 0;k < MAXN; k++){
						if(adj[j][k] != 0){
							flag = 0;
							break;
						}
					}
					if(!flag)
						break;
				}
				if(flag){
					cout << "Ordering is possible." << endl;
				}else{
					cout << "The door cannot be opened." << endl;
				}
			}
		}else{
			cout << "The door cannot be opened." << endl;
		}
    }
    return 0;
}
