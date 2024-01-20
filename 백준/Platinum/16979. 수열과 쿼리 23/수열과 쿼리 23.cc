#include <iostream>
#include <algorithm>
#include <cmath> 
#include <map>
#include <vector>
#define MAX 100001
#define sqrtN 500
using namespace std;
const int SIZE=MAX/sqrtN+100;
int n,k,q;
struct Query{
	int s,e,idx;
	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s<x.s;
		return e<x.e;
	}
};

vector<Query> query;
vector<int> v;
int arr[MAX],seg[MAX*4];
long long ans[MAX];
long long res=0;
map<int,int> m;

void update(int x,int val){
	for(;x<=n;x+=(x&-x)){
		seg[x]+=val;
	}
}

long long get(int x){
	long long ans=0;
	for(;x>0;x-=(x&-x)){
		ans+=seg[x];
	}
	return ans;
}

int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		if(!m[arr[i]]){
			m[arr[i]]=1;
			v.push_back(arr[i]);
		}
	}
	sort(v.begin(),v.end());
	int idx=1;
	for(auto i : v){
		m[i]=idx++;
	}
	for(int i=1;i<=n;i++){
		arr[i]=m[arr[i]];
	}
	
	for(int i=0;i<q;i++){
		int s,e; cin >> s >> e;
		query.push_back({s,e,i});
	}
	sort(query.begin(),query.end());
		
	int s=query[0].s,e=query[0].e;
	idx=query[0].idx;
	for(int i=s;i<=e;i++){
		update(arr[i],1);
		res+=get(n)-get(arr[i]);
	} 
	ans[idx]=res;
	
	for(int i=1;i<q;i++){
		idx=query[i].idx;
		while(query[i].s < s){
			s--;
			update(arr[s],1);
			res+=get(arr[s]-1);			
		}
		while(s < query[i].s){
			res-=get(arr[s]-1);
			update(arr[s],-1);
			s++;
		}
		while(e < query[i].e){
			e++;
			update(arr[e],1);
			res+=get(n)-get(arr[e]);
		}	
		while(query[i].e < e){
			res-=get(n)-get(arr[e]);
			update(arr[e],-1);
			e--;
		}
		
		ans[idx]=res;
	}
	for(int i=0;i<q;i++) cout << ans[i] << '\n';
		
	return 0;
}


