#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5+5;
int n;
int parent[MAXN];
int size[MAXN];
set<pair<int, int> > s;
void initialize(){
	for(int i = 1;i <= n; i++){
		parent[i] = i;
		size[i] = 1;
		s.insert(make_pair(1, i));
	}
}
int root(int i){
	while(i!=parent[i]){
		parent[i] = parent[parent[i]];
		i = parent[i];
	}
	return i;
}
bool find(int a, int b){
	return root(a) == root(b);
}
void union1(int a, int b){
	int root_a = root(a);
	int root_b = root(b);
	
	if(root_a == root_b)
		return;
	
	s.erase(make_pair(size[root_a], root_a));
	s.erase(make_pair(size[root_b], root_b));
	if(size[root_a] < size[root_b]){
		parent[root_a] = root_b;
		size[root_b]+=size[root_a];
		s.insert(make_pair(size[root_b], root_b));
	}else{
		parent[root_b] = root_a;
		size[root_a]+=size[root_b];
		s.insert(make_pair(size[root_a], root_a));
	}
}

int main(){
    cin>>n;
    initialize();
    int q;
    cin>>q;
    while(q--){
        int a, b;
        cin>>a>>b;
        union1(a, b);
        set<pair<int, int> >::iterator it1 = s.end();
        it1--;
        cout<<(it1->first-s.begin()->first)<<endl;
    }
	return 0;
}