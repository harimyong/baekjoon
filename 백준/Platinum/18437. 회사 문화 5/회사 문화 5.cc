#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100001
using namespace std;
typedef long long ll;
int n,m;
vector<vector<int> > arr;
vector<ll> stree;
vector<ll> stree2;
ll lazy[SIZE*4]={0,};
vector<pair<int,int> > range_tree;

//구간 트리 만들기 위함 
int cnt=0;
int dfs(int now){
//	cout << now << ' ';
	cnt++;
	int start=cnt;
	int fin=cnt;
	for(int next : arr[now]){
		fin=dfs(next);
	}
	range_tree[now]=make_pair(start,fin);
	return fin; 
}

void init(int l,int r,int node){
	if(l==r){
		stree[node]=1;
		return;
	}
	
	int m=(l+r)/2;
	init(l,m,node*2);
	init(m+1,r,node*2+1);
	stree[node]=stree[node*2]+stree[node*2+1];
}

void lazy_update(int l,int r,int node){
	if(lazy[node]==1){
		stree[node]=(r-l+1);
		if(l!=r){
			lazy[node*2]=lazy[node];
			lazy[node*2+1]=lazy[node];
		}
	}
	else{
		stree[node]=0;
		if(l!=r){
			lazy[node*2]=lazy[node];
			lazy[node*2+1]=lazy[node];
		}
	}
	lazy[node]=0;
}

void update_range(int s,int e,int l,int r,int node,ll val){
	if(lazy[node])lazy_update(l,r,node);
	
	if(s>r || e<l) return;
	
	if(s<=l && r<=e){
		lazy[node]=val;
		lazy_update(l,r,node);
		return;
	}
	
	int m=(l+r)/2;
	update_range(s,e,l,m,node*2,val);
	update_range(s,e,m+1,r,node*2+1,val);
	stree[node]=stree[node*2]+stree[node*2+1];
}

ll query(int s,int e,int l,int r,int node){
	if(lazy[node])lazy_update(l,r,node);
	
	if(s>r || e<l) return 0;
	
	if(s<=l && r<=e) return stree[node];
	
	int m=(l+r)/2;
	return query(s,e,l,m,node*2) + query(s,e,m+1,r,node*2+1);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	arr.resize(n+1); 
	stree.resize(n*4,0);
	range_tree.resize(n+1);
	for(int i=1;i<=n;i++){
		int a; cin >> a;
		if(i!=1)
			arr[a].push_back(i);
	}
	
	//구간 트리 만들기 
	dfs(1);
	init(1,n,1);
	cin >> m;
	bool flag=true; 
	while(m--){
		int a,b,c;
		cin >> a >> b;
		int l=range_tree[b].first;
		int r=range_tree[b].second;
		if(a==1) update_range(l+1,r,1,n,1,1);
		else if(a==2) update_range(l+1,r,1,n,1,2);
		else cout << query(l+1,r,1,n,1) << '\n';
	}
	
	return 0;
}
