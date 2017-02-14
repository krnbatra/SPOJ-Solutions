#include <stdio.h>
int isPrime(long long n){
	if (n <= 1)  return 0;
	    if (n <= 3)  return 1;
	 
	    // This is checked so that we can skip 
	    // middle five numbers in below loop
	    if (n%2 == 0 || n%3 == 0) return 0;
	 
	    for (int i=5; i*i<=n; i=i+6)
	        if (n%i == 0 || n%(i+2) == 0)
	           return 0;
	 
	    return 1;
}
int main(void) {
	int t;
	scanf("%d", &t);
	while(t--){
		long long n;
		scanf("%lld", &n);
		if(isPrime(n))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}