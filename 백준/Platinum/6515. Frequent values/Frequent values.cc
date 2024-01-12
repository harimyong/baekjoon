#pragma GCC optmize("Ofast")
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 100500
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

bool isnotzero(int i){
	return i!=0;
}
int cnt[MAX],arr[MAX],ans[MAX],d[MAX*2];
vector<Query> query;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while(1){
    
	    cin >> n; if(n==0) break;
	    cin >> q; sqrtN=sqrt(n);
		for(int i=1;i<=n;i++) {
			int a; cin >> a;
			arr[i]=a+100000;	
		}
		
		for(int i=0;i<q;i++){
			int s,e; cin >> s >> e;
			query.push_back({s,e,i});
		}
		sort(query.begin(),query.end());
		
		int s=query[0].s, e=query[0].e,res=0;
		//cout << s << ' ' << e << '\n';
		for(int i=s;i<=e;i++){
			cnt[d[arr[i]]]--;
			d[arr[i]]++;
			cnt[d[arr[i]]]++;
			res=max(res,d[arr[i]]);
		}
		
		ans[query[0].idx]=res;
		
		
		for(int i=1;i<q;i++){
			while(s<query[i].s){
				cnt[d[arr[s]]]--;
				if(cnt[res]==0) res--;
				d[arr[s]]--;
				cnt[d[arr[s]]]++;
				s++;
			}
			while(s>query[i].s){
				s--;
				cnt[d[arr[s]]]--;
				d[arr[s]]++;
				cnt[d[arr[s]]]++;
				if(cnt[res+1]) res++;
			}
			while(e<query[i].e){
				e++;
				cnt[d[arr[e]]]--;
				d[arr[e]]++;
				cnt[d[arr[e]]]++;
				if(cnt[res+1]) res++;
			}
			while(e>query[i].e){
				cnt[d[arr[e]]]--;
				if(cnt[res]==0) res--;
				d[arr[e]]--;
				cnt[d[arr[e]]]++;
				e--;
			}
			ans[query[i].idx]=res;
		}
		for(int i=0;i<q;i++) cout << ans[i] << '\n';
    	fill(cnt,cnt+MAX,0);
    	fill(arr,arr+MAX,0);
    	fill(ans,ans+MAX,0);
    	fill(d,d+(MAX*2),0);
    	query.clear();
	}
	
	
 	return 0;
 }