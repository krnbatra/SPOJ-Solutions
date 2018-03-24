#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

const int MAXN = 1e5+5;

int n, m;
vector<int> tree[4*MAXN];
vector<pair<int, int> > table;
int arr[MAXN];

void build(int node, int start,  int end){
	if(start > end)		return;

	if(start==end){
		tree[node].push_back(table[start].second);
		return;
	}
	int mid = (start + end) >> 1;
	int left = node << 1, right = left + 1;
	build(left, start, mid);
	build(right, mid + 1, end);
	merge(tree[left].begin(), tree[left].end(), tree[right].begin(), tree[right].end(), back_inserter(tree[node]));
}

int query(int node, int start, int end, int l, int r, int k){
	if(start == end)
	    return tree[node][0];
	int mid = (start + end) >> 1;
	int left = node << 1, right = left + 1;
	auto it = upper_bound(tree[left].begin(), tree[left].end(), r);
	int total = it - lower_bound(tree[left].begin(), tree[left].end(), l);
	if(total >= k){
	    return query(left, start, mid, l, r, k);
	}else{
	    return query(right, mid + 1, end, l, r, k - total);
	}
}


int main(){
    io;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        arr[i] = x;
        table.push_back({x, i});
    }
    sort(table.begin(), table.end());
    build(1, 0, n - 1);
    for(int i = 0; i < m; i++){
        int l, r, k;
        cin >> l >> r >> k;
        --l, --r;
        int idx = query(1, 0, n - 1, l, r, k);
        cout << arr[idx] << endl;
    }
    return 0;
}