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

const int MAXN = 1e5+5;
int TOP[MAXN], BOTTOM[MAXN];

int main(){
    io;
    int n;
    cin >> n;
    int temp = n;
    unordered_set<int> top;
    unordered_set<int> bottom;
    while(n--){
        int a, b;
        cin >> a >> b;
        top.insert(a);
        bottom.insert(b);
        TOP[a]++;
        BOTTOM[b]++;
    }
    n = temp;
    int flag = 0;
    int minn = INT_MAX;
    // for(auto i : top){
    //     int currCount = TOP[i];
    //     int requiredCount = (n+1)/2-currCount;
    //     if(requiredCount <= 0){minn = 0;flag=1;break;}
    //     if(BOTTOM[i] >= requiredCount){
    //         minn = min(minn, requiredCount);
    //     }
    // }
    // if(!flag){
    //     for(auto i : bottom){
    //         int currCount = BOTTOM[i];
    //         int requiredCount = (n+1)/2-currCount;
    //         if(requiredCount <= 0){minn = 0;flag=1;break;}
    //         if(TOP[i] >= requiredCount)
    //             minn = min(minn, requiredCount);
    //     }
    // }
    for(int i = 0;i <= 100000; i++){
        int currCount = TOP[i];
        int requiredCount = (n+1)/2-currCount;
        if(requiredCount <= 0){minn = 0;flag=1;break;}
        if(BOTTOM[i] >= requiredCount)
            minn = min(minn, requiredCount);
    }
    if(minn == INT_MAX)
        cout << "Impossible" << endl;
    else
        cout << minn << endl;
    return 0;
}