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
int a[MAXN];
vector<int> b[320];

int main(){
    io;
    int n;
    cin >> n;
    int q;
    cin >> q;
    int sqrtn = sqrt(n);
    for(int i = 0;i < n; i++){
    	cin >> a[i];
    	b[i/sqrtn].push_back(a[i]);
    }
    int numBlocks = ceil((double)n/sqrtn);
    for(int i = 0;i < numBlocks; i++)
    	sort(b[i].begin(), b[i].end());
    while(q--){
    	char c;
    	cin >> c;
    	if(c == 'M'){
    		int idx;
    		cin >> idx;
    		int newVal;
    		cin >> newVal;
    		idx--;
    		int block = idx/sqrtn;
    		int initVal = a[idx];
    		int lo = 0, hi = sqrtn-1;
    		while(lo <= hi){
    			int mid = (lo+hi) >> 1;
    			if(b[block][mid] == initVal){
    				b[block][mid] = newVal;
    				break;
    			}else if(b[block][mid] > initVal){
    				hi = mid-1;
    			}else{
    				lo = mid+1;
    			}
    		}
    		a[idx] = newVal;
    		sort(b[block].begin(), b[block].end());
    	}else{
    		int p, q, x;
    		cin >> p >> q >> x;
    		p--;q--;
    		int leftBlock = p/sqrtn;
    		int rightBlock = q/sqrtn;
    		int ans = 0;
    		if(leftBlock == rightBlock){
    			for(int i = p; i<= q; i++){
    				if(a[i] <= x)
    					ans++;
    			}
    		}else{
    			if(p%sqrtn != 0)
    				leftBlock++;
    			int i;
    			for(i = p; i < leftBlock*sqrtn; i++){
    				if(a[i] <= x)
    					ans++;
    			}
    			while(i+sqrtn-1 <= q){
    				int bb = i/sqrtn;
    				ans += upper_bound(b[bb].begin(), b[bb].end(), x) - b[bb].begin();
    				i += sqrtn;
    			}
    			while(i <= q){
    				if(a[i] <= x)
    					ans++;
    				i++;
    			}
    		}
    		cout << ans << endl;
    	}
    }
    return 0;
}