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

const int MAXN = 1e5+5;
ll pre_sum[MAXN];
int A[MAXN];

int main(){
    io;
	int n;
	cin >> n;
	for(int i = 1;i <= n; i++)
		cin >> A[i];
	sort(A+1, A+n+1);
	for(int i = 1;i <= n; i++)
		pre_sum[i] = pre_sum[i-1] + 1LL*A[i];
	int q;
	cin >> q;
	while(q--){
		int a, b;
		cin >> a >> b;
		int idx_1 = lower_bound(A+1, A+n+1, a) - A;
		idx_1 -= 1;
		int idx_2 = upper_bound(A+1, A+n+1, b) - A;
		idx_2 -= 1;
		cout << (pre_sum[idx_2] - pre_sum[idx_1]) << endl;
	}
    return 0;
}