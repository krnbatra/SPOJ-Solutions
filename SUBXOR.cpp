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

const int MAXN = 1e5+5;

struct node{
	int leftc;
	int rightc;
	node* left;
	node* right;
	node(){
		leftc = 0;
		rightc = 0;
		left = NULL;
		right = NULL;
	}
};

node root;

void init(){
	root.leftc = 0;
	root.rightc = 0;
	root.left = NULL;
	root.right = NULL;
}

void insert(node* curr, int n, int level){
	if(level == -1)
		return;
	int x = ((n >> level) & 1);
	if(x){
		curr->rightc++;
		if(curr->right == NULL)
			curr->right = new node;
		insert(curr->right, n, level-1);
	}else{
		curr->leftc++;
		if(curr->left == NULL)
			curr-> left = new node;
		insert(curr->left, n, level-1);
	}
}

ll query(node* curr, int level, int q, int k){
	if(level == -1 || curr == NULL)
		return 0;
	int bitq = ((q >> level) & 1);
	int bitk = ((k >> level) & 1);
	if(bitk){
		if(bitq)
			return (ll)curr->rightc + query(curr->left, level-1, q, k);
		else
			return (ll)curr->leftc + query(curr->right, level-1, q, k);
	}else{
		if(bitq)
			return query(curr->right, level-1, q, k);
		else
			return query(curr->left, level-1, q, k);
	}
}

int main(){
    io;
    int t;
    cin >> t;
    while(t--){
    	init();
    	int n;
    	cin >> n;
    	int k;
    	cin >> k;
    	int arr[n];
    	for(int i = 0; i < n; i++)
    		cin >> arr[i];
    	ll ans = 0;
    	ll pre = 0;
    	insert(&root, 0, 20);
    	for(int i = 0;i < n; i++){
    		pre = pre^arr[i];
    		ans += query(&root, 20, pre, k);
    		insert(&root, pre, 20);
    	}
    	cout << ans << endl;
    }
    return 0;
}