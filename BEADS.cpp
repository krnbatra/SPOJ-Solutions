#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl				'\n'
#define trace1(x)			cerr<<#x<<": "<<x<<endl
#define trace2(x, y)		cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)		cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)	cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

const int MAXN = 100005;
const int MAXLG = ceil(log2((double)MAXN));

string A;

struct entry{
    int nr[2], p;
}L[MAXN];

int P[MAXLG][MAXN], N, limit;    // P[k][i] position of Ai^k in the sorted array starting from position i and counting 2^k characters

int cmp(struct entry a, struct entry b){
    return a.nr[0] == b.nr[0] ? (a.nr[1] < b.nr[1] ? 1 : 0) : (a.nr[0] < b.nr[0] ? 1 : 0);
}

int lcp(int x, int y){
	int ret = 0;
	if(x == y)	return N - x;
	for(int k = limit; k >= 0 && x < N && y < N; k--){
		if(P[k][x] == P[k][y])
			x += 1 << k, y += 1 << k, ret += 1 << k;
	}
	return ret;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		cin >> A;
		A = A + A;
	    N = A.size();
	    for(int i = 0; i < N; i++)
	        P[0][i] = A[i] - '0';
	    limit = ceil(log2((double)N));
	    int cnt = 1;
	    for(int k = 1; k <= limit; k++){
	        for(int i = 0; i < N; i++){
	            L[i].nr[0] = P[k - 1][i];
	            L[i].nr[1] = i + cnt < N ? P[k - 1][i + cnt]: INT_MAX;
	            L[i].p = i;
	        }
	        sort(L, L + N, cmp);
	        for(int i = 0; i < N; i++)
	           P[k][L[i].p] = i > 0 && L[i].nr[0] == L[i - 1].nr[0] && L[i].nr[1] == L[i - 1].nr[1] ? P[k][L[i - 1].p] : i;
	        cnt <<= 1;
	    }
	    map<int, int> mp;
	    for(int j = 0; j < N; j++){
	    	mp[P[limit][j]] = j;
	    }
	    cout << mp[0] + 1 << endl;
	}
    return 0;
}