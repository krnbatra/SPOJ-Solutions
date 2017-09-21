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
# define M_PI   3.14159265358979323846

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return mod_exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

const int MAXN = 1e5+5;

int main(){
    io;
    int n, s;
    cin >> n >> s;
    int maxS = (n*(n+1))/2;
    int minS = 2-(n*(n+1))/2;
    if(s < 0){
    	if(s < minS)
    		cout << "Impossible" << endl;
    	else{
    		int rem = maxS+s;
    		if(rem&1)
    			cout << "Impossible" << endl;
    		else{
    			// search for positives
    			int currSum = rem/2 - 1;
    			int sign[n+1];
    			FORE(i,1,n)	sign[i] = 0;
    			sign[1] = 1;
    			int idx = n;
    			// building positive sum
    			while(idx > 1 && currSum){
    				if(currSum-idx == 0){
    					currSum = 0;
    					sign[idx] = 1;
    					break;
    				}
    				if(currSum-idx > 1){
    					currSum -= idx;
    					sign[idx] = 1;
    				}else{
    					sign[idx] = 0;
    				}
    				idx--;
    			}
    			if(currSum)
    				cout << "Impossible" << endl;
    			else{
    				cout << "1";
    				FORE(i,2,n){
    					if(sign[i]){
    						cout << "+";
    					}else{
    						cout << "-";
    					}
    					cout << i;
	    			}
    			}
    		}
    	}
    }else{
	    if(s > maxS){
	    	cout << "Impossible" << endl;
	    }else{
	    	int rem = maxS-s;
	    	if(rem&1){
	    		cout << "Impossible" << endl;
	    	}else{
	    		// divide in equal parts
	    		int currSum = rem/2;
	    		int sign[n+1];
	    		FORE(i,1,n)	sign[i] = 1;
	    		sign[1] = 1;
	    		int idx = n;
	    		// building negative sum
	    		while(idx > 1 && currSum){
	    			if(currSum-idx == 0){
	    				currSum = 0;
	    				sign[idx] = 0;
	    				break;
	    			}
	    			if(currSum-idx > 1){
	    				currSum -= idx;
	    				sign[idx] = 0;
	    			}else{
	    				sign[idx] = 1;
	    			}
	    			idx--;
	    		}
	    		if(currSum)
	    			cout << "Impossible" << endl;
	    		else{
    				cout << "1";
    				FORE(i,2,n){
    					if(sign[i]){
    						cout << "+";
    					}else{
    						cout << "-";
    					}
    					cout << i;
	    			}
	    		}
	    	}
	    }
    }
    return 0;
}
