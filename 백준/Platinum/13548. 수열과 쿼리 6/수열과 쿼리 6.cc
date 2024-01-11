#pragma GCC optmize("Ofast")
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 100010
#define INF 100000000000
using namespace std;

int n,q,sqrtN;

struct Query{
	int s,e,idx;
	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s < x.s;
		else return e < x.e;
	}
};

int d[MAX],arr[MAX],ans[MAX],cnt[MAX];
vector<Query> query;

bool isnotzero(int i){
	return i!=0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n; sqrtN=sqrt(n);
	for(int i=1;i<=n;i++) cin >> arr[i];
	cin >> q;
	for(int i=0;i<q;i++){
		int s,e; cin >> s >> e;
		query.push_back({s,e,i});
	}
	sort(query.begin(),query.end());
	
	int s=query[0].s, e=query[0].e,res=0;
	for(int i=s;i<=e;i++){
		cnt[d[arr[i]]]--;
		d[arr[i]]++;
		cnt[d[arr[i]]]++;
		res=max(res,d[arr[i]]);
	}
	
	ans[query[0].idx]=res;
	//cout << s << ' ' << e << ' ' << res << '\n';
	
	for(int i=1;i<q;i++){
		while(s<query[i].s){
			cnt[d[arr[s]]]--;
			d[arr[s]]--;
			cnt[d[arr[s]]]++;
			if(cnt[res]==0) res--;
			s++;
		}
		while(s>query[i].s){
			s--;
			cnt[d[arr[s]]]--;
			d[arr[s]]++;
			cnt[d[arr[s]]]++;
			res=max(res,d[arr[s]]);
		}
		while(e<query[i].e){
			e++;
			cnt[d[arr[e]]]--;
			d[arr[e]]++;
			cnt[d[arr[e]]]++;
			res=max(res,d[arr[e]]);
		}
		while(e>query[i].e){
			cnt[d[arr[e]]]--;
			d[arr[e]]--;
			cnt[d[arr[e]]]++;
			if(cnt[res]==0) res--;
			e--;
		}
	
	
	
		ans[query[i].idx]=res;
	}
	for(int i=0;i<q;i++) cout << ans[i] << '\n';
	
 	return 0;
 }