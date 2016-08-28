#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t-- > 0){
		long long int thirdTerm, thirdLastTerm, sum;
		scanf("%lld",&thirdTerm);
		scanf("%lld",&thirdLastTerm);
		scanf("%lld",&sum);
		long long int numOfTerms = (2*sum)/(thirdTerm+thirdLastTerm);
		printf("%lld\n",numOfTerms);
		long long int d = (thirdLastTerm-thirdTerm)/(numOfTerms-5);
		long long int a = thirdTerm-(2*d);
		for(int i = 1;i <= numOfTerms; i++){
			printf("%lld ",(a+(i-1)*d));

		}
            printf("\n");
	}

	return 0;
}
