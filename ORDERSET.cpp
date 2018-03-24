#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 2e5+5;
int tree[4*MAXN];
int numbers[MAXN];
int vis[MAXN];
unordered_map<int, int> reverse_map;

void update(int node, int start, int end, int idx, int val){
	if(start > end)
		return;
	if(start == end){
		tree[node] = val;
		return;
	}
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	if(idx <= mid)
		update(left, start, mid, idx, val);
	else
		update(right, mid+1, end, idx, val);
	tree[node] = tree[left] + tree[right];
}

int query(int node, int start, int end, int l, int r){
	if(start > end || start > r || end < l)
		return 0;
	if(start >= l && end <= r)
		return tree[node];
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	return query(left, start, mid, l, r) + query(right, mid + 1, end, l, r);
}

int main(){
	io;
	int q;
	scanf("%d ", &q);
	char type[q];
	int initial[q];
	for(int i = 0;i < q; i++){
		scanf("%c%d ", &type[i], &numbers[i]);
	}
	int temp[q];
	for(int i = 0;i < q; i++){
		temp[i] = numbers[i];
		initial[i] = numbers[i];
	}
	sort(temp, temp+q);
	for(int i = 0;i < q; i++){
		int id = lower_bound(temp, temp+q, numbers[i]) - temp;
		reverse_map[id] = numbers[i];
		numbers[i] = id;
	}
	int n = q;
	for(int i = 0;i < q; i++){
		if(type[i] == 'I'){
			update(1, 0, n-1, numbers[i], 1);
			vis[numbers[i]] = 1;
		}else if(type[i] == 'D'){
			update(1, 0, n-1, numbers[i], 0);
			vis[numbers[i]] = 0;
		}
		else if(type[i] == 'K'){
			int lo = -1, hi = 200000;
			int maxx = query(1, 0, n-1, 0, hi);
			if(maxx < initial[i])
				printf("invalid\n");
			else{
				while(hi-lo > 1){
					int mid = (lo + hi) >> 1;
					int smaller_than_mid = query(1, 0, n-1, 0, mid);
					if(smaller_than_mid < initial[i])
						lo = mid;
					else
						hi = mid;
				}
				printf("%d\n", reverse_map[hi]);
			}
		}else{
			int ans = query(1, 0, n-1, 0, numbers[i]);
			if(vis[numbers[i]])
				ans--;
			printf("%d\n", ans);
		}
	}
	return 0;
}