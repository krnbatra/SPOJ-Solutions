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

const int MAXN = 1e6+5;
int N, Q;
ll BIT[MAXN];

void update(int idx, int val){
    while(idx <= 1000000){
        BIT[idx] += val;
        idx += idx&-idx;
    }
}

ll query(int idx){
    ll sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -= idx&-idx;
    }
    return sum;
}

int main(){
    io;
    cin >> N >> Q;
    while(Q--){
        string s;
        cin >> s;
        if(s == "find"){
            int a, b;
            cin >> a >> b;
            cout << (query(b) - query(a - 1)) << endl;
        }else{
            int idx, val;
            cin >> idx >> val;
            update(idx, (ll)val);
        }
    }
    return 0;
}