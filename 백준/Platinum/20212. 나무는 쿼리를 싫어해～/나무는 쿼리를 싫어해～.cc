#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;
typedef long long ll;
int n;

struct Query{
	ll com,k,a,b,val;
	bool operator < (Query &x){
		if(k!=x.k) return k<x.k;
		return com<x.com;
	}
};

struct NODE{
	NODE *l, *r;
	ll tot,lazy;
	NODE() { l=NULL, r=NULL, tot=0, lazy=0;}
};

vector<Query> query;
ll ans[60000];

void prop(ll l,ll r,NODE *node){
	if(node->lazy){
		node->tot+=(r-l+1)*(node->lazy);
		if(l!=r){
			if(!node->l) node->l=new NODE();
			if(!node->r) node->r=new NODE();
			node->l->lazy+=node->lazy;
			node->r->lazy+=node->lazy;
		}
		node->lazy=0;
	}
}

void update(ll s,ll e,ll l,ll r,NODE *node,ll val){
	prop(l,r,node);
	
	if(l>e || s>r) return;
	
	if(s<=l && r<=e){
		node->lazy+=val;
		prop(l,r,node);
		return;
	}
	
	ll mid=(l+r)/2;
	if(!node->l) node->l=new NODE();
	if(!node->r) node->r=new NODE();
	update(s,e,l,mid,node->l,val);
	update(s,e,mid+1,r,node->r,val);	
	node->tot=node->l->tot+node->r->tot;
}

ll getResult(ll s,ll e,ll l,ll r,NODE *node){
	if(!node) return 0;
	prop(l,r,node);
	if(l>e || s>r) return 0;
	if(s<=l && r<=e) return node->tot;
	ll mid=(l+r)/2;
	return getResult(s,e,l,mid,node->l)+getResult(s,e,mid+1,r,node->r);
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	int idx=1,check[60000];
	for(int i=1;i<=n;i++){
		int com,a,b,k; cin >> com >> a >> b >> k;
		if(com==1) query.push_back({com,idx++,a,b,k});
		else{
			check[i]=1;
			query.push_back({com,k,a,b,i});	
		}
	}
	sort(query.begin(),query.end());
	
	NODE *root=new NODE();
	for(int i=0;i<query.size();i++){
		Query v = query[i];
		ll com=v.com, k=v.k, a=v.a, b=v.b, val=v.val;
		if(com==1) update(a,b,1,MAX,root,val);
		else ans[val]=getResult(a,b,1,MAX,root);
	}
	for(int i=0;i<=n;i++) if(check[i]) cout << ans[i] << '\n';
	
	return 0;
}