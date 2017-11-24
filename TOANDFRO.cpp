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
#define EPS 1e-9
#define FOR(i, n)	for(int i = 0;i < n; i++)
 
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}
template <typename T> T invFermat(T a, T p){return exp(a, p-2, p);}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
 
int t;
int n;
int main(){
    cin>>n;
    int flag = 0;
    while(n!=0){
        string input;
        cin>>input;
        int rows = input.size()/n;
        char matrix[rows][n];
        int j = -1, k = -1;
        for(int i = 0;i < input.size(); i++){
            if(i%n==0){
                j++;
                if((i/n)&1){
                    k = n-1;
                    flag = 1;
                }
                else{
                    k = 0;
                    flag = 0;
                }
            }
            matrix[j][k] = input[i];
            if(flag==0)
                k++;
            else
                k--;
        }
        for(int i = 0;i < n; i++){
            for(int l = 0; l < rows; l++){
                cout<<matrix[l][i];
            }
        }
        // for(int i = 0;i < rows; i++){
        //     for(int l = 0; l < n; l++){
        //         cout<<matrix[i][l];
        //     }
        //     cout<<endl;
        // }
        cout<<endl;
        cin>>n;
    }
	return 0;
}