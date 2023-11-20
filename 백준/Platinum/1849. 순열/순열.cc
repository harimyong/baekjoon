#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdlib>
#include <queue>
#define MAX 2050
#define INF 100000000
using namespace std;

int n,m;
vector<int> stree;
vector<int> arr;

void init(int l,int r,int node){
	if(l==r){
		stree[node]=1;
		return;
	}
	int mid=(l+r)/2;
	init(l,mid,node*2);
	init(mid+1,r,node*2+1);
	stree[node]=stree[node*2]+stree[node*2+1];
}

void update(int l,int r,int node,int idx){
	if(idx>r || idx<l) return;
	if(l==r){
		stree[node]=0;
		return;
	}
	int mid=(l+r)/2;
	update(l,mid,node*2,idx);
	update(mid+1,r,node*2+1,idx);
	stree[node]=stree[node*2]+stree[node*2+1];
}


int query(int l,int r,int node,int diff){
	if(l==r) return l;
	int mid=(l+r)/2;
	int k=stree[node*2];
	if(k>diff) return query(l,mid,node*2,diff);
	else return query(mid+1,r,node*2+1,diff-k);
}



int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	arr.resize(n+1);
	stree.resize(n*4,0);
	init(1,n,1);
	for(int i=0;i<n;i++){
		int a; cin >> a;
		int idx=query(1,n,1,a);
		arr[idx]=i+1;
		update(1,n,1,idx);
	}
	
	for(int i=1;i<=n;i++)
	cout << arr[i] << '\n';
	
	return 0;
}