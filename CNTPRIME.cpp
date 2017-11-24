/*Let's get high :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define M_PI                3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e6+5;
bool isPrime[MAXN];
const int SIZE = 1e4+5;
int N, Q;
int A[SIZE], T[4*SIZE], L[4*SIZE];

void sieve(){
    isPrime[0] = isPrime[1] = 1;
    for(int i = 2;i <= 1000000; i++){
        if(isPrime[i] == 0){
           if(i*1LL*i <= 1000000){
                for(int j = i*i;j <= 1000000; j+=i)
                    isPrime[j] = 1;
           } 
        }
    }
}

void build(int n, int st, int en){
    if(st > en)
        return;
    if(st == en){
        int num = A[st];
        T[n] = isPrime[num] == 1 ? 0 : 1;
        return;
    }
    int left = n << 1, right = left + 1;
    int mid = (st + en) >> 1;
    build(left, st, mid);
    build(right, mid + 1, en);
    T[n] = T[left] + T[right];
}

void update(int n, int st, int en, int l, int r, int v){
    int left = n << 1, right = left + 1;
    if(L[n]){
        T[n] = (en-st+1) * (isPrime[L[n]] == 1 ? 0 : 1);
        if(st != en)
            L[left] = L[right] = L[n];
        L[n] = 0;
    }
    if(st > en || en < l || st > r)
        return;
    if(st >= l && en <= r){
        T[n] = (en-st+1) * (isPrime[v] == 1 ? 0 : 1);
        if(st != en)
            L[left] = L[right] = v;
        return;
    }
    int mid = (st + en) >> 1;
    update(left, st, mid, l, r, v);
    update(right, mid + 1, en, l, r, v);
    T[n] = T[left] + T[right];
}

int query(int n, int st, int en, int l, int r){
    int left = n << 1, right = left + 1;
    if(L[n]){
        T[n] = (en-st+1) * (isPrime[L[n]] == 1 ? 0 : 1);
        if(st != en)
            L[left] = L[right] = L[n];
        L[n] = 0;
    }
    if(st > en || en < l || st > r)
        return 0;
    if(st >= l && en <= r)
        return T[n];
    int mid = (st+en) >> 1;
    return query(left, st, mid, l, r) + query(right, mid + 1, en, l, r);
}

int main(){
    sieve();
    int kase = 1;
    int tc;
    scanf("%d", &tc);
    while(tc--){
        memset(L, 0, sizeof L);
        printf("Case %d:\n", kase);
        kase++;
        scanf("%d%d", &N, &Q);
        for(int i = 0;i < N; i++)
            scanf("%d", &A[i]);
        build(1, 0, N-1);
        while(Q--){
            int t, l, r;
            scanf("%d%d%d", &t, &l, &r);
            l--;r--;
            if(t == 0){
                int v;
                scanf("%d", &v);
                update(1, 0, N-1, l, r, v);
            }else{
                printf("%d\n", query(1, 0, N-1, l, r));
            }
        }
    }
    return 0;
}