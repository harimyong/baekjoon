#include <bits/stdc++.h>
#define MAX 100001
#define sqrtN 500
using namespace std;

const int SIZE = MAX/sqrtN+50;

struct Query{
	int s, e, x;
	bool operator < (Query &x) {
		if(s/sqrtN != x.s/sqrtN) return s < x.s;
		return e < x.e;
	}
};

int n, k, q;
int arr[MAX];
vector<Query> qry;

list<int> pos[MAX];
int cnt[MAX], bucket[SIZE];
int ans[MAX];

void Plus(int x, int dir){
	int now = 0;
	auto &dq = pos[arr[x]];
	if(!dq.empty()){
		now = dq.back() - dq.front();
		cnt[now]--;
		bucket[now/sqrtN]--;
	}
	if(!dir) dq.push_front(x);
	else dq.push_back(x);
	now = dq.back() - dq.front();
	cnt[now]++; bucket[now/sqrtN]++;
}

void Minus(int x, int dir){
	auto &dq = pos[arr[x]];
	int now = dq.back() - dq.front();
	cnt[now]--; bucket[now/sqrtN]--;
	if(!dir) dq.pop_front();
	else dq.pop_back();
	if(!dq.empty()){
		now = dq.back() - dq.front();
		cnt[now]++; bucket[now/sqrtN]++;
	}
}

int query(){
	for(int i=SIZE-1; i>=0; i--){
		if(bucket[i]==0) continue;
		for(int j=sqrtN-1; j>=0; j--){
			if(cnt[i*sqrtN+j]>0){
				return i*sqrtN+j;
			}
		}
	}
	return 0;
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> arr[i];
	cin >> q;
	for(int i=0; i<q; i++){
		int s,e;
		cin >> s >> e;
		qry.push_back({s,e,i});
	}
	sort(qry.begin(),qry.end());

	int s = qry[0].s, e = qry[0].e, x = qry[0].x;
	for(int i=s; i<=e; i++){
		Plus(i, 1);
	}
	ans[x] = query();

	for(int i=1; i<q; i++){
		x = qry[i].x;
		while(qry[i].s < s) Plus(--s, 0);
		while(e < qry[i].e) Plus(++e, 1);
		while(s < qry[i].s) Minus(s++, 0);
		while(qry[i].e < e) Minus(e--, 1);
		ans[x] = query();
	}

	for(int i=0; i<q; i++) cout << ans[i] << "\n";
}
