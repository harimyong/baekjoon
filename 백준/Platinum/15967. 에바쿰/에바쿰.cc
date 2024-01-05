#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000000
using namespace std;
typedef long long ll;
const int MAX = 1000005;
int n,q1,q2;
ll arr[MAX];
vector<vector<ll> > graph;
ll seg[MAX*4],lazy[MAX*4];
void init(int l,int r,int node){
	if(l==r){
		seg[node]=arr[l];
		return;
	}
	init(l,(l+r)/2,node*2);
	init((l+r)/2+1,r,node*2+1);
	seg[node]=seg[node*2]+seg[node*2+1];
}

void prop(int l,int r,int node){
	if(lazy[node]){
		seg[node]+=(r-l+1)*lazy[node];
		if(l!=r){
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
}

void update(int s,int e,int l,int r,int node,int v){
	prop(l,r,node);
	if(s>r || e<l) return;
	if(s<=l && r<=e){
		lazy[node]+=v;
		prop(l,r,node);
		return;
	}
	update(s,e,l,(l+r)/2,node*2,v);
	update(s,e,(l+r)/2+1,r,node*2+1,v);
	seg[node]=seg[node*2]+seg[node*2+1];
}
ll query(int s,int e,int l,int r,int node){
	prop(l,r,node);
	if(s>r || l>e) return 0;
	if(s<=l && r<=e) return seg[node];
	return query(s,e,l,(l+r)/2,node*2)+query(s,e,(l+r)/2+1,r,node*2+1);
}

int main(){
	ios::sync_with_stdio(0); // C++ 입출력 버퍼 동기화 해제
    cin.tie(0); // cin과 cout의 묶임을 해제하여 버퍼 분리
	cout.tie(0);
	cin >> n >> q1 >> q2;
	for(int i=1;i<=n;i++) cin >> arr[i];
	init(1,n,1);
	int q=q1+q2;
	while(q--){
		int a,b,c,v;
		cin >> c;
		if(c==1){
			cin >> a >> b;
			cout << query(a,b,1,n,1) << '\n';
		}else{
			cin >> a >> b >> v;
			update(a,b,1,n,1,v);
		}
	}
	
		
	return 0;
}