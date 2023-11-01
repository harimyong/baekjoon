#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 500001
using namespace std;
typedef long long ll;
int n,m;
ll arr[SIZE]={0,};
vector<ll> stree;
ll lazy[SIZE*4]={0,};

ll init(int l,int r, int node){
	if(l==r){
		stree[node]=arr[l];
		return stree[node];
	}
	int mid=(l+r)/2;
	init(l,mid,node*2);
	init(mid+1,r,node*2+1);
	stree[node]=stree[node*2]^stree[node*2+1];
	return stree[node];
}

void propagation(int l,int r,int node){
	if(lazy[node]!=0){
		if((r-l+1)%2==1)
		stree[node]^=lazy[node];
		
		if(l!=r){
			lazy[node*2]^=lazy[node];
			lazy[node*2+1]^=lazy[node];
		}
		lazy[node]=0;
	}
}


void lazy_update(int s,int e,int l,int r,int node,ll val){
	propagation(l,r,node);
	
	if(s>r || l>e) return;
	
	if(s<=l && r<=e){
		stree[node]^=((r-l+1)%2)*val;
		if(l!=r){
			lazy[node*2]^=val;
			lazy[node*2+1]^=val;
		}
		return;
	}
	
	int mid=(l+r)/2;
	lazy_update(s,e,l,mid,node*2,val);
	lazy_update(s,e,mid+1,r,node*2+1,val);
	stree[node]=stree[node*2]^stree[node*2+1];
}


ll query(int s,int e,int l,int r,int node){
	propagation(l,r,node);
	
	if(s>r || l>e) return 0;
	
	if(s<=l && r<=e){
		return stree[node];
	}
	
	int mid=(l+r)/2;
	return query(s,e,l,mid,node*2)^query(s,e,mid+1,r,node*2+1);
}



int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n; 
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	stree.resize(SIZE*4,0);
	init(0,n-1,1);
	cin >> m; 
	
	
	
	while(m--){
		int com;
		int a,b;
		ll c;
		
		cin >> com >> a;
		
		if(com==1){
			cin >> b >> c;
			lazy_update(a,b,0,n-1,1,c);
		}else{
			cout << query(a,a,0,n-1,1) << '\n';
		}
	}
	
		
	return 0;
}