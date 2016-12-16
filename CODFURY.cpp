/*My First Template :D*/
#include <bits/stdc++.h>
#include <limits.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
 
#define MOD (ll)1000000007
#define pb  push_back
#define EPS 1e-9
#define FOR(i, n)   for(int i = 0;i < n; i++)
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

int main(){
    int t;
    si(t);
    while(t--){
        int n, people;
        si(n);
        si(people);
        int arr[n];
        FOR(i, n)   si(arr[i]);
        int l=0,r=0;
        int bc = 0;
        ll currPeople = 0;
        ll maxxPEOPLE = 0;
        while(r < n && l < n){
            if(currPeople+arr[r] <= people){
                currPeople+=arr[r];
                if((r-l+1) == bc){
                    bc = r-l+1;
                    maxxPEOPLE = min(maxxPEOPLE,currPeople);
                }
                if((r-l+1) > bc){
                    bc = r-l+1;
                    maxxPEOPLE = currPeople;
                }
                r++;
            }else{
                currPeople+=arr[r];
                while(currPeople > people){
                    currPeople-=arr[l];
                    l++;
                }
                if(currPeople <= people){
                    if((r-l+1) == bc){
                        bc = r-l+1;
                        maxxPEOPLE = min(maxxPEOPLE,currPeople);
                    }
                    if((r-l+1) > bc){
                        bc = r-l+1;
                        maxxPEOPLE = currPeople;
                    }
                }
                r++;
            }
        }   
        if(currPeople < people){
            r--;
            if((r-l+1) == bc){
                bc = r-l+1;
                maxxPEOPLE = min(maxxPEOPLE,currPeople);
            }
            if((r-l+1) > bc){
                bc = r-l+1;
                maxxPEOPLE = currPeople;
            }
        }
        cout<<maxxPEOPLE<<' '<<bc<<endl;
    }
    return 0;
}