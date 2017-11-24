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

const int MAXN = 1e5+5;

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	int r, c;
    	cin >> r >> c;
    	int arr[r][c];
    	FOR(i,r){
    		FOR(j,c)
    			cin >> arr[i][j];
    	}
    	arr[r-1][c-1] = 1;
    	for(int j = c-2; j >= 0; j--){
    		arr[r-1][j] = arr[r-1][j+1]-arr[r-1][j];
    		if(arr[r-1][j] <= 0)
    			arr[r-1][j] = 1;
    	}
    	for(int i = r-2;i >= 0; i--){
    		arr[i][c-1] = arr[i+1][c-1]-arr[i][c-1];
    		if(arr[i][c-1] <= 0)
    			arr[i][c-1] = 1;
    	}
    	for(int i = r-2;i >= 0; i--){
    		for(int j = c-2; j >= 0; j--){
    			arr[i][j] = min(arr[i+1][j], arr[i][j+1]) - arr[i][j];
    			if(arr[i][j] <= 0)
    				arr[i][j] = 1;
    		}
    	}
    	cout << arr[0][0] << endl;
    }
    return 0;
}
