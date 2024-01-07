#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
int n,m;
ll arr[MAX];
ll stree[MAX*4],lazy[MAX*4];

void prop(int l,int r,int node){
	if(lazy[node]){
		stree[node]+=(r-l+1)*lazy[node];
		if(l!=r){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

void update(int s,int e,int l,int r,int node,ll v){
	prop(l,r,node);
	if(s>r || e<l) return;
	if(s<=l && r<=e){
		lazy[node]+=v;
		prop(l,r,node);
		return;
	}
	int mid=(l+r)/2;
	update(s,e,l,mid,node*2,v);
	update(s,e,mid+1,r,node*2+1,v);
	stree[node]=stree[node*2]+stree[node*2+1];
}

ll query(int l,int r,int node,int k){
	prop(l,r,node);
	if(l>k || k>r) return 0;
	if(l==r) return stree[node];
	int mid=(l+r)/2;
	return query(l,mid,node*2,k)+query(mid+1,r,node*2+1,k);
}


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	while(n--){
		int a,b;
		cin >> a >> b;
		ll s=query(1,MAX,1,a),e=query(1,MAX,1,b);
		update(a,a,1,MAX,1,-s);
		update(b,b,1,MAX,1,-e);
		update(a+1,b-1,1,MAX,1,1);
		cout << s+e << '\n';
	}
	
	return 0;
}
