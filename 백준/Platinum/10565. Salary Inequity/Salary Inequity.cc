#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1000005;

vector<vector<ll> > graph;
ll t,n,q,arr[MAX];

ll treemax[MAX*4],treemin[MAX*4];

ll cnt=0;
bool visit[MAX];
ll in[MAX],out[MAX];
void dfs(int x){
	visit[x]=true;
	in[x]=++cnt;
	for(auto next : graph[x]){
		if(!visit[next]){
			dfs(next);
		}
	}
	out[x]=cnt;
}

ll lazy[MAX*4];
void prop(int l,int r,int node){
	if(lazy[node]){
		treemax[node]+=lazy[node];
		treemin[node]+=lazy[node];
		if(l!=r){
			lazy[node*2+1]+=lazy[node];
			lazy[node*2]+=lazy[node];
		}else{
			arr[l]=treemax[node];
		}
		lazy[node]=0;
	}
}

ll mid(int l,int r){
	return (l+r)/2;
}

void update(int s,int e,int l,int r,int node,int v){
	prop(l,r,node);
	if(s>r || e<l) return;
	if(s<=l && r<=e){
		lazy[node]+=v;
		prop(l,r,node);
		return;
	}
	update(s,e,l,mid(l,r),node*2,v);
	update(s,e,mid(l,r)+1,r,node*2+1,v);
	treemax[node]=max(treemax[node*2],treemax[node*2+1]);
	treemin[node]=min(treemin[node*2],treemin[node*2+1]);
}

ll max_query(int s,int e,int l,int r,int node){
	prop(l,r,node);
	if(s>r || e<l) return 0;
	if(s<=l && r<=e) return treemax[node];
	return max(max_query(s,e,l,mid(l,r),node*2),max_query(s,e,mid(l,r)+1,r,node*2+1));
}

ll min_query(int s,int e,int l,int r,int node){
	prop(l,r,node);
	if(s>r || e<l) return 1e10;
	if(s<=l && r<=e) return treemin[node];
	return min(min_query(s,e,l,mid(l,r),node*2),min_query(s,e,mid(l,r)+1,r,node*2+1));
}

void test(){
	cout << "i in out sal max min\n";
	for(int i=1;i<=n;i++){
		cout << i << ' ' << in[i] << ' ' << out[i] << ' ' << \
		arr[in[i]] << ' ' << max_query(in[i],out[i],1,n,1) << ' ' << \
		min_query(in[i],out[i],1,n,1) << '\n';		
	}cout << '\n';
}

int main(){
	ios::sync_with_stdio(false); // C++ 입출력 버퍼 동기화 해제
    cin.tie(NULL); // cin과 cout의 묶임을 해제하여 버퍼 분리
	cout.tie(NULL);
	cin >> t;
	while(t--){
		cin >> n;
		graph.resize(n+1);
		for(int i=2;i<=n;i++){
			int a; cin >> a;
			graph[a].push_back(i);
		}
		dfs(1);
		for(int i=1;i<=n;i++){
			cin >> arr[in[i]];
			update(in[i],in[i],1,n,1,arr[in[i]]);
		}
		//cout << "====================================\n";
		//test();
		
		
		cin >> q;
		while(q--){
			char c; int a,b;
			cin >> c;
			if(c=='Q'){
				cin >> a;
				cout << max_query(in[a],out[a],1,n,1)-min_query(in[a],out[a],1,n,1) << '\n';
			}else{
				cin >> a >> b;
				update(in[a],out[a],1,n,1,b);
			}
			//test();
		}
		cnt=0;
		graph.clear();
		fill(arr,arr+MAX,0);
		fill(in,in+MAX,0);
		fill(out,out+MAX,0);
		fill(visit,visit+MAX,false);
		fill(lazy,lazy+(MAX*4),0);
		fill(treemax,treemax+(MAX*4),0);
		fill(treemin,treemin+(MAX*4),0);
	}
	
	
	
	return 0;
}