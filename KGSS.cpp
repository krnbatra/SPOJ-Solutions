#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;
int arr[MAXN];
struct Tree{int largest, second_largest;};
Tree T[4*MAXN];
int n;

void build(int node, int start, int end){
	if(start > end)
		return;
	if(start == end){
		T[node].largest = arr[start];
		T[node].second_largest = 0;
		return;
	}
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	build(left, start, mid);
	build(right, mid + 1, end);
	if(T[left].largest >= T[right].largest){
		T[node].largest = T[left].largest;
		T[node].second_largest = max(T[right].largest, T[left].second_largest);
	}else{
		T[node].largest = T[right].largest;
		T[node].second_largest = max(T[left].largest, T[right].second_largest);
	}
}

Tree query(int node, int start, int end, int l, int r){
	if(start > end || start > r || end < l){
		Tree t;
		t.largest = t.second_largest = 0;
		return t;
	}
	if(start >= l && end <= r)
		return T[node];
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	Tree t1 = query(left, start, mid, l, r);
	Tree t2 = query(right, mid + 1, end, l, r);
	Tree t3;
	if(t1.largest >= t2.largest){
		t3.largest = t1.largest;
		t3.second_largest = max(t2.largest, t1.second_largest);
	}else{
		t3.largest = t2.largest;
		t3.second_largest = max(t2.second_largest, t1.largest);
	}
	return t3;
}

void update(int node, int start, int end, int idx, int val){
	if(start > end)
		return;
	if(start == end){
		arr[start] = val;
		T[node].largest = val;
		T[node].second_largest = 0;
		return;
	}
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	if(idx <= mid)
		update(left, start, mid, idx, val);
	else
		update(right, mid + 1, end, idx, val);
	if(T[left].largest >= T[right].largest){
		T[node].largest = T[left].largest;
		T[node].second_largest = max(T[right].largest, T[left].second_largest);
	}else{
		T[node].largest = T[right].largest;
		T[node].second_largest = max(T[left].largest, T[right].second_largest);
	}
}

int main(){
	io;
	scanf("%d", &n);
	for(int i = 0;i < n; i++)
		scanf("%d", arr+i);
	build(1, 0, n-1);
	int q;
	scanf("%d ", &q);
	while(q--){
		char t;
		int l, r;
		scanf("%c%d%d ", &t, &l, &r);
		if(t == 'U'){
			l--;
			update(1, 0, n-1, l, r);
		}else{
			l--;r--;
			Tree t = query(1, 0, n-1, l, r);
			printf("%d\n", t.largest + t.second_largest);
		}
	}
	return 0;
}