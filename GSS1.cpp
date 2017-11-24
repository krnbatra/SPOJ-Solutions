#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 5e4+5;
int arr[MAXN];
struct Tree{int maxisum, maxlsum, maxrsum, sum;};
Tree T[4*MAXN];
int n;

void build(int node, int start, int end){
	if(start > end)
		return;
	if(start == end){
		T[node].sum = T[node].maxrsum = T[node].maxlsum = T[node].maxisum = arr[start];
		return;
	}
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	build(left, start, mid);
	build(right, mid + 1, end);
	T[node].maxlsum = max(T[left].maxlsum, T[left].sum + T[right].maxlsum);
	T[node].maxrsum = max(T[right].maxrsum, T[right].sum + T[left].maxrsum);
	T[node].sum = T[left].sum + T[right].sum;
	T[node].maxisum = max(T[left].maxisum, max(T[right].maxisum, T[left].maxrsum + T[right].maxlsum));
}

Tree query(int node, int start, int end, int l, int r){
	if(start > end || start > r || end < l){
		Tree t;
		t.sum = 0;
		t.maxisum = t.maxrsum = t.maxlsum = -15008;
		return t;
	}
	if(start >= l && end <= r)
		return T[node];
	int left = node << 1, right = left + 1;
	int mid = (start + end) >> 1;
	Tree t1 = query(left, start, mid, l, r);
	Tree t2 = query(right, mid + 1, end, l, r);
	Tree t3;
	t3.maxisum = max(t1.maxisum, max(t2.maxisum, t1.maxrsum + t2.maxlsum));
	t3.maxlsum = max(t1.maxlsum, t1.sum + t2.maxlsum);
	t3.maxrsum = max(t2.maxrsum, t2.sum + t1.maxrsum);
	t3.sum = t1.sum + t2.sum;
	return t3;
}

int main(){
	io;
	scanf("%d", &n);
	for(int i = 0;i < n; i++)
		scanf("%d", arr+i);
	build(1, 0, n-1);
	int q;
	scanf("%d", &q);
	while(q--){
		int l, r;
		scanf("%d%d", &l, &r);
		l--;r--;
		printf("%d\n", query(1, 0, n-1, l, r).maxisum);
	}
	return 0;
}