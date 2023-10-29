#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
vector<int> stree;
vector<int> arr;
int update(int l, int r, int idx, int val, int node){
	
	if(l>idx || r<idx){
		return stree[node];
	}
	
	if(l==r){
		stree[node]=val;
		return stree[node];	
	}
	
	int mid=(l+r)/2;
	int lv=update(l,mid,idx,val,node*2);
	int rv=update(mid+1,r,idx,val,node*2+1);
	stree[node]=lv+rv;
	return stree[node];
}

int query(int s, int e, int l, int r, int node){

    if (s>r || e<l)
        return 0;
    if (s<=l && r<=e)
        return stree[node];
    int mid=(l+r)/2;
    int lv=query(s,e,l,mid,node*2);
    int rv=query(s,e,mid+1,r,node*2+1);
    return lv+rv;
}



int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	stree.resize(n*4,0);
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		arr.push_back(a);
	}
    
	long long tot=0;
	for (int i=0; i<n; i++) {
     	   tot+=arr[i]-1-query(1,arr[i]-1,1,n,1);
     	   update(1,n,arr[i],1,1);
    }
    cout << tot;
 
	
	
	return 0;
}