#pragma GCC optmize("Ofast")
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 100001
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

int d[MAX*10],arr[MAX],ans[MAX],res=0;
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
	
	int s=query[0].s, e=query[0].e;
	//cout << s << ' ' << e << '\n';
	for(int i=s;i<=e;i++){
		d[arr[i]]++;
	}
	res+=count_if(d,d+MAX*10,isnotzero);
	ans[query[0].idx]=res;
	
	for(int i=1;i<q;i++){
		while(s<query[i].s){
			d[arr[s]]--;
			if(!d[arr[s]]) res--;
			s+=1;
		}
		while(s>query[i].s){
			s-=1;
			if(!d[arr[s]]) res++;
			d[arr[s]]++;
		}
		while(e<query[i].e){
			e+=1;
			if(!d[arr[e]]) res++;
			d[arr[e]]++;
		}
		while(e>query[i].e){
			d[arr[e]]--;
			if(!d[arr[e]]) res--;
			e--;
		}
		ans[query[i].idx]=res;
	}
	for(int i=0;i<q;i++) cout << ans[i] << '\n';
	
 	return 0;
 }