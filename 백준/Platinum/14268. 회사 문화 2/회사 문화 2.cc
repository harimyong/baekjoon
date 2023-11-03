#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100001
using namespace std;
typedef long long ll;
int n,m;
ll lazy[SIZE*4]={0,};
vector<vector<int> > arr;
vector<ll> stree;

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

void lazy_update(int l,int r,int node){
	if(lazy[node]){
		stree[node]+=lazy[node];
		if(l!=r){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	return;
}

void update_range(int s,int e,int l,int r,int node,ll val){
	lazy_update(l,r,node);
	
	if(s>r || e<l) return;
	
	if(s<=l && r<=e){
		stree[node]+=val;
		if(l!=r){
			lazy[node*2]+=val;
			lazy[node*2+1]+=val;
		}
		return;
	} 
	
	int mid=(l+r)/2;
	update_range(s,e,l,mid,node*2,val);
	update_range(s,e,mid+1,r,node*2+1,val);
	stree[node]=stree[node*2]+stree[node*2+1];
}


ll query(int idx,int l,int r,int node){
	lazy_update(l,r,node);
	
	if(idx>r || idx<l) return 0;
	
	if(l==r && idx==l){
//		cout << l << ' ' << r << ' ' << stree[node] << '\n';
		return stree[node];	
	} 
	
	int mid=(l+r)/2;
	return query(idx,l,mid,node*2)+query(idx,mid+1,r,node*2+1);
}




int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
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
//	init(1,n,1);
	
	while(m--){
		int a,b,c;
		cin >> a >> b;
		int s=range_tree[b].first;
		int e=range_tree[b].second;
//		cout << s << ' ' << e << '\n';
		if(a==1){
			cin >> c;
			update_range(s,e,1,n,1,c);
//			for(int i=1;i<n*4;i++)
//				cout << stree[i] << ' ';
//			cout << '\n';
		}
		else{
			cout << query(s,1,n,1) << '\n';
		}
		
	}
	
	
	return 0;
}