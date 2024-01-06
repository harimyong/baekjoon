#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef long long ll;
const int MAX = 200001;
ll n,m,k,t,q;
ll arr[MAX];

struct node{
	ll min=INF,tot=0;
};

node seg[MAX*4];
ll lazy[MAX*4];

node merge(node a,node b){
	struct node ret;
	ret.min=min(a.min,b.min);
	ret.tot=a.tot+b.tot;
	return ret;
}

ll mid(ll l,ll r){
	return (l+r)/2;
}

void init(int l,int r,int node){
	if(l==r){
		seg[node].min=arr[l];
		seg[node].tot=arr[l];
		return;
	}
	init(l,mid(l,r),node*2);
	init(mid(l,r)+1,r,node*2+1);
	seg[node]=merge(seg[node*2],seg[node*2+1]);
}

void prop(int l,int r,int node){
	if(lazy[node]){
		seg[node].tot+=((r-l+1)*lazy[node]);
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
		ret.tot=0;
		return ret;	
	}
	if(s<=l && r<=e) return seg[node];
	return merge(query(s,e,l,mid(l,r),node*2),query(s,e,mid(l,r)+1,r,node*2+1));
}

int main(){
	ios::sync_with_stdio(false); // C++ 입출력 버퍼 동기화 해제
    cin.tie(NULL); // cin과 cout의 묶임을 해제하여 버퍼 분리
	cout.tie(NULL);
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> arr[i];
	init(1,n,1);
	while(q--){
		char c; int a,b,v;
		cin >> c;
		if(c=='M'){
			cin >> a >> b;
			cout << query(a,b,1,n,1).min << '\n';
		}else if(c=='P'){
			cin >> a >> b >> v;
			update(a,b,1,n,1,v);
		}else{
			cin >> a >> b;
			cout << query(a,b,1,n,1).tot << '\n';
		}
	}
	

	return 0;
}