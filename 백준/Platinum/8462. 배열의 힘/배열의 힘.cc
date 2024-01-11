#pragma GCC optmize("Ofast")
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 1000001
#define INF 100000000000
typedef long long ll;
using namespace std;

int n,q,sqrtN;

struct Query{
	int s,e,idx;
	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s < x.s;
		else return e < x.e;
	}
};

ll d[MAX],arr[MAX],ans[MAX];
vector<Query> query;

bool isnotzero(int i){
	return i!=0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q; sqrtN=sqrt(n);
	for(int i=1;i<=n;i++) cin >> arr[i];

	for(int i=0;i<q;i++){
		int s,e; cin >> s >> e;
		query.push_back({s,e,i});
	}
	sort(query.begin(),query.end());
	
	ll s=query[0].s, e=query[0].e;
	ll res=0;
	for(int i=s;i<=e;i++){
		res-=d[arr[i]]*d[arr[i]]*arr[i];
		d[arr[i]]++;
		res+=d[arr[i]]*d[arr[i]]*arr[i];
	}
	
	ans[query[0].idx]=res;

	for(int i=1;i<q;i++){
		while(s<query[i].s){
			res-=d[arr[s]]*d[arr[s]]*arr[s];
			d[arr[s]]--;
			res+=d[arr[s]]*d[arr[s]]*arr[s];
			s++;
		}
		while(s>query[i].s){
			s--;
			res-=d[arr[s]]*d[arr[s]]*arr[s];
			d[arr[s]]++;
			res+=d[arr[s]]*d[arr[s]]*arr[s];
		}
		while(e<query[i].e){
			e++;
			res-=d[arr[e]]*d[arr[e]]*arr[e];
			d[arr[e]]++;
			res+=d[arr[e]]*d[arr[e]]*arr[e];
		}
		while(e>query[i].e){
			res-=d[arr[e]]*d[arr[e]]*arr[e];
			d[arr[e]]--;
			res+=d[arr[e]]*d[arr[e]]*arr[e];
			e--;
		}
		
//		cout << s << ' ' << e << ' ' << res << '\n';
//		for(int j=1;j<=10;j++) cout << d[j] << ' '; cout << "\n\n";
	
		ans[query[i].idx]=res;
	}
	for(int i=0;i<q;i++) cout << ans[i] << '\n';
	
 	return 0;
 }