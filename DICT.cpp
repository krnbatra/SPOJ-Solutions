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
#define read(arr, n)	for(int i = 0;i < n; i++)cin>>arr[i];

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

const int MAXN = 500005;
int sz = 0;

int trie[26][MAXN];	//MAXN represents the maximum number of nodes.
bool end1[MAXN];		//to indicate the end of word
string s, prefix;

void insert(){
    int v = 0;  //root is represented by 0;
    for(int i = 0;i < s.size(); i++){
        int current = s[i]-'a';
        if(trie[current][v] == -1){	//initially trie is filled with -1
            trie[current][v] = ++sz;
        }
        v = trie[current][v];
    }
    end1[v] = true;
}

int searchPrefix(){
    int v = 0;
    for(int i = 0;i < prefix.size(); i++){
        int current = prefix[i]-'a';
        if(trie[current][v] == -1)
            return -1;
        v = trie[current][v];
    }
    return v;
}

void print(int v, vector<char> word){
	if(end1[v] == true && word.size() != 0){
		cout << prefix;
		for(int i = 0;i < word.size(); i++){
			cout << word[i];
		}
		cout << endl;
	}
	for(int i = 0;i < 26; i++){
		if(trie[i][v] != -1){
		  //  cout << i << ' ' << v << endl;
			word.pb((char)(i+'a'));
			print(trie[i][v], word);			
			word.pop_back();			
		}	
	}
}

int main(){
    io;
    FILL(end1, false);
    FILL(trie, -1);
	int n;
	cin >> n;
	set<string> S;
	for(int i = 1;i <= n; i++){
	    string input;
	    cin >> input;
	    S.insert(input);
	}
	for(auto input : S){
	     s = input;
	     insert();
	}
	int q;
	cin >> q;
	int kase = 1;
	while(q--){
	    string input;
	    cin >> input;
	    prefix = input;
	    int vertex = searchPrefix();
	    cout << "Case #" << kase <<":" << endl;
	    if(vertex == -1){
	        cout << "No match." << endl;
	    }else{
	        bool check = false;
	        for(int i = 0;i < 26; i++){
	            if(trie[vertex][i] != -1){
	                check = true;
	            }
	        }
	        if(check){
			    vector<char> V;
			    print(vertex, V);
	            
	        }else{
	            cout << "No match." << endl;
	        }
	    }
	    kase++;
	}
    return 0;
}