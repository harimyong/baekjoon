#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define SIZE 500001
using namespace std;
typedef long long ll;
int n,m;
vector<vector<int> > arr;
vector<ll> pay;
vector<ll> stree;
ll lazy[SIZE*4]={0,};
vector<ll> order;

void init(int l,int r,int node){
	if(l==r){
		stree[node]=order[l];
		return;
	}
	int mid=(l+r)/2;
	init(l,mid,node*2);
	init(mid+1,r,node*2+1); 
	stree[node]=stree[node*2]+stree[node*2+1];
}

void lazy_update(int l,int r,int node){
	if(lazy[node]!=0){
		stree[node]+=(r-l+1)*lazy[node];
		if(l!=r){
			lazy[node*2+1]+=lazy[node]; 
			lazy[node*2]+=lazy[node];
		}
		lazy[node]=0;
	}
}

void range_update(int s,int e,int l,int r,int node,ll val){
	lazy_update(l,r,node);
	
	if(s>r || e<l) return;
	
	if(s<=l && r<=e){
		lazy[node]+=val;
		lazy_update(l,r,node);
		return;
	}
	
	int mid=(l+r)/2;
	range_update(s,e,l,mid,node*2,val);
	range_update(s,e,mid+1,r,node*2+1,val);
	stree[node]=stree[node*2]+stree[node*2+1];
}

ll query(int idx,int l,int r,int node){
	lazy_update(l,r,node);
	 
	if(idx>r || idx<l) return 0;
	
	if(l==r && l==idx) return stree[node];
	
	int mid=(l+r)/2;
	return query(idx,l,mid,node*2)+query(idx,mid+1,r,node*2+1);
}

int cnt=0;
int in[SIZE],out[SIZE];
void dfs(int now){
	in[now]=++cnt;
	for(auto i : arr[now])
		dfs(i);
	out[now]=cnt;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	arr.resize(n+1);
	stree.resize(n*4,0);
	pay.resize(n+1,0);
	for(int i=1;i<=n;i++){
//		cin >> pay[i];
		int a; cin >> a;
		if(i!=1){
			arr[a].push_back(i);
		}
	}
	
	dfs(1);
//	order.resize(n+1);
//	for(int i=1;i<=n;i++)
//		order[in[i]]=pay[i];
//	init(1,n,1);

	while(m--){
		int a,b,c;
		cin >> a >> b;
		if(a==1){
			cin >> c;
			range_update(in[b],out[b],1,n,1,c);
		}else{
			cout << query(in[b],1,n,1) << '\n';
		}
		
//		for(int i=1;i<n*4;i++){
//			cout << stree[i] << ' ';
//		}cout << '\n';
	}
	
	return 0;
}
