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

const int MAXN = 3e4+5;
struct node{
    int type, value, l, r, q_pos, orig_pos, query_pos;
};
vector<node> table;

bool comp(node &x, node &y){
    if(x.value != y.value)  return x.value > y.value;
    return x.type > y.type;
}


int tree[4*MAXN];


// O(log(n))
int query(int node, int start, int end, int l, int r){
    if(start > end || start > r || end < l)
        return 0; 
    if(start >= l && end <= r)
        return tree[node];
    int mid = (start+end) >> 1;
    int left = node << 1, right = left + 1;
    return query(left, start, mid, l, r) + query(right, mid + 1, end, l, r);
}

// O(log(n))
void updateIndex(int node, int start, int end, int idx, int value){
    if(start == end){
        tree[node] += value;
    }else{
        int mid = (start+end) >> 1;
        int left = node << 1, right = left + 1;
        if(idx >= start && idx <= mid)
            updateIndex(left, start, mid, idx, value);
        else
            updateIndex(right, mid + 1, end, idx, value);
        tree[node] = tree[left] + tree[right];
    }
}

int main(){
    // io;
    int n;
    scanf("%d", &n);
    // cin >> n;
    int foo;
    for(int i = 0;i < n; i++){
        // cin >> foo;
        scanf("%d", &foo);
        node t;
        t.type = 1;
        t.orig_pos = i;
        t.value = foo;
        table.push_back(t);
    }
    int q;
    // cin >> q;
    scanf("%d", &q);
    int cnt = 0;
    int final_ans[q];
    int queries = q;
    int l, r, val;
    while(q--){
        // cin >> l >> r >> val;
        scanf("%d%d%d", &l, &r, &val);
        node t;
        t.value = val;
        t.type = 2;
        t.l = l;
        t.r = r;
        t.query_pos = cnt;
        table.push_back(t);
        cnt++;
    }
    sort(table.begin(), table.end(), comp);
    for(auto p : table){
        if(p.type == 1){
            updateIndex(1, 0, n-1, p.orig_pos, 1);
        }else{
            int ans = query(1, 0, n-1, p.l-1, p.r-1);
            final_ans[p.query_pos] = ans;
        }
    }
    for(int i = 0;i < queries; i++){
        // cout << final_ans[i] << endl;
        printf("%d\n", final_ans[i]);
    }
    return 0;
}