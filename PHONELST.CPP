/*input
2
3
911
97625999
91125426
5
113
12340
123440
12345
98346
*/
#include <bits/stdc++.h>
#define fio ios_base::sync_with_stdio(0);cin.tie(0)	
#define FOR(i, a, b) for(long long i = a;i < b; i++)		
#define rev(i, a, b) for(long long i = a;i > b; i--)		
#define si(a)   scanf("%d", &a) 					
#define pi(a)   printf("%d\n", a)					
typedef long long ll;
#define dbl long double		
#define vi vector<int>
#define vll vector<long long>
#define pii pair<int,int> 
#define pll pair< ll , ll >
#define vpll vector< pll >		
#define all(v) v.begin(),v.end()				
#define pb push_back									//^
#define ff first										//^
#define ss second										//^
#define MOD (ll)1000000007								//^
#define M_PI 3.14159265358979323846
#define ednl endl
#define N 1000005
#define MAX 100005
#define EPS 1e-12
template <typename T> T gcd(T a, T b){return (b==0)?a:gcd(b,a%b);}
template <typename T> T lcm(T a, T b){return a*(b/gcd(a,b));}
template <typename T> T exp(T b, T p){T x = 1;while(p){if(p&1)x=(x*b);b=(b*b);p=p>>1;}return x;}
template <typename T> T mod_exp(T b, T p, T m){T x = 1;while(p){if(p&1)x=(x*b)%m;b=(b*b)%m;p=p>>1;}return x;}

using namespace std;

const int AS = 10;

struct TrieNode
{
	struct TrieNode *children[AS];
	bool isEnd;
	int words;
	int prefixes;
};


TrieNode *getNode()
{
	struct TrieNode *pNode = new TrieNode;
	pNode->isEnd = false;
	pNode->words = 0;
	pNode->prefixes = 0;
	for(int i=0;i<AS;i++)
		pNode->children[i] = NULL;
	return pNode;
}

bool insert(TrieNode *root, string key)
{
	TrieNode *pCrawl = root;
	for(int i=0;i<key.size();i++)
	{
		pCrawl->prefixes++;
		if(pCrawl->isEnd)
			return 0;
		int idx = key[i] - '0';
		if(!pCrawl->children[idx])
			pCrawl->children[idx] = getNode();
		pCrawl = pCrawl->children[idx];


	}
	pCrawl->words++;
	pCrawl->isEnd = true;

	return 1;
}

bool search(TrieNode *root, string key)
{
	TrieNode *pCrawl = root;
	for(int i=0;i<key.size();i++)
	{
		if(!pCrawl->children[key[i]-'0'])
			return false;
		pCrawl = pCrawl->children[key[i]-'0'];
	}

	return(pCrawl!=NULL && pCrawl->isEnd);
}

int countPrefixes(TrieNode *root, string key)
{
	TrieNode *pCrawl = root;
	for(int i=0;i<key.size();i++)
	{
		if(!pCrawl->children[key[i]-'0'])
			return 0;
		pCrawl = pCrawl->children[key[i]-'0'];
	}
	return pCrawl->prefixes;
}

int countWords(TrieNode *root, string key)
{
	TrieNode *pCrawl = root;
	for(int i=0;i<key.size();i++)
	{
		if(!pCrawl->children[key[i]-'0'])
			return 0;
		pCrawl = pCrawl->children[key[i]-'0'];
	}
	return pCrawl->words;
}

int main()
{
	fio;
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<string> v(n, "");
		for(int i=0;i<n;i++)
			cin>>v[i];
		sort(all(v));
		struct TrieNode *root = getNode();

		bool f = 1;
		for(int i=0;i<n;i++)
		{
			if(!insert(root, v[i]))
			{
				cout<<"NO"<<endl;
				f = 0;
				break;
			}
		}
		if(f)
		cout<<"YES"<<endl;
	}
	// string keys[] = {"the", "a", "there", "answer", "any", "by", "bye", "their" };
	// int n = sizeof(keys)/sizeof(keys[0]);
	// struct TrieNode *root = getNode();
 
 //    // Construct trie
 //    for (int i = 0; i < n; i++)
 //        insert(root, keys[i]);

 //    // Search for different keys
 //    cout<<countPrefixes(root, "th")<<endl;
 //    search(root, "the")? cout << "Yes\n" :
 //                         cout << "No\n";
 //    search(root, "these")? cout << "Yes\n" :
 //                           cout << "No\n";

	

	return 0;
}
