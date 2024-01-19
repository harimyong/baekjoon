#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100001
#define MAX 1000000001
using namespace std;
typedef long long ll;
int n,m;
vector<int> arr;
vector<ll> stree[SIZE*4];
void init(int l, int r ,int node){
	if(l==r){
		stree[node].push_back(arr[l]);
		return;
	} 
	int mid=(l+r)/2;
	init(l,mid,node*2);
	init(mid+1,r,node*2+1);
	stree[node]=stree[node*2];
	stree[node].insert(stree[node].end(),stree[node*2+1].begin(),stree[node*2+1].end());
	sort(stree[node].begin(),stree[node].end());
}
ll query(int s,int e,int l,int r,int node,int k){
	if(l>e or r<s) return 0;	
	if(s<=l and r<=e) return upper_bound(stree[node].begin(),stree[node].end(),k)-stree[node].begin();
	int mid=(l+r)/2;
	return query(s,e,l,mid,node*2,k)+query(s,e,mid+1,r,node*2+1,k);
}


int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m ;
	arr.resize(n+1,0); 
	for(int i=1;i<=n;i++)
		cin >> arr[i];
		
	init(1,n,1);
	while(m--){
		int a,b,c;
		cin >> a >> b >> c;
		int l=-MAX,r=MAX;
		while(l<=r){
			int mid=(l+r)/2;
			if(query(a,b,1,n,1,mid)<c) l=mid+1;
			else r=mid-1;
		}
		cout << l << '\n';
	}
	
	return 0;
}
