/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define MOD (ll)1000000007
#define pb 	push_back
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

vector<int> primes;
int maxx = 100000000;
int arr[100000000];

void sieve(){
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 0;
  primes.pb(2);
  for(int i = 3;i < maxx; i+=2){
      if(arr[i]==0){
          primes.pb(i);
          if(i*(ll)i < (ll)maxx){
              for(int j = i*i; j < maxx; j+=2*i){
                  arr[j] = 1;
              }
          }
      }
  }
}
int main(){
  sieve();
  int i = 0;
  int size = primes.size();
  while(i < size){
      printf("%d\n", primes[i]);
      i+=100;
  }
	return 0;
}
