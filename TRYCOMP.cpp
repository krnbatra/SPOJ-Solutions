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

const int MAXN = 26;

struct Trie{
    int words;
    int prefixes;
    Trie* edges[26];
    Trie(){
        words = 0;
        prefixes = 0;
        for(int i = 0;i < MAXN; i++)
            edges[i] = NULL;
    }
};

Trie root;

void addWord(Trie* vertex, int idx, string &word){
    if(idx == word.size()){
        vertex->prefixes++;
        vertex->words++;
        return;
    }
    vertex->prefixes++;
    if(vertex->edges[word[idx]-'a'] == NULL)
        vertex->edges[word[idx]-'a'] = new Trie;
    addWord(vertex->edges[word[idx]-'a'], idx+1, word);
}

string ans;

int query2(Trie* vertex){
	if(vertex->words > 0){
		int maxx = 0;
		for(int i = 0;i < 26; i++){
			if(vertex->edges[i] != NULL)
				maxx = max(maxx, vertex->edges[i]->prefixes);
		}
		if(vertex->words >= maxx)
			return vertex->words;
	}
	int pre_max = 0;
	int corr_char = -1;
	for(int i = 0; i < 26; i++){
		if(vertex->edges[i] != NULL && (vertex->edges[i])->prefixes > pre_max){
			pre_max = vertex->edges[i]->prefixes;
			corr_char = i;
		}
	}
	ans += ('a'+corr_char);
	return query2(vertex->edges[corr_char]);
}

int query(Trie* vertex, int idx, string &word){
	if(idx == word.size())
		return query2(vertex);
	if(vertex->edges[word[idx]-'a'] == NULL)
		return -1;
	return query(vertex->edges[word[idx]-'a'], idx+1, word);
}

void init(){
    root.words = 0;
    root.prefixes = 0;
    for(int i = 0;i < MAXN; i++)
        root.edges[i] = NULL;
}

int main(){
    io;
    init();
    int n;
    cin >> n;
    for(int i = 0;i < n; i++){
    	string s;
    	cin >> s;
	    addWord(&root, 0, s);
	}
	int q;
	cin >> q;
	while(q--){
		string s;
		cin >> s;
		ans = s;
		int num_ans = query(&root, 0, s);
		if(num_ans == -1)
			cout << num_ans << endl;
		else
			cout<< ans << " " << num_ans << endl;
	}
    return 0;
}