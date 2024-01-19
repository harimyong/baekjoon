#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;
typedef long long ll;
int n,t,q,arr[MAX],seg[MAX*4],lazy[MAX*4];

void prop(int l,int r,int node){
	if(lazy[node]!=0){
		seg[node]=lazy[node];
		if(l!=r){
			lazy[node*2]=lazy[node];
			lazy[node*2+1]=lazy[node];
		}
		lazy[node]=0;
	}
}

void update(int s,int e,int l,int r,int node,int k){
	prop(l,r,node);
	if(s>r || e<l) return;
	if(s<=l && r<=e){
		lazy[node]=k;
		prop(l,r,node);
		return;
	}
	update(s,e,l,(l+r)/2,node*2,k);
	update(s,e,(l+r)/2+1,r,node*2+1,k);
	seg[node]=seg[node*2] | seg[node*2+1];
}

int query(int s,int e,int l,int r,int node){
	prop(l,r,node);
	if(s>r || e<l) return 0;
	if(s<=l && r<=e) return seg[node];
	return query(s,e,l,(l+r)/2,node*2) | query(s,e,(l+r)/2+1,r,node*2+1);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> t >> q;
	update(1,n,1,n,1,1);
	while(q--){
		char c; int x,y,z; cin >> c;
		if(c=='C'){
			cin >> x >> y >> z;
			if(x>y) swap(x,y);
			update(x,y,1,n,1,1<<(z-1));
		}else{
			cin >> x >> y;
			if(x>y) swap(x,y);
			int ret=query(x,y,1,n,1);
			int ans=0;
			while(ret){
				ans+=(ret & 1);
				ret >>= 1;
			}
			cout << ans << '\n';
		}
	}
	
	return 0;
}
