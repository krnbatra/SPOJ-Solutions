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
int answers[300005];
int main(){
    io;
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > table;
    for(int i= 0;i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	table.push_back({{a, b}, i});
    }
    sort(table.begin(), table.end());
    for(int i = 0;i < table.size();){
    	int first_val = table[i].first.first;
    	int second_val = table[i].first.second;
    	int init_idx = i;
    	while(i < table.size() && table[i].first.first == first_val && table[i].first.second == second_val){
     		answers[table[i].second] = query(table[i].first.second);
    		i++;
    	}
    	update(table[i-1].first.second, i-init_idx);
    }
    for(int i = 0;i < table.size(); i++){
    	cout << answers[i] << endl;
    }
    return 0;
}