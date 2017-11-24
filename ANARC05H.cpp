/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD                 1000000007LL
#define pb                   push_back
#define EPS                 1e-9
#define FOR(i,n)             for(int i = 0;i < n; i++)
#define FORE(i,a,b)         for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io                     ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl                 '\n'
#define F                     first
#define S                     second
#define sp                     ' '
#define M_PI                   3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;
ll dp[26][230];
string str;

ll solve(int idx, int prevSum){
    // new string starts from idx
    if(idx == (int)str.size())    return 1;
    if(dp[idx][prevSum] != -1)  return dp[idx][prevSum];
    int sum = 0;
    ll ans = 0;
    for(int i = idx; i < str.size(); i++){
        sum += (str[i]-'0');
        if(sum >= prevSum)
            ans += solve(i+1, sum);
    }
    dp[idx][prevSum] = ans;
    return ans;
}

int main(){
    io;
    for(int kase = 1; ; kase++){
        cin >> str;
        if(str == "bye")
            break;
        memset(dp, -1, sizeof dp);
        cout << kase << ". " << solve(0, 0) << endl;
    }
    return 0;
}
