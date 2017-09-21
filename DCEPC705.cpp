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
int n, k;
int BIT[MAXN];

void update(int idx, int val){
    while(idx <= 100000){
        BIT[idx] += val;
        idx += idx&-idx;
    }
}

int query(int idx){
    int sum = 0;
    while(idx > 0){
        sum += BIT[idx];
        idx -= idx&-idx;
    }
    return sum;
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
        memset(BIT, 0, sizeof BIT);
        set<pair<int, int> > S;
        vector<pair<int, int> > table;
        vector<int> Y, Ytemp;
        cin >> n >> k;
        for(int i = 0;i < n; i++){
            int x, y;
            cin >> x >> y;
            if(S.find({x, y}) != S.end()){
                assert(0);
            }
            table.push_back({x, y});
            S.insert({x, y});
        }
        sort(table.begin(), table.end());
        for(auto p : table)
            Y.push_back(p.second);
        for(auto i : Y)
            Ytemp.push_back(i);
        sort(Ytemp.begin(), Ytemp.end());
        vector<int> final;
        for(auto i : Y){
            int pos = lower_bound(Ytemp.begin(), Ytemp.end(), i) - Ytemp.begin() + 1;
            final.push_back(pos);
        }
        int cnt = 0;
        for(int i = 0;i < n; i++){
            // int nd = n-1-i;
            int d = query(final[i]);
            int nd = n-1-d;
            update(final[i], 1);
            int diff = abs(d-nd);
            if(diff >= k)
                cnt++;
        }
        cout << cnt << endl;
    } 
    return 0;
}