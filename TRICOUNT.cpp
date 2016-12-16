#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){int t;scanf("%d", &t);while(t--){	ull n;	scanf("%llu", &n);	ull ans = n*(n+2)*(2*n+1)/8;	printf("%llu\n", ans);}return 0;}