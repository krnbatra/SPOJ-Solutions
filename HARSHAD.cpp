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
bool isPrime[MAXN];
bool Devlali[MAXN] = {false};

void sieve(){
    isPrime[0] = isPrime[1] = 1;
    for(int i = 2;i*i <= 1000000; i++){
        if(isPrime[i] == 0){
            if(i*1LL*i <= 1000000){
                for(int j = i*i;j <= 1000000; j+=i)
                    isPrime[j] = 1;
            }
        }
    }
}

int sumDig(int n){
    int sum = 0;
    while(n > 0){
        sum += (n%10);
        n /= 10;
    }
    return sum;
}
bool DP[MAXN];
int DP2[MAXN];
void pre(){
    for(int i = 1;i <= 1000000; i++){
        int sum = sumDig(i) + i;
        if(sum <= 1000000){
            Devlali[sum] = true;
        }
    }
    for(int i = 1;i <= 1000000; i++){
        if(Devlali[i] == false && isPrime[i] == 0)
            DP[i] = true;
    }
    for(int i = 1;i <= 1000000; i++){
        DP2[i] += DP2[i-1];
        if(DP[i])
            DP2[i]++;
    }
}

int main(){
    io;
    sieve();
    pre();
    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        if(l == 0)
            cout << DP2[r] << endl;
        else
            cout << DP2[r] - DP2[l-1] << endl;
    }
    return 0;
}