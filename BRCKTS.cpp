#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 3e4+5;
struct Tree{int uOB, uCB;};
Tree T[4*MAXN];
char s[MAXN];
int n;

void build(int node, int start, int end){
	if(start > end)
		return;
	if(start == end){
		if(s[start] == '('){
			T[node].uOB = 1;
			T[node].uCB = 0;
		}else{
			T[node].uCB = 1;
			T[node].uOB = 0;
		}
		return;
	}
	int mid = (start + end) >> 1;
	int left = node << 1, right = left + 1;
	build(left, start, mid);
	build(right, mid + 1, end);
	int matches = min(T[left].uOB, T[right].uCB);
	T[node].uOB = T[right].uOB + (T[left].uOB - matches);
	T[node].uCB = T[left].uCB + (T[right].uCB - matches);
}

void update(int node, int start, int end, int idx){
	if(start > end)
		return;
	if(start == end){
		if(s[start] == '('){
			s[start] = ')';
			T[node].uCB = 1;
			T[node].uOB = 0;
		}else{
			s[start] = '(';
			T[node].uOB = 1;
			T[node].uCB = 0;
		}
		return;
	}
	int mid = (start + end) >> 1;
	int left = node << 1, right = left + 1;
	if(idx <= mid)
		update(left, start, mid, idx);
	else
		update(right, mid + 1, end, idx);
	int matches = min(T[left].uOB, T[right].uCB);
	T[node].uOB = T[right].uOB + (T[left].uOB - matches);
	T[node].uCB = T[left].uCB + (T[right].uCB - matches);
}

int main(){
	// io;
	for(int i = 1;i <= 10; i++){
		for(int j = 1;j < 4*MAXN; j++){
			T[j].uOB = T[j].uCB = 0;
		}
		printf("Test %d:\n", i);
		scanf("%d ", &n);
		scanf("%s", s);
		build(1, 0, n-1);
		int q;
		scanf("%d", &q);
		while(q--){
			int x;
			scanf("%d", &x);
			if(x > 0){
				x--;
				update(1, 0, n-1, x);
			}else{
				if(T[1].uOB == 0 && T[1].uCB == 0)
					printf("YES\n");
				else
					printf("NO\n");
			}
		}
	}
	return 0;
}