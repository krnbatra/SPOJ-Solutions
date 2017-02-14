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
#define F first
#define S second
#define FILL(arr, val)  memset(arr, val, sizeof(arr))
#define read(arr, n)    for(int i = 0;i < n; i++)cin>>arr[i];
#define sp ' '

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

const int MAXN = 205;
int F[10000000];
string text, pattern;
int m;

void build(){
    // the prefix under index i is string from pattern[0] to pattern[i-1]
    // inclusive, so the last character of string under index i is [i-1].
    m = pattern.size();
    F[0] = F[1] = 0;    //always true
    for(int i = 2;i <= m; i++){
        // j is the index of the largest next partial match (the largest suffix/prefix)
        // of the string under index (i-1)
        int j = F[i-1];
        while(1){
            // check to see if the last character of string i.e pattern[i-1]
            // expands the current candidate best partial match the prefix under index j
            if(pattern[j] == pattern[i-1]){
                F[i] = j + 1;
                break;
            }
            // if we cannot expand even the empty string
            if(j == 0) { F[i] = 0; break; }
            // else go to the next best candidate partial match
            j = F[j];
        }
    }
}

void kmp(){
    build();
    int flag = 0;
    int n = text.size();
    int i = 0;  // the initial state of automaton is empty
    int j = 0;  // the first character of the text
    while(j < n){
        // if the current character of the text expands the current match
        if(text[j] == pattern[i]){
            i++;
            j++;
            if(i == m) {cout << (j-m) << endl;flag=1;}   // match found
        }
        // if the current state is not 0 (we have not reached the empty string yet) 
        // we try to expand the next best match
        else if(i > 0)  i = F[i];
        // if we reached the empty string and failed to expand even it; we go to the
        // next character from the text, the state of the automaton remains zero
        else j++;
    }
    if(!flag)
        cout << endl;
}

int main(){
    // io;
    while(cin >> m){
        cin >> pattern >> text;
        kmp();
    }
    return 0;
}



