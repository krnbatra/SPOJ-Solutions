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


int main(){
    io;
 	int m, n;
 	while(1){
 	cin >> m >> n;
	 	if(m == 0 && n == 0)
	 		break;
	 	int matrix[m][n];
	 	FOR(i,m){
	 		FOR(j,n){
	 			cin >> matrix[i][j];
	 		}
	 	}
	 	int row[m];
	 	//row[i] is the maximum i can obtain from ith row
	 	for(int i = 0;i < m; i++){
	 		int dp[n];
	 		for(int j = 0;j < n; j++)
	 			dp[j] = 0;
	 		//dp[j] is the maximum from the first j elements
	 		dp[0] = matrix[i][0];
	 		dp[1] = max(matrix[i][0], matrix[i][1]);
	 		for(int j = 2;j < n; j++){
	 			dp[j] = max(matrix[i][j]+dp[j-2], dp[j-1]);
	 		}
	 		row[i] = dp[n-1];
	 	}
	 	int dp[m];
	 	dp[0] = row[0];
	 	dp[1] = max(row[0], row[1]);
	 	for(int i = 2; i < m; i++){
	 		dp[i] = max(dp[i-2]+row[i], dp[i-1]);
	 	}
	 	cout << dp[m-1] << endl;
	}
    return 0;
}