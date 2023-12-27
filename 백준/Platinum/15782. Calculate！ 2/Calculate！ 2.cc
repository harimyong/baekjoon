#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdlib>
#include <queue>
#define MAX 100001
#define INF 100000000
using namespace std;
typedef pair<long long,long long> pii;
typedef long long ll;
int n,q;
ll stree[MAX*4]={0,};
vector<vector<int> > graph;
ll arr[MAX];
ll lazy[MAX*4];
ll in[MAX],out[MAX];

ll cnt=0;
bool visit[MAX];
void dfs(int x){
	in[x]=++cnt;
	visit[x]=true;
	for(auto next : graph[x]){
		if(!visit[next]){
			dfs(next);
		}
	}
	out[x]=cnt;
}

void init(int l,int r,int nd){
	if(l==r) { stree[nd]=arr[l]; return;}
	int mid=(l+r)/2;
	init(l,mid,nd*2);
	init(mid+1,r,nd*2+1);
	stree[nd]=(stree[nd*2]^stree[nd*2+1]);
}

void prop(int l,int r,int nd){
	if(lazy[nd]!=0){
		if((r-l+1)%2==1)
		stree[nd]^=lazy[nd];
		if(l!=r){
			lazy[nd*2]^=lazy[nd];
			lazy[nd*2+1]^=lazy[nd];
		}
		lazy[nd]=0;
	}
}

void update(int s,int e,int l,int r,int nd,int v){
	prop(l,r,nd);
	
	if(s>r || e<l) return;
	
	if(s<=l && r<=e){
		lazy[nd]^=v	;
		prop(l,r,nd);
		return;
	}
	int mid=(l+r)/2;
	update(s,e,l,mid,nd*2,v);
	update(s,e,mid+1,r,nd*2+1,v);
	stree[nd]=(stree[nd*2]^stree[nd*2+1]);
}

ll query(int s,int e,int l,int r,int nd){
	prop(l,r,nd);
	if(s>r || e<l) return 0;
	if(s<=l && r<=e) return stree[nd];
	return (query(s,e,l,(l+r)/2,nd*2)^query(s,e,(l+r)/2+1,r,nd*2+1));
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> q;
	graph.resize(n+1);
	for(int i=1;i<=n-1;i++){
		int a,b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		update(in[i],in[i],1,n,1,arr[i]);
	}
	
	
	while(q--){
		int a,b,c;
		cin >> a >> b;
		if(a==1){
			cout << query(in[b],out[b],1,n,1) << '\n';
		}
		else if(a==2){
			cin >> c;
			update(in[b],out[b],1,n,1,c);
		}
	}
	
	
	return 0;
}
