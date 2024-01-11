#pragma GCC optmize("Ofast")
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 1000001
#define INF 100000000000
using namespace std;

int n,c,q,sqrtN;

struct Query{
	int s,e,idx;
	bool operator < (Query &x){
		if(s/sqrtN != x.s/sqrtN) return s < x.s;
		else return e < x.e;
	}
};

int arr[MAX],ans[MAX],d[MAX],res=0;
vector<Query> query;

bool isnotzero(int i){
	return i!=0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> c; sqrtN=sqrt(n);
	for(int i=1;i<=n;i++) {
		cin >> arr[i];
	}
	
	cin >> q;
	for(int i=0;i<q;i++){
		int s,e; cin >> s >> e;
		query.push_back({s,e,i});
	}
	sort(query.begin(),query.end());
	
	int s=query[0].s, e=query[0].e;
	for(int i=s;i<=e;i++){
		d[arr[i]]++;
	}
	for(int i=1;i<=c;i++){
		if(d[i]>(e-s+1)/2){
			res=i;
			break;
		}
	}
	ans[query[0].idx]=res;
	
	for(int i=1;i<q;i++){
		while(s<query[i].s){
			d[arr[s]]--; s++;
		}
		while(s>query[i].s){
			s--; d[arr[s]]++; 
		}
		while(e<query[i].e){
			e++; d[arr[e]]++;
		}
		while(e>query[i].e){
			d[arr[e]]--; e--;
		}
		
		res=0;
		for(int i=1;i<=c;i++){
			if(d[i]>(e-s+1)/2){
				res=i;
				break;
			}
		}
		
		ans[query[i].idx]=res;
	}
	for(int i=0;i<q;i++){
		if(!ans[i]) cout << "no\n";
		else cout << "yes " << ans[i] << '\n';		
	}

	
 	return 0;
 }