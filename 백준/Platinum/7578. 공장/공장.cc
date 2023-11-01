#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define SIZE 500001
using namespace std;
typedef long long ll;
int n,m;
int start[SIZE]={0,};
int B[SIZE*2];

vector<int> stree;
map<ll, ll> dict;
//ll init(int l,int r, int node){
//	if(l==r){
//		stree[node]=arr[l];
//		return stree[node];
//	}
//	int mid=(l+r)/2;
//	init(l,mid,node*2);
//	init(mid+1,r,node*2+1);
//	stree[node]=stree[node*2]+stree[node*2+1];
//	return stree[node];
//}

void update(int l,int r,int idx,int val,int node){
	if (l>idx || r<idx)
        return;
    if(l==r){
        stree[node]=1;
        return;
	}
    int mid=(l+r)/2;
    update(l,mid,idx,val,node*2);
    update(mid+1,r,idx,val,node*2+1);
    stree[node]=stree[node*2]+stree[node*2+1];
}

ll query(int s,int e,int l,int r,int node){
	if(l>e || r<s) return 0;
	
	if(s<=l && r<=e){
		return stree[node];
	}
	
	int mid=(l+r)/2;
	return query(s,e,l,mid,node*2)+query(s,e,mid+1,r,node*2+1);
}




int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n ; 
	for(int i=0;i<n;i++){
		cin >> start[i];
	}
	for(int i=0;i<n;i++){
		int a; cin >> a;
		B[a]=i;
	}
	stree.resize(SIZE*4,0);
	ll tot=0;
	for(int i=0;i<n;i++){
		tot+=query(B[start[i]]+1,n-1,0,n-1,1);
		update(0,n-1,B[start[i]],1,1);
	}
	cout << tot;
	
	
		
	return 0;
}