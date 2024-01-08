#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 250001
using namespace std;
typedef long long ll;
int n,m;
ll arr[10];
ll stree[MAX*4][10],lazy[MAX*4];

void init(int l,int r,int node,int i,int v){
	if(l>i || i>r) return;
	if(l==r){
		stree[node][v]+=1;
		return;
	}
	init(l,(l+r)/2,node*2,i,v);
	init((l+r)/2+1,r,node*2+1,i,v);
	stree[node][v]=stree[node*2][v]+stree[node*2+1][v];
}

void prop(int l,int r,int node){
	if(lazy[node]){
		for(int i=0;i<=9;i++){
			arr[(i+lazy[node])%10]=stree[node][i];
		}
		for(int i=0;i<=9;i++){
			stree[node][i]=arr[i];
		}
		if(l!=r){
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
	for(int i=0;i<=9;i++){
		stree[node][i]=(stree[node*2][i]+stree[node*2+1][i]);
	}
}

ll query(int s,int e,int l,int r,int node){
	prop(l,r,node);
	if(s>r || l>e) return 0;
	if(s<=l && r<=e){
		ll tot=0;
		for(int i=1;i<=9;i++){
			tot+=(stree[node][i]*i);
		}
		return tot;
	}
	return query(s,e,l,(l+r)/2,node*2)+query(s,e,(l+r)/2+1,r,node*2+1);
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		int x; scanf("%1d",&x);
		init(1,n,1,i,x);
	}
	while(m--){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",query(a,b,1,n,1));
		update(a,b,1,n,1);
	}
 	return 0;
 }