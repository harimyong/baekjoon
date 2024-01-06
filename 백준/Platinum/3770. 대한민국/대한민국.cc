#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000
using namespace std;
typedef long long ll;
const int MAX = 1001;
ll n,m,k,t;
vector<ll> graph[400000];

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

void update(ll l,ll r,ll node,ll k,ll val){
	if(l>k || k>r) return;
	if(l==r && k==l){
		seg[node]+=val;
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
	cin >> t;
	for(ll test=1;test<=t;test++){
		cin >> n >> m >> k;
		while(k--){
			ll a,b; cin >> a >> b;
			graph[a].push_back(b);
		}
		for(ll i=1;i<=n;i++)
		sort(graph[i].begin(),graph[i].end());
		ll tot=0;
		for(ll i=1;i<=n;i++){
			for(auto x : graph[i]){
				tot += query(x+1,m,1,m,1);
				update(1,m,1,x,1);
			}
		}
		cout << "Test case " << test << ": " << tot << '\n';	
        for(ll i=1;i<=n;i++)
		graph[i].clear();
        fill(seg,seg+(MAX*4),0);
	}

	return 0;
}