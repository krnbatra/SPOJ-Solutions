/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define pi(a)   printf("%d\n", a)
#define all(c)  c.begin(), c.end()
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define gc getchar_unlocked
#define sdi(a, b)   si(a);si(b)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'

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

const int MAXN = 1e7;
vector<int> primes;
int isPrime[MAXN+1];    //isPrime[i] = 0 indicates i is prime. 
void sieve(){
    //if even check itself while calling. This function will only tells wether a number is prime or not(not for even numbers).
    isPrime[0] = isPrime[1] = 1;
    primes.pb(2);
    for(int i = 3; i <= MAXN; i+=2){
        if(isPrime[i] == 0){
            primes.pb(i);
            if(i*(ll)1*i <= MAXN){
                for(int j = i*i; j <= MAXN; j += (2*i)){
                    isPrime[j] = 1;
                }
            }
        }
    }
}

const int SIZE = (int)1e5+1;     //define size to be max(B-A+1)
ll r[SIZE];
ll phi[SIZE];
void segmentedSieve(ll a, ll b){
    for(int i = 0;i < SIZE; i++){
        r[i] = a+i;
        phi[i] = a+i;
    }
    // if(a == 1)    a++;
    // int sqrtn = sqrt(b);
    //arr[0] represents a
    for(int i = 0;i < primes.size(); i++){
        int p = primes[i];
        ll j = p;
        if(j < a)    j = ((a+p-1)/p)*p;    //j = ceil(a/p)*p
        for(; j <= b; j+=p){    //j is the smallest multiple of p
            phi[j-a] /= p;
            phi[j-a] *= (p-1);
            while(r[j-a]%p == 0){
                r[j-a]/=p;
            }
        }
    }
    // int res = 0;
    for(ll i = a; i<= b; i++){
        if(r[i-a] > 1){
            phi[i-a] /= r[i-a];
            phi[i-a] *= (r[i-a]-1);
        }
    }
    for(ll i = a;i <= b; i++){
        // cout<<"AR"<<endl;
        if(i != b)
            printf("%lld\n",phi[i-a]);
        else
            printf("%lld",phi[i-a]);
    }
    return;
}

int main(){
    io;
    sieve();
    ll a, b;
    cin>>a>>b;
    // cout<<a<<b<<endl;
    segmentedSieve(a,b);
    return 0;
}
