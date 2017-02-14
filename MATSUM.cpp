/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
 
#define MOD (ll)1000000007
#define pb   push_back
#define EPS 1e-9
#define FOR(i,n)  for(int i = 0;i < n; i++)
#define FORE(i,a,b) for(int i = a;i <= b; i++)
#define tr(container, it)   for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl '\n'
#define F first
#define S second
#define sp ' '

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1025;
int BIT[MAXN][MAXN];
int arr[MAXN][MAXN];
int n;

void update(int x, int y, int val){
  while(x <= MAXN){
    // cout << x << sp;
    int y1 = y;
    while(y1 <= MAXN){
      // cout << y1 << sp;
      BIT[x][y1] += val;
      y1 += y1&-y1;
    }
    // cout << endl;
    x += x&-x;
  }
}

int query(int x, int y){
  int sum = 0;
  while(x > 0){
    int y1 = y;
    while(y1 > 0){
      sum += BIT[x][y1];
      y1 -= y1&-y1;
    }
    x -= x&-x;
  }
  return sum;
}

int RSQ(int x1, int y1, int x2, int y2){
  return query(x2, y2) - query(x2, y1-1) - query(x1-1, y2) + query(x1-1, y1-1);
}


int main(){
    io;
    int t;
    cin >> t;
    while(t--){
      cin >> n;
      while(1){
        string input;
        cin >> input;
        if(input == "END")
          break;
        if(input == "SET"){
          int x, y, val;
          cin >> x >> y >> val;
          ++x;++y;
          // cout << x << sp << y << sp << val << endl;
          update(x, y, -arr[x][y] + val);
          arr[x][y] = val;
        }else{
          int x1, y1, x2, y2;
          cin >> x1 >> y1 >> x2 >> y2;
          ++x1;++y1;++x2;++y2;
          // cout << query(x2, y2) << endl;
          // cout << query(x2, y1-1) << endl;
          cout << RSQ(x1, y1, x2, y2) << endl;
        }
      }
      memset(BIT, 0, sizeof BIT);
      memset(arr, 0, sizeof arr);
    }
    return 0;
}