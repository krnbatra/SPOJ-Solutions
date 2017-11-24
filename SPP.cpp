/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
// #define MOD (ll)1000000007
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
ll MOD;
struct Matrix{
    vector< vector<int> > mat; // the contents of matrix as a 2D-vector
    int n_rows, n_cols; // number of rows and columns
	Matrix() {}
    Matrix(vector< vector<int> > values): mat(values), n_rows(values.size()),
        n_cols(values[0].size()) {}

    static Matrix identity_matrix(int n){
        // Return I_n - the identity matrix of size n.
        // This function is static, because it creates a new Matrix instance
        vector< vector<int> > values(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++)
            values[i][i] = 1;
        return values;
    }

    Matrix operator*(const Matrix &other) const {
    	ll MOD2 = MOD*MOD;
        int n = n_rows, m = other.n_cols;
        vector< vector<int> > result(n_rows, vector<int>(n_cols, 0));
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) {
                long long tmp = 0;
                for(int k = 0; k < n_cols; k++) {
                    tmp += mat[i][k] * 1ll * other.mat[k][j];
                    while(tmp >= MOD2)
                        tmp -= MOD2;
                }
                result[i][j] = tmp % MOD;
            }
        // Multiply matrices as usual, then return the result as the new Matrix
        return Matrix(result);
    }

    inline bool is_square() const{
        return n_rows == n_cols;
    }
};

Matrix M_powers[55];

void precalc_powers(Matrix M)
{
    assert(M.is_square());
    M_powers[0] = M;

    for(int i = 1; i < 55; i++)
        M_powers[i] = M_powers[i - 1] * M_powers[i - 1];
}

Matrix fast_exponentiation_with_precalc(int power)
{
    Matrix result = Matrix::identity_matrix(M_powers[0].mat.size());
    int pointer = 0;
    while(power) {
        if(power & 1)
            result = result * M_powers[pointer];
        pointer++;
        power >>= 1;
    }
    return result;
}

int main(){
    // io;
 	int t;
 	si(t);
 	while(t--){
 		int k;
 		si(k);
 		int b[k];
 		FOR(i,k)	si(b[i]);
 		int c[k];
 		FOR(i,k)	si(c[i]);
 		ll m, n;
 		scanf("%lld%lld%lld",&m,&n,&MOD);
 		if(n <= k){
 			ll sum1 = 0;
 			for(int i = 0;i < n; i++){
 				sum1+=b[i];
 			}
 			ll sum2 = 0;
 			for(int i = 0;i < m-1; i++){
 				sum2+=b[i];
 			}
 			ll ans = sum1-sum2;
 			if(ans < 0)
 				ans = (ans+MOD)%MOD;
 			printf("%lld\n", ans%MOD);
 		}
 		//M^(n-k)
 		else{
	 		vector<vector<int> > values(k+1, vector<int>(k+1, 0));
	 		ll sum = 0;
	 		for(int i = 0;i < k; i++){
	 			sum += b[i];
	 		}
	 		values[0][0] = 1;
	 		for(int i = 1;i <= k; i++){
	 			values[i][0] = c[i-1];
	 			values[i][1] = c[i-1];
	 		}
	 		for(int i = 1;i < k; i++){
	 			values[i][i+1] = 1;
	 		}
	 		Matrix M(values);
	 		precalc_powers(M);
	 		vector<vector<int> > values2(1, vector<int>(k+1, 0));
	 		values2[0][0] = sum;
	 		for(int i = 1;i <= k; i++){
	 			values2[0][i] = b[k-i];
	 		}
	 		Matrix M2(values2);
	 		ll ans1 = (M2*fast_exponentiation_with_precalc(n-k)).mat[0][0];
	 		ll sum2 = 0, ans2;
	 		if(m <= k){
	 			for(int i = 0;i < m-1; i++){
	 				sum2+=b[i];
	 			}
	 			ans2 = sum2;
	 		}else
	 			ans2 = (M2*fast_exponentiation_with_precalc(m-k-1)).mat[0][0];
	 		ll ans = ans1-ans2;
	 		if(ans < 0)
	 			ans = (ans+MOD)%MOD;
	 		printf("%lld\n", ans);
	 	}
 	}   
    return 0;
}