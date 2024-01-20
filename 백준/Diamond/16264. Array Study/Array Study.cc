#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath> 
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
deque<int> dq[MAX*2];
int arr[MAX*2],bucket[SIZE*2],cnt[MAX*2];
long long ans=0;

void Push(int idx,int flag){
	int length=0;
	if(!dq[arr[idx]].empty()){
		length=dq[arr[idx]].back()-dq[arr[idx]].front();
		cnt[length]--;
		bucket[length/sqrtN]--;
	}	
	if(flag) dq[arr[idx]].push_front(idx);
	else dq[arr[idx]].push_back(idx);
	length=dq[arr[idx]].back()-dq[arr[idx]].front();
	cnt[length]++;
	bucket[length/sqrtN]++;	
}

void Pop(int idx,int flag){
	int length=0;
	if(!dq[arr[idx]].empty()){
		length=dq[arr[idx]].back()-dq[arr[idx]].front();
		cnt[length]--;
		bucket[length/sqrtN]--;
	}
	if(flag) dq[arr[idx]].pop_front();
	else dq[arr[idx]].pop_back();
	if(!dq[arr[idx]].empty()){
		length=dq[arr[idx]].back()-dq[arr[idx]].front();
		cnt[length]++;
		bucket[length/sqrtN]++;	
	}
}

int getResult(){
	for(int i=SIZE-1;i>=0;i--){
		if(!bucket[i]) continue;
		for(int j=sqrtN-1;j>=0;j--){
			if(cnt[i*sqrtN+j]){
				return i*sqrtN+j;
			}
		}
	}
}


int main(){
	ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> arr[i];
			arr[i]+=arr[i-1];
		}
		for(int i=0;i<=n;i++){
			arr[i]+=100000;
		}
		
		cin >> q;
		for(int i=0;i<q;i++){
			int s,e; cin >> s >> e;
			query.push_back({s-1,e,i});
		}
		sort(query.begin(),query.end());
		
		int s=query[0].s,e=query[0].e,idx=query[0].idx;
		for(int i=s;i<=e;i++){
			Push(i,0);
		} 
		ans=getResult();
		for(int i=1;i<q;i++){
			idx=query[i].idx;
			while(query[i].s < s) Push(--s,1);
			while(e < query[i].e) Push(++e,0);
			while(query[i].e < e) Pop(e--,0);
			while(s < query[i].s) Pop(s++,1);
			
			ans+=getResult();
		}
		cout << ans << '\n';	
		for(int i=0;i<MAX*2;i++) dq[i].clear();
		query.clear();
		fill(arr,arr+(MAX*2),0);	
		fill(cnt,cnt+(MAX*2),0);
		fill(bucket,bucket+(SIZE*2),0);
	}
	
	

	return 0;
}


