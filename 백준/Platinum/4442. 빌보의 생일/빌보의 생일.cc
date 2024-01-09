#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#define MAX 200001
#define INF 100000000000
using namespace std;
typedef long long ll;
int n,q;
vector<ll> arr[MAX];
ll seg[MAX*4];

void update(int l,int r,int node,int k){
	if(l>k || k>r) return;
	if(l==r){
		seg[node]++;
		return;
	}
	update(l,(l+r)/2,node*2,k);
	update((l+r)/2+1,r,node*2+1,k);
	seg[node]=seg[node*2]+seg[node*2+1];
}

ll query(int s,int e,int l,int r,int node){
	if(s>r || l>e) return 0;
	if(s<=l && r<=e) return seg[node];
	return query(s,e,l,(l+r)/2,node*2)+query(s,e,(l+r)/2+1,r,node*2+1);
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while(1){
		cin >> n;
		if(n==0) break;
		map<string,int> dict;
		for(int i=1;i<=n;i++){
			string a; cin >> a;
			dict[a]=i;
		}
		for(int i=1;i<=n;i++){
			string a; cin >> a;
			arr[dict[a]].push_back(i);
		}
		ll tot=0;
		for(int i=1;i<=n;i++){
			for(auto x : arr[i]){
				//cout << x << '\n';
				tot+=query(x+1,n,1,n,1);
				update(1,n,1,x);
			}//cout << '\n';			
		}
		for(int i=1;i<=n;i++) arr[i].clear();
		fill(seg,seg+(MAX*4),0);
		
		cout << tot << '\n';
	}
 	return 0;
 }