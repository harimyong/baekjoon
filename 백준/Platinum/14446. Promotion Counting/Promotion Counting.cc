#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000000
using namespace std;
typedef long long ll;
const int MAX = 100005;
int n;
ll arr[MAX];
vector<vector<ll> > graph;
vector<ll> seg[MAX*4];

bool visit[MAX];
ll cnt=0,in[MAX],out[MAX];
ll skill[MAX];
void dfs(int x){
	visit[x]=true;
	in[x]=++cnt;
	skill[in[x]]=arr[x];
	for(auto next : graph[x]){
		if(!visit[next]) dfs(next);
	}
	out[x]=cnt;
}

void init(int l,int r,int node){
	if(l==r){
		seg[node].push_back(skill[l]);
		return;
	}
	init(l,(l+r)/2,node*2);
	init((l+r)/2+1,r,node*2+1);
	seg[node]=seg[node*2];
	seg[node].insert(seg[node].end(),seg[node*2+1].begin(),seg[node*2+1].end());
	sort(seg[node].begin(),seg[node].end());
}

ll query(int s,int e,int l,int r,int node,int val){
	if(s>r || l>e) return 0;
	if(s<=l && r<=e) return (r-l+1)-(upper_bound(seg[node].begin(),seg[node].end(),val)-seg[node].begin());
	return query(s,e,l,(l+r)/2,node*2,val)+query(s,e,(l+r)/2+1,r,node*2+1,val);
}

int main(){
	ios::sync_with_stdio(0); // C++ 입출력 버퍼 동기화 해제
    cin.tie(0); // cin과 cout의 묶임을 해제하여 버퍼 분리
	cout.tie(0);
	cin >> n;
	graph.resize(n+1);
//	for(int i=1;i<=MAX*4;i++) seg[i]={};
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=2;i<=n;i++) { int a; cin >> a; graph[a].push_back(i); }
	dfs(1);
	init(1,n,1);
//	for(int i=1;i<=n;i++){
//		cout << i << ' ' << in[i] << ' ' << out[i] << '\n';
//	}
	
	//for(int i=1;i<=n;i++) update(1,n,1,in[i],arr[i]);
	
	for(int i=1;i<=n;i++){
		cout << query(in[i],out[i],1,n,1,arr[i]) << '\n';
	}
	
		
	return 0;
}