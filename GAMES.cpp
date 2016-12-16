/*My First Template :D*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000
#define MOD (ll)1000000007
#define pb 	push_back
#define EPS (float)1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)

template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}

int t;
int main(){
    cin>>t;
    while(t--){
        // float f;
				string input;
				cin>>input;
        int count = 0;
				int i;
				for(i = 0;i < input.size(); i++){
					if(input[i]=='.')
						break;
				}

        if(i == input.size()){
            printf("1\n");
        }else{
						count = input.size()-i-1;
						// cout<<count<<endl;
            int power = exp(10, count);
						ll numerator=0;
						int j;
						for(j = 0;j < input.size(); j++){
							if(j!=i)
								numerator = numerator*10+(input[j]-'0');
						}
						// cout<<numerator<<endl;
            ll denominator = (ll)power;
            ll g = gcd(numerator, denominator);
            ll ans = denominator/g;
            cout<<ans<<endl;
        }

    }
		// printf("%f", 0.33*10);
	return 0;
}
