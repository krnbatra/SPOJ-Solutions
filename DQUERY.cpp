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
int BLOCK_SIZE;
ll arr[MAXN];
pair<pair<int, int>, int> queries[200005];

int N, Q;
ll cnt[1000005];
ll curr_ans;
ll answer[200005];

bool mo_cmp(pair<pair<int, int>, int> &x, pair<pair<int, int>, int> &y){
	int block_x = x.first.first/BLOCK_SIZE;
	int block_y = y.first.first/BLOCK_SIZE;
	if(block_x != block_y)
		return block_x < block_y;
	return x.first.second < y.first.second;
}

void add(int x){
	cnt[x]++;
	if(cnt[x] == 1)
		curr_ans++;
}

void remove(int x){
	cnt[x]--;
	if(cnt[x] == 0)
		curr_ans--;
}

int main(){
    scanf("%d", &N);
    BLOCK_SIZE = sqrt(N);
    for(int i = 0;i < N; i++)
    	scanf("%lld", &arr[i]);
    scanf("%d", &Q);
    for(int i = 0;i < Q; i++){
    	scanf("%d %d", &queries[i].first.first, &queries[i].first.second);
    	queries[i].first.first--;
    	queries[i].first.second--;
    	queries[i].second = i;
    }
    sort(queries, queries+Q, mo_cmp);
    int mo_left = 0, mo_right = -1;
    for(int i = 0;i < Q; i++){
    	if (i == 0 || queries[i].first.first / BLOCK_SIZE != queries[i - 1].first.first / BLOCK_SIZE){
			memset(cnt, 0, sizeof(cnt));
			curr_ans = 0;
			for (int j = queries[i].first.first; j <= queries[i].first.second; j++){
				add(arr[j]);
			}
			mo_left = queries[i].first.first, mo_right = queries[i].first.second;
			answer[queries[i].second] = curr_ans;
		}
		else{
	    	int left = queries[i].first.first;
	    	int right = queries[i].first.second;
	    	while(mo_right < right){
	    		mo_right++;
	    		add(arr[mo_right]);
	    	}
	    	while(mo_right > right){
	    		remove(arr[mo_right]);
	    		mo_right--;
	    	}
	    	while(mo_left > left){
	    		mo_left--;
	    		add(arr[mo_left]);
	    	}
	    	while(mo_left < left){
	    		remove(arr[mo_left]);
	    		mo_left++;
	    	}
	    	answer[queries[i].second] = curr_ans;
	    }
    }
    for(int i = 0;i < Q; i++)
    	printf("%lld\n", answer[i]);
    return 0;
}