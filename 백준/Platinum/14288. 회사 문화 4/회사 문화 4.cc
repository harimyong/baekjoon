#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 100001
using namespace std;
typedef long long ll;
int n,m;
vector<vector<int> > arr;
vector<ll> stree;
vector<ll> stree2;

vector<pair<int,int> > range_tree;

//구간 트리 만들기 위함 
int cnt=0;
int dfs(int now){
//	cout << now << ' ';
	cnt++;
	int start=cnt;
	int fin=cnt;
	for(int next : arr[now]){
		fin=dfs(next);
	}
	range_tree[now]=make_pair(start,fin);
	return fin; 
}


void update(int x,ll val,bool flag){
	for(int i=x;i<=n;i+=(i&-i)){
		if(flag)
		stree[i]+=val;
		else
		stree2[i]+=val;	
	}
}

void range_update(int l,int r,ll val,bool flag){
	update(l,val,flag);
	update(r+1,-val,flag);
}

ll sum(int x,bool flag){
	ll result=0;
	for(int i=x;i>=1;i-=(i&-i)){
		if(flag)
		result+=stree[i];
		else
		result+=stree2[i];	
	}	
	return result;
}

ll range_query(int l, int r,bool flag){
	return sum(r,flag)-sum(l-1,flag);
}




int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	arr.resize(n+1); 
	stree.resize(n+1,0);
	stree2.resize(n+1,0);
	range_tree.resize(n+1);
	for(int i=1;i<=n;i++){
		int a; cin >> a;
		if(i!=1)
			arr[a].push_back(i);
	}
	
	//구간 트리 만들기 
	dfs(1);

	bool flag=true; 
	while(m--){
		int a,b,c;
		cin >> a;
		if(a==3){
			if(flag) flag=false;
			else flag=true;
		}else{
			if(flag){
				cin >> b;
				int l=range_tree[b].first;
				int r=range_tree[b].second;
				if(a==1){
					cin >> c;
					range_update(l,r,c,flag);
				}else if(a==2){
					cout << range_query(l,r,!flag)+sum(l,flag) << '\n';	
				}
			}else{
				cin >> b;
				int l=range_tree[b].first;
				int r=range_tree[b].second;
				if(a==1){
					cin >> c;
					update(l,c,flag);
				}else if(a==2){
					cout << range_query(l,r,flag)+sum(l,!flag) << '\n';	
				}	
			}	
		}
		
		
		
		
	}
	
	return 0;
}
