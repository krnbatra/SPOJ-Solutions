#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;
int arr[MAXN], tree[4*MAXN], lazy[4*MAXN];
int n, q;

void update(int node, int start, int end, int l, int r){
	int left = node << 1, right = left + 1;
	if(lazy[node] != 0){
		tree[node] = (end-start+1) - tree[node];
		if(start != end){
			lazy[left] = 1-lazy[left];
			lazy[right] = 1-lazy[right];
		}
		lazy[node] = 0;
	}
	if(start > end || start > r || end < l)
		return;
	if(start >= l && end <= r){
		tree[node] = (end-start+1) - tree[node];
		if(start != end){
			lazy[left] = 1-lazy[left];
			lazy[right] = 1-lazy[right];
		}
		return;
	}
	int mid = (start + end) >> 1;
	update(left, start, mid, l, r);
	update(right, mid + 1, end, l, r);
	tree[node] = tree[left] + tree[right];
}

int query(int node, int start, int end, int l, int r){
	int left = node << 1, right = left + 1;
	if(lazy[node] != 0){
		tree[node] = (end-start+1) - tree[node];
		if(start != end){
			lazy[left] = 1-lazy[left];
			lazy[right] = 1-lazy[right];
		}
		lazy[node] = 0;
	}
	if(start > end || start > r || end < l)
		return 0;
	if(start >= l && end <= r){
		return tree[node];
	}
	int mid = (start + end) >> 1;
	return query(left, start, mid, l, r) + query(right, mid + 1, end, l, r);
}

int main(){
	scanf("%d%d", &n, &q);
	while(q--){
		int type, l, r;
		scanf("%d%d%d", &type, &l, &r);
		l--;r--;
		if(type == 0){
			update(1, 0, n-1, l, r);
		}else{
			int ans = query(1, 0, n-1, l, r);
			printf("%d\n", ans);
		}
		// for(int i = 1;i <= 15; i++)
		// 	printf("Node: %d Value: %d\n", i, tree[i]);
		// printf("\n");
	}
	return 0;
}