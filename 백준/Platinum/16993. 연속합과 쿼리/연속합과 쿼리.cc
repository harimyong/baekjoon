#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef long long ll;
const int MAX = 100001;
int n,q,u,v;
ll arr[MAX];

struct node{
	ll tot,lmax,rmax,tmax;
};

node seg[MAX*4];

ll mid(int l,int r){
	return (l+r)/2;
}

node merge(node a,node b){
	node ret;
	ret.tot=a.tot+b.tot;
	ret.lmax=max(a.lmax,a.tot+b.lmax);
	ret.rmax=max(b.rmax,b.tot+a.rmax);
	ret.tmax=max({a.tmax,b.tmax,a.rmax+b.lmax});
	return ret;
}

void init(int l,int r,int node){
	if(l==r){
		seg[node]={arr[l],arr[l],arr[l],arr[l]};
		return;
	}
	init(l,mid(l,r),node*2);
	init(mid(l,r)+1,r,node*2+1);
	seg[node]=merge(seg[node*2],seg[node*2+1]);
}

void update(int l,int r,int node,int k,int val){
	if(l>k || k>r) return;
	if(l==r){
		seg[node]={val,val,val,val};
		return;
	}
	update(l,mid(l,r),node*2,k,val);
	update(mid(l,r)+1,r,node*2+1,k,val);
	seg[node]=merge(seg[node*2],seg[node*2+1]);	
}

node query(int s,int e,int l,int r,int node){
	if(s>r || l>e) return {0,-INF,-INF,-INF};
	if(s<=l && r<=e) return seg[node];
	return merge(query(s,e,l,mid(l,r),node*2),query(s,e,mid(l,r)+1,r,node*2+1));
}


int main(){
	ios::sync_with_stdio(false); // C++ 입출력 버퍼 동기화 해제
    cin.tie(NULL); // cin과 cout의 묶임을 해제하여 버퍼 분리
	cout.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}	
	init(1,n,1);
	cin >> q;
	while(q--){
		int a,b; cin >> a >> b;
		cout << query(a,b,1,n,1).tmax << '\n';
	}
	return 0;
}