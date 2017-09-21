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

ll add(ll a, ll b){
    ll res = a + b;
    if(res >= MOD)
        return res - MOD;
    return res;
}

ll mult(ll a, ll b){
    ll res = a * b;
    if(res >= MOD)
        return res % MOD;
    return res;
}

const int SZ = 5;
struct matrix{
    ll arr[SZ][SZ];

    void reset(){
        memset(arr, 0, sizeof arr);
    }

    void makeiden(){
        reset();
        for(int i = 0;i < SZ; i++)
            arr[i][i] = 1;
    }

    matrix operator + (const matrix &o) const{
        matrix res;
        res.reset();
        for(int i = 0;i < SZ; i++)
            for(int j = 0;j < SZ; j++)
                res.arr[i][j] = add(arr[i][j], o.arr[i][j]);
        return res;
    }

    matrix operator * (const matrix &o) const {
        matrix res;
        res.reset();
        for(int i = 0;i < SZ; i++)
            for(int j = 0;j < SZ; j++)
                for(int k = 0;k < SZ; k++)
                    res.arr[i][j] = add(res.arr[i][j], mult(arr[i][k], o.arr[k][j]));
        return res;
    }
};

matrix power(matrix a, int b){
    matrix res;
    res.makeiden();
    while(b){
        if(b & 1){
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

matrix base;
matrix init;

int main(){
    io;
    base.reset();
    init.reset();
    
    base.arr[0][0] = 1;
    base.arr[0][1] = 1;
    base.arr[1][1] = 1;
    base.arr[1][2] = 1;
    base.arr[1][3] = 1;
    base.arr[1][4] = 1;
    base.arr[2][1] = 1;
    base.arr[3][2] = 1;
    base.arr[4][3] = 1;

    init.arr[1][0] = 1;
        
    int t;
    cin >> t;
    while(t--){
    	int n, m;
    	cin >> n >> m;
    	ll sumN, sumM;
    	if(n == 0 || n == 1 || n == 2)
    		sumN = 0;
    	else if(n >= 3)
	    	sumN = (power(base, n-3) * init).arr[0][0];
	    if(m == 0 || m == 1 || m == 2)
	    	sumM = 0;
	    else
	   		sumM = (power(base, m-2) * init).arr[0][0];
	    ll output = ((sumM-sumN) + MOD) % MOD;
	    cout << output << endl;
    }
    return 0;
}