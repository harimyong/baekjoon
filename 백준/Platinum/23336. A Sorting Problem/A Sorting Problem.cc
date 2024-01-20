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
	cin >> n;
	stree.resize(n*4,0);
	for(int i=0;i<n;i++){
//		cin >> pay[i];
		int a; cin >> a;
		arr.push_back({a,i});
//		cout << arr[i-1].num << ' ' << arr[i-1].idx << '\n';
	}
	
	sort(arr.begin(),arr.end());
	
//	dfs(1);
//	order.resize(n+1);
	init(0,n-1,1);
//	for(int i=0;i<n;i++)
//		cout << arr[i].num << ' ' << arr[i].idx << '\n'; 
	
	ll sum=0;
	for(int i=0;i<n;i++){
		sum+=query(0,arr[i].second-1,0,n-1,1);
//		cout << query(0,arr[i].idx,0,n-1,1)-1 << '\n';	
		update(0,n-1,1,arr[i].second);
	}
	cout << sum;
	return 0;
}



