#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl				'\n'
#define trace1(x)			cerr<<#x<<": "<<x<<endl
#define trace2(x, y)		cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)		cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)	cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl

const int N = 1e6 + 5;
const int p = 31;
const int m = 1e9 + 9;

ll powers[N];

void init(){
	powers[0] = 1;
	for(int i = 1; i < N; i++){
		powers[i] = (powers[i - 1] * p) % m;
	}
}

vector<int> rabin_karp(string &s, string &t){
	// occurences of s(pattern) in t(text)
	int S = s.size(), T = t.size();
	vector<ll> h(T + 1, 0);
	h[0] = (t[0] - 'a' + 1) % m;
	for(int i = 1; i < T; i++)
		h[i] = (h[i - 1] + (t[i] - 'a' + 1) * powers[i]) % m;
	ll h_s = (s[0] - 'a' + 1) % m;
	for(int i = 1; i < S; i++)
		h_s = (h_s + (s[i] - 'a' + 1) * powers[i]) % m;
	vector<int> occurences;
	for(int i = 0; i + S - 1 < T; i++){
		ll curr_h;
		if(i == 0)
			curr_h = h[i + S - 1] % m;
		else
			curr_h = (h[i + S - 1] - h[i - 1] + m) % m;
		if(curr_h == (h_s * powers[i]) % m)
			occurences.push_back(i);
	}
	return occurences;
}

int main(){
	io;
	init();
	int t;
	cin >> t;
	while(t--){
		string s, t;
		cin >> t >> s;
		vector<int> res = rabin_karp(s, t);
		if(res.size() == 0){
			cout << "Not Found" << endl;
			cout << endl;
		}
		else{
			cout << res.size() << endl;
			for(auto i : res)
				cout << i + 1 << " ";
			cout << endl;
			cout << endl;
		}
	}
	return 0;
}