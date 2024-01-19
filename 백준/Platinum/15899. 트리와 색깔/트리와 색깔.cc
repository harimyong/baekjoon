#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000000
using namespace std;
typedef long long ll;
const int MAX = 200005;
int n,m,c;
int arr[MAX];
vector<int> graph[MAX];
vector<int> seg[MAX*4];

bool visit[MAX];
int cnt=0;
int in[MAX], out[MAX], color[MAX];
void dfs(int x){
	in[x]=++cnt;
	visit[x]=true;
	color[in[x]]=arr[x];
	for(auto next : graph[x]){
		if(!visit[next]) dfs(next);
	}
	out[x]=cnt;
}


void _init(int l,int r,int node){
	if(l==r){
		seg[node].push_back(color[l]);
		return;
	} 
	_init(l,(l+r)/2,node*2);
	_init((l+r)/2+1,r,node*2+1);
	seg[node]=seg[node*2];
	seg[node].insert(seg[node].end(),seg[node*2+1].begin(),seg[node*2+1].end());
	sort(seg[node].begin(),seg[node].end());
}

int _query(int s,int e,int l,int r,int node,int k){
	if(l>e || s>r) return 0;
	if(s<=l && r<=e) return (upper_bound(seg[node].begin(),seg[node].end(),k)-seg[node].begin());
	return _query(s,e,l,(l+r)/2,node*2,k)+_query(s,e,(l+r)/2+1,r,node*2+1,k);
}

void init(){
	_init(1,n,1);
}

int query(int s,int e,int k){
	return _query(s,e,1,n,1,k);	
}


int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cout.tie(0);
    
	cin >> n >> m >> c;
	for(int i=1;i<=n;i++) cin >> arr[i];
	for(int i=1;i<=n-1;i++){
		int a,b; cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	dfs(1);
	init();
	
	ll ans=0;
	while(m--){
		int a,b; cin >> a >> b;
		ans+=query(in[a],out[a],b);
		ans%=1000000007;
	}
	cout << ans;
	
	return 0;
}