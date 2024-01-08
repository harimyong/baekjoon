#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 500001
#define INF 100000000000
using namespace std;
typedef long long ll;
int n,q;
ll arr[MAX];

struct node{
	ll lv,rv,cnt;
	//ll tot;
};
node seg[MAX*4];

node merge(node a,node b){
	node ret;
	if(a.cnt!=0 && b.cnt!=0){
		ret.lv=a.lv;
		ret.rv=b.rv;
		if(a.rv==b.lv) ret.cnt=a.cnt+b.cnt-1;
		else ret.cnt=a.cnt+b.cnt;	
	}else if(a.cnt!=0){
		ret=a;
	}else{
		ret=b;
	}
	return ret;
}

void init(int l,int r,int node){
	if(l==r){ seg[node]={arr[l],arr[l],1}; return; }
	init(l,(l+r)/2,node*2);
	init((l+r)/2+1,r,node*2+1);
	seg[node]=merge(seg[node*2],seg[node*2+1]);
}

void update(int l,int r,int node,int k,int v){
	if(l>k || k>r) return;
	if(l==r){ seg[node].lv=v; seg[node].rv=v; seg[node].cnt=1; return; }
	update(l,(l+r)/2,node*2,k,v);
	update((l+r)/2+1,r,node*2+1,k,v);
	seg[node]=merge(seg[node*2],seg[node*2+1]);
}

node query(int s,int e,int l,int r,int node){
	if(s>r || e<l) return {};
	if(s<=l && r<=e) return seg[node];
	return merge(query(s,e,l,(l+r)/2,node*2),query(s,e,(l+r)/2+1,r,node*2+1));
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q;
	for(int i=1;i<=n;i++) cin >> arr[i];
	init(1,n,1);
	while(q--){
		int c,a,b; cin >> c >> a >> b;
		if(c==1){
			update(1,n,1,a,b);
		}else{
			cout << query(a,b,1,n,1).cnt << '\n';
		}
	}
 	return 0;
 }