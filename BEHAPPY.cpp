#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e2+5;

int gf, gifts;
int A[MAXN], B[MAXN];

int solve(int idx, int left){
	if(idx < 0)	return 1;
	if(left < 0)	return 0;
	if(idx == 0){
		if(left >= A[0] && left <= B[0])	return 1;
		else	return 0;
	}
	int res = 0;
	for(int i = A[idx]; i <= B[idx]; i++){
		res += solve(idx - 1, left - i);
	}
	return res;
}

int main(){
	io;
	while(1){
		cin >> gf >> gifts;
		if(gf == 0 && gifts == 0)
			break;
		for(int i = 0;i < gf; i++)
			cin >> A[i] >> B[i];
		cout << solve(gf - 1, gifts) << endl;
	}
	return 0;
}