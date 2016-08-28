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

const int MAXN = 1e5+5;
int isPrime[MAXN];	//isPrime[i] = 0 indicates i is prime. 
void sieve(){
	//if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
	isPrime[0] = isPrime[1] = 1;
	for(int i = 3; i*i <= MAXN; i+=2){
		if(isPrime[i] == 0){
			if(i*(ll)1*i <= MAXN){
				for(int j = i*i; j <= MAXN; j += (2*i)){
					isPrime[j] = 1;
				}
			}
		}
	}
}
int visited[(int)1e4+5];
int solve(int n1, int n2){
	queue<pair<int, int> > q;	//value and cost
	q.push(make_pair(n1, 0));
	visited[n1] = 1;
	while(!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		int cost = p.second;
		int value = p.first;
		// cout<<value<<endl;
		// cout<<n2<<endl;
		if(value == n2)
			return cost;
		for(int i = 0;i <= 3; i++){
			if(i == 0){
				//change the last digit.
				int tempValue = value;
				tempValue/=10;
				for(int j = 0;j <= 9; j++){
					tempValue = tempValue*10+j;
					if(tempValue%2 != 0 && !isPrime[tempValue] && !visited[tempValue]){
						// cout<<tempValue<<endl;
						q.push(make_pair(tempValue, cost+1));
						visited[tempValue] = 1;
					}
					tempValue/=10;
				}
			}else if(i == 1){
				//change the second last digit
				int tempValue = value;
				int lastDigit = tempValue%10;
				tempValue/=100;
				for(int j = 0;j <= 9; j++){
					tempValue = tempValue*10+j;
					tempValue = tempValue*10+lastDigit;
					if(tempValue%2 != 0 && !isPrime[tempValue] && !visited[tempValue]){
						// cout<<tempValue<<endl;
						q.push(make_pair(tempValue, cost+1));
						visited[tempValue] = 1;
					}
					tempValue/=100;
				}
			}else if(i == 2){
				//change the third last digit.
				int tempValue = value;
				int secondLastDigit = tempValue%100;
				tempValue/=1000;
				for(int j = 0;j <= 9; j++){
					tempValue = tempValue*10+j;
					tempValue = tempValue*100+secondLastDigit;
					if(tempValue%2 != 0 && !isPrime[tempValue] && !visited[tempValue]){
						// cout<<tempValue<<endl;	
						q.push(make_pair(tempValue, cost+1));
						visited[tempValue] = 1;
					}
					tempValue/=1000;
				}
			}else{
				//change the first digit.
				int tempValue = value;
				// cout<<"HELLO"<<tempValue<<endl;
				int thirdLastDigits = tempValue%1000;
				tempValue/=10000;
				for(int j = 1;j <= 9; j++){
					tempValue = tempValue*10+j;
					tempValue = tempValue*1000+thirdLastDigits;
					// cout<<tempValue<<endl;
					if(tempValue%2 != 0 && !isPrime[tempValue] && !visited[tempValue]){
						// cout<<tempValue<<"END"<<endl;
						q.push(make_pair(tempValue, cost+1));
						visited[tempValue] = 1;
					}
					tempValue/=10000;
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
		memset(visited, 0, sizeof(visited));
		int n1, n2;
		si(n1);
		si(n2);
		int ans = solve(n1, n2);
		printf("%d\n", ans);
	}
	return 0;
}