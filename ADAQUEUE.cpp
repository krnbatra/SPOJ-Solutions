#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
#define MOD                 1000000007LL
#define EPS                 1e-9
#define io                  ios_base::sync_with_stdio(false);cin.tie(NULL);

const int MAXN = 1e5+5;

int main(){
	io;
	int q;
	cin >> q;
	deque<int> dq;
	int rev = 0;
	while(q--){
		string str;
		cin >> str;
		if(str == "back"){
			if(dq.size() == 0)
				cout << "No job for Ada?" << endl;
			else{
				if(rev%2 == 0){
					cout << dq.back() << endl;
					dq.pop_back();
				}else{
					cout << dq.front() << endl;
					dq.pop_front();
				}
			}
		}else if(str == "front"){
			if(dq.size() == 0)
				cout << "No job for Ada?" << endl;
			else{
				if(rev%2 == 0){
					cout << dq.front() << endl;
					dq.pop_front();
				}else{
					cout << dq.back() << endl;
					dq.pop_back();
				}
			}
		}else if(str == "reverse"){
			rev++;
		}
		else if(str == "push_back"){
			int x;
			cin >> x;
			if(rev%2 == 0){
				dq.push_back(x);
			}else
				dq.push_front(x);
		}else if(str == "toFront"){
			int x;
			cin >> x;
			if(rev%2 == 0){
				dq.push_front(x);
			}else
				dq.push_back(x);
		}
	}
	return 0;
}