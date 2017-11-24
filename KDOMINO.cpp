#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int N = 2e5+5;
const int M = 2e5+5;
const int SQN = sqrt(N) + 1;

struct query{
	int l, r;
	int idx;
	int block;
	int k;
	query(){}
	query(int _l, int _r, int _k, int _id){
		l = _l;
		r = _r;
		k = _k;
		block = _l/SQN;
		idx = _id;
	}
	bool operator < (const query &b) const{
		if(block != b.block)
			return block < b.block;
		return r < b.r;
	}

};

query Q[M];
int ans[M];
int n, q;
int arr[N], temp[N];
int freq[N], counter[N];

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n; i++){
		scanf("%d", arr+i);
		temp[i] = arr[i];
	}
	sort(temp + 1, temp + 1 + n);
	for(int i = 1;i <= n; i++){
		int id = lower_bound(temp+1, temp+1+n, arr[i]) - (temp+1);
		arr[i] = id+1;
	}
	for(int i = 1;i <= q; i++){
		int l, r, k;
		scanf("%d%d%d", &l, &r, &k);
		Q[i] = query(l, r, k, i);
	}
	sort(Q+1, Q+1+q);
	int curl = 1, curr = 0;
	int t_ans = 0;
	for(int i = 1;i <= q; i++){
		int l = Q[i].l;
		int r = Q[i].r;
		int idx = Q[i].idx;
		int k = Q[i].k;
		while(curr < r){
			++curr;
			int val = arr[curr];
			int c = freq[val];
			counter[c]--;
			freq[val]++;
			counter[freq[val]]++;
			t_ans = max(t_ans, freq[val]);
		}
		while(curl > l){
			--curl;
			int val = arr[curl];
			int c = freq[val];
			counter[c]--;
			freq[val]++;
			counter[freq[val]]++;
			t_ans = max(t_ans, freq[val]);
		}
		while(curr > r){
			int val = arr[curr];
			int c = freq[val];
			counter[c]--;
			freq[val]--;
			counter[freq[val]]++;
			while(counter[t_ans] == 0)	t_ans--;	
			--curr;
		}
		while(curl < l){
			int val = arr[curl];
			counter[freq[val]]--;
			freq[val]--;
			counter[freq[val]]++;
			while(counter[t_ans] == 0)	t_ans--;
			++curl;
		}
		if(t_ans*k >= (r-l+1))
			ans[idx] = 1;
	}
	for(int i = 1;i <= q; i++){
		printf("%s\n", (ans[i] == 1) ? "YES" : "NO");
	}
	return 0;
}