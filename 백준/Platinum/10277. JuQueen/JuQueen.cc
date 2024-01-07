#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define INF 1000000000
using namespace std;
typedef long long ll;
const int MAX = 4587600;
ll C,N,O;
ll arr[MAX];

struct node{
	ll max,min;
};

node seg[MAX*4];
ll lazy[MAX*4];

node merge(node a,node b){
	struct node ret;
	ret.max=max(a.max,b.max);
	ret.min=min(a.min,b.min);
	return ret;
}

ll mid(ll l,ll r){
	return (l+r)/2;
}

void init(int l,int r,int node){
	if(l==r){
		seg[node].min=0;
		seg[node].max=0;
		return;
	}
	init(l,mid(l,r),node*2);
	init(mid(l,r)+1,r,node*2+1);
	seg[node]=merge(seg[node*2],seg[node*2+1]);
}

void prop(int l,int r,int node){
	if(lazy[node]){
		seg[node].max+=lazy[node];
		seg[node].min+=lazy[node];
		if(l!=r){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

void update(int s,int e,ll l,ll r,ll node,ll val){
	prop(l,r,node);
	if(l>e || s>r) return;
	if(s<=l && r<=e){
		lazy[node]+=val;
		prop(l,r,node);
		return;
	}
	update(s,e,l,mid(l,r),node*2,val);
	update(s,e,mid(l,r)+1,r,node*2+1,val);
	seg[node]=merge(seg[node*2],seg[node*2+1]);	
}

node query(int s,int e,int l,int r,int node){
	prop(l,r,node);
	if(s>r || l>e){
		struct node ret;
		ret.min=INF;
		ret.max=0;
		return ret;	
	}
	if(s<=l && r<=e) return seg[node];
	return merge(query(s,e,l,mid(l,r),node*2),query(s,e,mid(l,r)+1,r,node*2+1));
}

int main(){
	ios::sync_with_stdio(false); // C++ 입출력 버퍼 동기화 해제
    cin.tie(NULL); // cin과 cout의 묶임을 해제하여 버퍼 분리
	cout.tie(NULL);
	cin >> C >> N >> O;
	init(0,C-1,1);
	while(O--){
		string com; cin >> com;
		int a,b,c;
		if(com=="state"){
			cin >> a;
			cout << query(a,a,0,C-1,1).max << '\n';
		}else if(com=="groupchange"){
			cin >> a >> b >> c;
			node ret=query(a,b,0,C-1,1);
			ll max=ret.max,min=ret.min;
			if(c>0 && c+max>N){
				update(a,b,0,C-1,1,N-max);
				cout << N-max << '\n';
			}else if(c<0 && c+min<0){
				update(a,b,0,C-1,1,-min);
				cout << -min << '\n';
			}else{
				update(a,b,0,C-1,1,c);
				cout << c << '\n';
			}
		}else if(com=="change"){
			cin >> a >> b;
			node ret=query(a,a,0,C-1,1);
			ll val=ret.max;
			//cout << ret.max << ' ' << ret.min<< '\n';
			if(b>0 && b+val>N){
				update(a,a,0,C-1,1,N-val);
				cout << N-val << '\n';
			}else if(b<0 && b+val<0){
				update(a,a,0,C-1,1,-val);
				cout << -val << '\n';
			}else{
				update(a,a,0,C-1,1,b);
				cout << b << '\n';
			}
		}
	}
	
	

	return 0;
}