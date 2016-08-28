/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb 	push_back
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

void si(int &x){
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

const int MAXN = 1e6+5;
int isPrime[MAXN];	//isPrime[i] = 0 indicates i is prime. 
vector<int> primes;
vector<int> palindromes;

bool isPalindrome(int n){
	int newNumber = 0;
	int tempNumber = n;
	while(n){
		int temp = n%10;
		newNumber = newNumber*10+temp;
		n/=10;
	}
	return newNumber == tempNumber;
}

void sieve(){
	//if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
	isPrime[0] = isPrime[1] = 1;
	primes.pb(2);
	palindromes.pb(2);
	for(int i = 3; i <= MAXN; i+=2){
		if(isPrime[i] == 0){
			primes.pb(i);
			if(isPalindrome(i)){
				palindromes.pb(i);
			}
			if(i*(ll)1*i <= MAXN){
				for(int j = i*i; j <= MAXN; j += (2*i)){
					isPrime[j] = 1;
				}
			}
		}
	}
}


int main(){
    int t;
    si(t);
    sieve();
    while(t--){
    	int n;
    	si(n);
    	n-=1;
    	int ans1 = palindromes[n];
    	int tempAns = ans1;
    	int pro = 1;
    	while(tempAns){
    		int x = tempAns%10;
    		if(x!=0){
    			pro*=x;
    		}
    		tempAns/=10;
    	}
    	int ans2 = primes[pro-1];
    	cout<<ans1<<' '<<ans2<<endl;
    }
    return 0;
}