#pragma GCC optmize("Ofast")
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 1000001
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

int arr[MAX],ans[MAX],d[MAX],res=0;
vector<Query> query;
map<int,int> v;
bool check[MAX];

bool isnotzero(int i){
	return i!=0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> q; sqrtN=sqrt(n);
	int idx=1;
	for(int i=1;i<=n;i++) {
		cin >> arr[i];
		if(!v[arr[i]]){
			v[arr[i]]=idx;
			arr[i]=idx;
			idx++;
		}else{
			arr[i]=v[arr[i]];
		}
	}
	
	//cin >> q;
	for(int i=0;i<q;i++){
		int s,e; cin >> s >> e;
		query.push_back({s,e,i});
	}
	sort(query.begin(),query.end());
	
	int s=query[0].s, e=query[0].e;
	//cout << s << ' ' << e << '\n';
	for(int i=s;i<=e;i++){
		d[arr[i]]++;
		if(d[arr[i]]==2){
			res++;
			check[arr[i]]=true;
		}else if(d[arr[i]]==3){
			check[arr[i]]=false;
			res--;
		}
	}
	ans[query[0].idx]=res;
	
	for(int i=1;i<q;i++){
		while(s<query[i].s){
			d[arr[s]]--;
			if(d[arr[s]]==2){
				res++;
				check[arr[s]]=true;
			}else if(d[arr[s]]==1){
				check[arr[s]]=false;
				res--;
			}
			s+=1;
		}
		while(s>query[i].s){
			s-=1;
			d[arr[s]]++;
			if(d[arr[s]]==2){
				res++;
				check[arr[s]]=true;
			}else if(d[arr[s]]==3){
				check[arr[s]]=false;
				res--;
			}
		}
		while(e<query[i].e){
			e+=1;
			d[arr[e]]++;
			if(d[arr[e]]==2){
				res++;
				check[arr[e]]=true;
			}else if(d[arr[e]]==3){
				check[arr[e]]=false;
				res--;
			}
		}
		while(e>query[i].e){
			d[arr[e]]--;
			if(d[arr[e]]==2){
				res++;
				check[arr[e]]=true;
			}else if(d[arr[e]]==1){
				check[arr[e]]=false;
				res--;
			}
			e--;
		}
		ans[query[i].idx]=res;
	}
	for(int i=0;i<q;i++) cout << ans[i] << '\n';
	
 	return 0;
 }