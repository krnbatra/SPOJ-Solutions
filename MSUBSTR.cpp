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

const int MAXN = 3e3+5;

int P[MAXN*2];

string convert(const string &s){
    string newString = "@";
    for(int i = 0;i < s.size(); i++){
        newString += "#" + s.substr(i, 1);
    }
    newString += "#$";
    return newString;
}

int lps(const string &s){
    string str = convert(s);
    int c = 0, r = 0;   // c - center of main palindrome, r - right boundary of main palindrome
    for(int i = 1;i < str.size()-1; i++){
        int mirr = 2*c - i;     // mirror of i in the main palindrome
        if(i < r)
            P[i] = min(r-i, P[mirr]);
        while(str[i+1+P[i]] == str[i-1-P[i]])   // try expanding around i
            P[i]++;
        if(i+P[i] > r){     // update the main palindrome
            c = i;
            r = i + P[i];
        }
    }
    int maxx = *max_element(P, P+str.size()-1);
    int ans = 0;
    for(int i = 1;i < str.size()-1; i++){
        if(P[i] == maxx)
            ans++;
    }
    cout << maxx << " " << ans << endl;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        lps(s);
        memset(P, 0, sizeof P);
    }
    return 0;
}