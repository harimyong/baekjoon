#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cstdlib>
#include <queue>
#define MAX 2050
#define INF 100000000
#define MOD 1000000007
using namespace std;
typedef pair<long long,long long> pii;
typedef long long ll;
int n,q;
ll stree[100500*4]={0,};
ll arr[100500]={0,};
ll lazy[100500*4];
ll lazy2[100500*4]={0,};

void init(int l,int r,int nd){
	if(l==r) { stree[nd]=arr[l]; return;}
	int mid=(l+r)/2;
	init(l,mid,nd*2);
	init(mid+1,r,nd*2+1);
	stree[nd]=(stree[nd*2]+stree[nd*2+1])%MOD;
}

void prop(int l,int r,int nd){
	if(lazy[nd]==1 && lazy2[nd]==0) return;
	
	stree[nd]=(stree[nd]*lazy[nd]+(r-l+1)*lazy2[nd])%MOD;
	if(l!=r){
		lazy[nd*2]*=lazy[nd];
		lazy2[nd*2]*=lazy[nd];
		lazy2[nd*2]+=lazy2[nd];
		
		lazy[nd*2+1]*=lazy[nd];
		lazy2[nd*2+1]*=lazy[nd];
		lazy2[nd*2+1]+=lazy2[nd];
		
		lazy[nd*2]%=MOD;
		lazy2[nd*2]%=MOD;
		lazy[nd*2+1]%=MOD;
		lazy2[nd*2+1]%=MOD;
	}
	lazy[nd]=1;
	lazy2[nd]=0;
}

void update(int s,int e,int l,int r,int nd,int v1,int v2){
	prop(l,r,nd);
	
	if(s>r || e<l) return;
	
	if(s<=l && r<=e){
		lazy[nd]*=v1;
		lazy2[nd]*=v1;
		lazy2[nd]+=v2;
		
		lazy[nd]%=MOD;
		lazy2[nd]%=MOD;
		
		prop(l,r,nd);
		return;
	}
	int mid=(l+r)/2;
	update(s,e,l,mid,nd*2,v1,v2);
	update(s,e,mid+1,r,nd*2+1,v1,v2);
	stree[nd]=(stree[nd*2]+stree[nd*2+1])%MOD;
}

ll query(int s,int e,int l,int r,int nd){
	prop(l,r,nd);
	if(s>r || e<l) return 0;
	if(s<=l && r<=e) return stree[nd];
	return (query(s,e,l,(l+r)/2,nd*2)+query(s,e,(l+r)/2+1,r,nd*2+1))%MOD;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
	}
	init(1,n,1);
	fill(lazy,lazy+(100500*4),1);
	
	cin >> q;
	while(q--){
		int a,b,c,d;
		cin >> a >> b >> c;
		if(a==1){
			cin >> d;
			update(b,c,1,n,1,1,d);
		}
		else if(a==2){
			cin >> d;
			update(b,c,1,n,1,d,0);
		}	
		else if(a==3){
			cin >> d;
			update(b,c,1,n,1,0,d);
		}
		else if(a==4){
			cout << query(b,c,1,n,1) << '\n';
		}
	}
	
	
	return 0;
}