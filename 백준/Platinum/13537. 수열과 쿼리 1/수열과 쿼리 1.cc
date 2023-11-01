#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100001
using namespace std;
typedef long long ll;
int n,m;
ll arr[SIZE]={0,};
vector<vector<int> > stree;

vector<int> init(int l,int r, int node){
	if(l==r){
		stree[node].push_back(arr[l]);
		return stree[node];
	}
	int mid=(l+r)/2;
	init(l,mid,node*2);
	init(mid+1,r,node*2+1);
	stree[node]=stree[node*2];
	stree[node].insert(stree[node].end(),stree[node*2+1].begin(),stree[node*2+1].end());
	sort(stree[node].begin(),stree[node].end());
	return stree[node];
}

void update(int l,int r,int idx,int val,int node){
		
}

ll query(int s,int e,int l,int r,int node,int k){
	if(l>e or r<s) return 0;
	
	if(s<=l and r<=e){
		return stree[node].end()-upper_bound(stree[node].begin(),stree[node].end(),k);
	}
	
	int mid=(l+r)/2;
	return query(s,e,l,mid,node*2,k)+query(s,e,mid+1,r,node*2+1,k);
}




int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n ;
	for(int i=1;i<=n;i++)
		cin >> arr[i];
	stree.resize(n*4);
	init(1,n,1);
	cin >> m;
	while(m--){
		int a,b,c; cin >> a >> b >> c;
		cout << query(a,b,1,n,1,c) << '\n';
		
	}
	
		
	return 0;
}