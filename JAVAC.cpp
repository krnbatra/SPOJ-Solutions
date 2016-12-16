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
int main(){
    char buff[1000];
    while(fscanf(stdin,"%s", buff)!=EOF){
        int c = 0;
        int j = 0;
        int i = 0;
        while(buff[i]!='\0'){
            if(buff[0] >= 'A' && buff[0] <= 'Z'){
                c=1;
                j=1;
                // break;
            }
            if(buff[0]=='_'){
                c=1;
                j=1;
                // break;
            }
            if(buff[i] >= 'A' && buff[i] <= 'Z'){
                j = 1;
            }else if(buff[i]=='_'){
                c = 1;
                if(buff[i+1]!='\0' && buff[i+1]=='_'){
                    j = 1;
                }
            }
            i++;
        }
        if(buff[i-1]=='_'){
            c=1;
            j=1;
        }
        if(c==1 && j==1){
            cout<<"Error!"<<endl;
        }else if(c==1){
            //convert to java
            i = 0;
            while(buff[i]!='\0'){
                if(buff[i]!='_'){
                    cout<<buff[i];
                }else{
                    i++;
                    cout<<(char)(buff[i]-32);
                }
                i++;
            }
            cout<<endl;
        }else{
            //convert to c++
            i = 0;
            while(buff[i]!='\0'){
                if(buff[i] >= 'A' && buff[i] <= 'Z'){ 
                    cout<<'_';
                    cout<<(char)(buff[i]+32);
                }else{
                    cout<<buff[i];
                }
                i++;
            }
            cout<<endl;
        }
    }
	return 0;
}