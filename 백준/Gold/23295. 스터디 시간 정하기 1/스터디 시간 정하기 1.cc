#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000
using namespace std;
typedef long long ll;
int n,t,k,Ms,Me;
ll seg[MAX*4],lazy[MAX*4],ans;

void prop(int s,int e,int node){
	if(lazy[node]){
		seg[node]+=((e-s+1)*lazy[node]);
		if(s!=e){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

void update(int s,int e,int l,int r,int node){
	prop(l,r,node);
	if(s>r || l>e) return;
	if(s<=l && r<=e){
		lazy[node]+=1;
		prop(l,r,node);
		return;
	}
	update(s,e,l,(l+r)/2,node*2);
	update(s,e,(l+r)/2+1,r,node*2+1);
	seg[node]=seg[node*2]+seg[node*2+1];
}

ll query(int s,int e,int l,int r,int node){
	prop(l,r,node);
	if(s>r || e<l) return 0;
	if(s<=l && r<=e) return seg[node];
	return query(s,e,l,(l+r)/2,node*2)+query(s,e,(l+r)/2+1,r,node*2+1);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> t;
	for(int i=1;i<=n;i++){
		cin >> k;
		for(int j=1;j<=k;j++){
			int a,b; cin >> a >> b;
			update(a,b-1,0,MAX,1);
		}
	}
	
	for(int i=0;i<=MAX-t;i++){
		ll ret=query(i,i+t-1,0,MAX,1);
		if(ret>ans){
			Ms=i;
			Me=i+t;
			ans=ret;
		}
		//cout << i << ' ' << i+t << ' ' << ret << '\n';
	}
	cout << Ms << ' ' << Me;
	
	return 0;
}