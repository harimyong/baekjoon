#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdlib>
#include <queue>
#define MAX 2050
#define INF 100000000
using namespace std;
typedef pair<int,long long> pii;

int n,m;
vector<long long> stree;
vector<long long> arr;

void init(int l,int r,int node){
	if(l==r){
		stree[node]=arr[l];
		return;
	}
	int mid=(l+r)/2;
	init(l,mid,node*2);
	init(mid+1,r,node*2+1);
	stree[node]=max(stree[node*2],stree[node*2+1]);
}

void update(int l,int r,int node,int idx){
	if(idx>r || idx<l) return;
	if(l==r){
		stree[node]=-1;
		return;
	}
	int mid=(l+r)/2;
	update(l,mid,node*2,idx);
	update(mid+1,r,node*2+1,idx);
	stree[node]=max(stree[node*2],stree[node*2+1]);
}


long long query(int l,int r,int node,long long diff){
	if(l==r) return l;
	int mid=(l+r)/2;
	long long leftval=stree[node*2];
	long long rightval=stree[node*2+1];
	if(leftval>=diff) return query(l,mid,node*2,diff);
	else if(rightval>=diff) return query(mid+1,r,node*2+1,diff);
	else return -1;
}



int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		cin >> n >> m;
		arr.resize(n+1);
		for(int i=1;i<=n;i++){
			cin >> arr[i];
		}
		stree.resize(n*4);
		init(1,n,1);
		unsigned long long tot=0;
		for(int i=1;i<=m;i++){
			long long a; cin >> a;
			long long ret=query(1,n,1,a);
			if(ret!=-1){
				update(1,n,1,ret);
				tot+=(ret*i);
			}
			
		}
		cout << tot << '\n';
		arr.clear();
		stree.clear();
	}
	
	
	return 0;
}