#include <iostream>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

struct Q{
	int rt,sz;
	bool operator < (const Q& x) const{
		if(sz!=x.sz) return sz > x.sz;
		return rt < x.rt;
	}
};
int n,q;
set<Q> s;
int parent[100001],size[100001],cycle[100001];

int find(int x){
	if(parent[x]==x) return x;
	parent[x]=find(parent[x]);
	return parent[x];
}

void merge(int x,int y){
	x=find(x),y=find(y);
	s.erase({x,size[x]});
	s.erase({y,size[y]});
	if(x==y) cycle[x]=cycle[y]=1;
	else{
		if(cycle[x] || cycle[y]) cycle[x]=cycle[y]=1;
		else{
			if(x>y) swap(x,y);
			parent[y]=x;
			size[x]=size[y]=size[x]+size[y];
			s.insert({x,size[x]});
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for(int i=1;i<=n;i++){
		parent[i]=i; size[i]=1;
		s.insert({i,1});
	}
	while(q--){
		int c,a,b;
		cin >> c;
		if(c==1){
			cin >> a >> b;
			merge(a,b);
		}else{
			cout << (*s.begin()).rt << '\n';
			s.erase(s.begin());
		}
	}
	
	return 0;
}