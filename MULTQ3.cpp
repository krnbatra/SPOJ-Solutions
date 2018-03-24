#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;
int arr[MAXN], lazy[4*MAXN];
struct Tree{
	int rem0, rem1, rem2;
};
Tree T[4*MAXN];

int n, q;

void build(int node, int start, int end){
	if(start > end)
		return;
	if(start == end){
		T[node].rem0 = 1;
		T[node].rem1 = 0;
		T[node].rem2 = 0;
		return;
	}
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	build(left, start, mid);
	build(right, mid + 1, end);
	T[node].rem0 = T[left].rem0 + T[right].rem0;
	T[node].rem1 = T[left].rem1 + T[right].rem1;
	T[node].rem2 = T[left].rem2 + T[right].rem2;
}

void update(int node, int start, int end, int l, int r){
	int left = node << 1, right = left + 1;
	if(lazy[node] != 0){
		if(lazy[node] == 1){
			int temp = T[node].rem2;
			T[node].rem2 = T[node].rem1;
			T[node].rem1 = T[node].rem0;
			T[node].rem0 = temp;
			if(start != end){
				lazy[left] = (1+lazy[left])%3;
				lazy[right] = (1+lazy[right])%3;
			}
		}else if(lazy[node] == 2){
			int temp = T[node].rem2;
			T[node].rem2 = T[node].rem0;
			T[node].rem0 = T[node].rem1;
			T[node].rem1 = temp;
			if(start != end){
				lazy[left] = (2+lazy[left])%3;
				lazy[right] = (2+lazy[right])%3;
			}
		}
		
		lazy[node] = 0;
	}
	if(start > end || start > r || end < l)
		return;
	if(start >= l && end <= r){
		int temp = T[node].rem2;
		T[node].rem2 = T[node].rem1;
		T[node].rem1 = T[node].rem0;
		T[node].rem0 = temp;
		if(start != end){
			lazy[left] = (1+lazy[left])%3;
			lazy[right] = (1+lazy[right])%3;
		}
		return;
	}
	int mid = (start + end) >> 1;
	update(left, start, mid, l, r);
	update(right, mid + 1, end, l, r);
	T[node].rem0 = T[left].rem0 + T[right].rem0;
	T[node].rem1 = T[left].rem1 + T[right].rem1;
	T[node].rem2 = T[left].rem2 + T[right].rem2;
}

int query(int node, int start, int end, int l, int r){
	int left = node << 1, right = left + 1;
	if(lazy[node] != 0){
		if(lazy[node] == 1){
			int temp = T[node].rem2;
			T[node].rem2 = T[node].rem1;
			T[node].rem1 = T[node].rem0;
			T[node].rem0 = temp;
			if(start != end){
				lazy[left] = (1+lazy[left])%3;
				lazy[right] = (1+lazy[right])%3;
			}
		}else if(lazy[node] == 2){
			int temp = T[node].rem2;
			T[node].rem2 = T[node].rem0;
			T[node].rem0 = T[node].rem1;
			T[node].rem1 = temp;
			if(start != end){
				lazy[left] = (2+lazy[left])%3;
				lazy[right] = (2+lazy[right])%3;
			}
		}
		lazy[node] = 0;
	}
	if(start > end || start > r || end < l)
		return 0;
	if(start >= l && end <= r){
		return T[node].rem0;
	}
	int mid = (start + end) >> 1;
	return query(left, start, mid, l, r) + query(right, mid + 1, end, l, r);
}

int main(){
	scanf("%d%d", &n, &q);
	build(1, 0, n-1);
	while(q--){
		int type, l, r;
		scanf("%d%d%d", &type, &l, &r);
		if(type == 0){
			update(1, 0, n-1, l, r);
		}else{
			int ans = query(1, 0, n-1, l, r);
			printf("%d\n", ans);
		}
		// for(int i = 1; i <= 7; i++)
		// 	printf("node: %d rem0: %d rem1: %d rem2: %d lazy: %d\n", i, T[i].rem0, T[i].rem1, T[i].rem2, lazy[i]);
		// printf("\n");
	}
	return 0;
}