#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef long long ll;
const int MAX = 300001;
ll n,m,k,t;
ll arr[MAX];

struct node{
	ll tot=0;
};

ll seg[MAX*4];

ll mid(ll l,ll r){
	return (l+r)/2;
}

node merge(node a,node b){
	node ret;
	ret.tot=a.tot+b.tot;
	return ret;
}

void init(int l,int r,int node){
	if(l==r){
		seg[node]=arr[l];
		return;
	}
	init(l,mid(l,r),node*2);
	init(mid(l,r)+1,r,node*2+1);
	seg[node]=seg[node*2]+seg[node*2+1];
}

void update(ll l,ll r,ll node,ll k,ll val){
	if(l>k || k>r) return;
	if(l==r && k==l){
		if(k%2==1)
		seg[node]-=val;
		else seg[node]+=val;
		return;
	}
	update(l,mid(l,r),node*2,k,val);
	update(mid(l,r)+1,r,node*2+1,k,val);
	seg[node]=(seg[node*2]+seg[node*2+1]);	
}

ll query(int s,int e,int l,int r,int node){
	if(s>r || l>e) return 0;
	if(s<=l && r<=e) return seg[node];
	return (query(s,e,l,mid(l,r),node*2)+query(s,e,mid(l,r)+1,r,node*2+1));
}

void test(){
	for(int i=1;i<=n*4;i++){
		cout << seg[i] << ' ';
	}cout << '\n';
}


int main(){
	ios::sync_with_stdio(false); // C++ 입출력 버퍼 동기화 해제
    cin.tie(NULL); // cin과 cout의 묶임을 해제하여 버퍼 분리
	cout.tie(NULL);
	cin >> n >> t;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		if(i%2==1) arr[i]*=(-1);
	}
	init(1,n,1);
	while(t--){
		int a,b,c; cin >> c >> a >> b;
		if(c==1){
			ll ret=query(a,b,1,n,1);
			ret=ret<0 ? -ret : ret;
			cout << ret << '\n';
		}else{
			update(1,n,1,a,b);
		}
	}
	return 0;
}