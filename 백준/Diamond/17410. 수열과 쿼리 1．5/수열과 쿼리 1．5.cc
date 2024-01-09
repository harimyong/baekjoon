#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#define MAX 100001
#define INF 100000000000
using namespace std;
typedef long long ll;
int n,q,sqrtN,bucket_size;
int arr[MAX];
vector<int> bucket[330];

void init(){
	cin >> n;
	sqrtN=sqrt(n);
	//cout << sqrtN << '\n';
	for(int i=1;i<=n;i++){
		cin >> arr[i];
		bucket[i/sqrtN].push_back(arr[i]);
	}//cout << '\n';
	for(int i=0;i<=n/sqrtN;i++) {
		sort(bucket[i].begin(),bucket[i].end());
	}
}

void update(int k,int v){
	for(int i=0;i<bucket[k/sqrtN].size();i++){
		if(arr[k]==bucket[k/sqrtN][i]){
			bucket[k/sqrtN][i]=v;
			arr[k]=v;
			break;
		}
	}
	sort(bucket[k/sqrtN].begin(),bucket[k/sqrtN].end());
}

int query(int l,int r,int k){
	int ret=0;
	if(l/sqrtN==r/sqrtN){
		for(int i=l;i<=r;i++) if(arr[i]>k) ret++;
	}else{
		for(int i=l;i<sqrtN*(l/sqrtN+1);i++) if(arr[i]>k) ret++;
		for(int i=sqrtN*(r/sqrtN);i<=r;i++) if(arr[i]>k) ret++;
		for(int i=l/sqrtN+1;i<r/sqrtN;i++) 
		ret+=bucket[i].end()-upper_bound(bucket[i].begin(),bucket[i].end(),k);
	}
	return ret;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	init();
	cin >> q;
	while(q--){
		int c;
		cin >> c;
		if(c==2){
			int a,b,k; cin >> a >> b >> k;
			cout << query(a,b,k) << '\n';
		}else{
			int k,v; cin >> k >> v;
			update(k,v);
		}
	}
	
	
 	return 0;
 }