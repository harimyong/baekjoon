#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define SIZE 500001
using namespace std;
typedef long long ll;
int n,m;

vector<ll> pay;
vector<ll> stree;
ll lazy[SIZE*4]={0,};
vector<ll> order;

vector<pair<int,int> > arr;

void init(int l,int r,int node){
	if(l==r){
		stree[node]=1;
		return;
	}
	int mid=(l+r)/2;
	init(l,mid,node*2);
	init(mid+1,r,node*2+1);
	stree[node]=stree[node*2]+stree[node*2+1];
}

void update(int l,int r,int node,int idx){
	if(idx>r || idx<l) return;
	
	if(l==r && idx==l){
		stree[node]=0;
		return;
	}
	
	int mid=(l+r)/2;
	update(l,mid,node*2,idx);
	update(mid+1,r,node*2+1,idx);
	stree[node]=stree[node*2]+stree[node*2+1];
}

ll query(int s,int e,int l,int r,int node){
	if(s>r || e<l) return 0;
	if(s<=l && r<=e) return stree[node];
	int mid=(l+r)/2;
	return query(s,e,l,mid,node*2)+query(s,e,mid+1,r,node*2+1);
	
}

//int cnt=0;
//int in[SIZE],out[SIZE];
//void dfs(int now){
//	in[now]=++cnt;
//	for(auto i : arr[now])
//		dfs(i);
//	out[now]=cnt;
//}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		cin >> n;
		stree.resize(n*4,0);
		for(int i=0;i<n;i++){
			int a; cin >> a;
			arr.push_back({a,i});
		}
		sort(arr.begin(),arr.end());
		
		init(0,n-1,1);
		
		int start=0,fin=n-1;
		ll ans=0;
		bool flag=true;
		while(start<=fin){
			if(flag){
				ans+=query(0,arr[start].second-1,0,n-1,1);
				update(0,n-1,1,arr[start].second);
				start++;
			}else{
				ans+=query(arr[fin].second+1,n-1,0,n-1,1);
				update(0,n-1,1,arr[fin].second);
				fin--;
			}
			flag=!flag;
		}
		cout << ans << '\n';	
		arr.clear();
		stree.clear();
	}
	
	return 0;
}
