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

struct Tree{ int unOB, unCB; };
char str[32768];
Tree T[65536];

void build(int node, int start, int end){
    // cout<<node<<endl;
    if(start == end){
        if(str[start] == '('){
            T[node].unOB=1, T[node].unCB = 0;
        }else{
            T[node].unOB=0, T[node].unCB = 1;
        }
        return;
    }
    int mid = (start+end)/2;
    int left = 2*node, right = left+1;
    build(left, start, mid);
    build(right, mid+1, end);
    int matches = min(T[left].unOB, T[right].unCB);
    T[node].unOB = (T[left].unOB-matches)+T[right].unOB;
    T[node].unCB = T[left].unCB+(T[right].unCB-matches);
}

void update(int node, int start, int end, int idx){
    if(start == end){
        if(str[start] == '('){
            T[node].unOB=0, T[node].unCB=1;
        }else{
            T[node].unOB=1, T[node].unCB=0;
        }
        return;
    }
    int mid = (start+end)/2;
    int left = 2*node, right = left+1;
    if(idx <= mid){
        update(left, start, mid, idx);
    }else{
        update(right, mid+1, end, idx);
    }
    int matches = min(T[left].unOB, T[right].unCB);
    T[node].unOB = (T[left].unOB-matches)+T[right].unOB;
    T[node].unCB = T[left].unCB+(T[right].unCB-matches);
}


int main(){
  for(int i = 1;i <= 1; i++){
      int len;
      si(len);
      scanf("%s", str);
      build(1, 0, len-1);
      printf("Test %d:\n", i);
      int q;
      si(q);
      while(q--){
          int x;
          si(x);
          if(x == 0){
              //query
              if(T[1].unOB == 0 && T[1].unCB == 0){
                  printf("YES\n");
              }else{
                  printf("NO\n");
              }
          }else{
              //replace
              update(1, 0, len-1, --x);
          }
      }
  }
  return 0;
}