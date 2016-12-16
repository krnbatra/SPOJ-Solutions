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
#define EPS 1e-6
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

const int MAXN = 5e4+5;
typedef struct node{
	double b;
	double h;
	double w;
	double d;
}cistern;

int cisterns;
cistern arr[MAXN];
double V;
bool f(double mid){
	double currVolume = 0;
	for(int i = 0;i < cisterns; i++){
		if(mid-EPS > (double)arr[i].b+arr[i].h){
			// printf("")
			double temp = (arr[i].h*arr[i].d*arr[i].w);
			// printf("Box%d=%.2lf\n", i, temp);
			currVolume = currVolume+temp;
			// printf("Volume%d=%.2lf\n", i,currVolume);
		}else{
			double height = mid-arr[i].b;
			if(height > 0){
				double temp = (height*arr[i].d*arr[i].w);
				// printf("Box%d=%.2lf\n", i, temp);
				currVolume = currVolume+temp;
				// printf("Volume%d=%.2lf\n", i,currVolume);
			}
		}
	}
	// printf("Volume=%lf\n", currVolume);
	if(currVolume < V-EPS)
		return true;
	return false;
}

int main(){
    io;
    int t;
    cin>>t;
    while(t--){
    	// int cisterns;
    	cin>>cisterns;
    	// cistern arr[cisterns];
    	double volume = 0;
    	for(int i = 0;i < cisterns; i++){
    		cin>>arr[i].b>>arr[i].h>>arr[i].w>>arr[i].d;
    		volume += (arr[i].h*arr[i].w*arr[i].d);
    	}
    	// printf("%lf\n", volume);
    	cin>>V;
    	if(V > volume){
    		printf("OVERFLOW\n");
    	}
    	// cout<<V<<endl;
    	else{
	    	double minn = 2000000000;
	    	double maxx = 0;
	    	for(int i = 0;i < cisterns; i++){
	    		minn = min(arr[i].b, minn);
	    		maxx = max(maxx, arr[i].b+arr[i].h);
	    	}
	    	// cout<<minn<<' '<<maxx<<endl;
	    	double lo = (double)minn;
	    	double hi = (double)maxx;
	    	double mid;
	    	while(hi-lo > EPS){
	    		//is it possible to have mid height
	    		mid = (lo+hi)/2;
	    		// printf("%.2lf\n", mid);
	    		if(f(mid)){
	    			lo = mid;
	    		}else{
	    			hi = mid;
	    		}
	    	}
	    	// double mid = (lo+hi)/2;
	    	// if(f(mid)){
	    		printf("%.2lf\n", lo);
	    	// }
	    }
    }
    return 0;
}
