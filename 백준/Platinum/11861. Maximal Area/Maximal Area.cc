#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000000
using namespace std;
typedef long long ll;
const int MAX = 1000005;
int n,q,u,v;
ll arr[MAX],seg[MAX*4];

ll init(int l,int r,int node){
	if(l==r) { return seg[node]=l; }
	ll a=init(l,(l+r)/2,node*2);
	ll b=init((l+r)/2+1,r,node*2+1);
	return seg[node] = arr[a]>arr[b] ? b : a;
}

ll find_idx(int s,int e,int l,int r,int node){
	if(s>r || e<l) return 0;
	if(s<=l && r<=e) return seg[node];
	ll a=find_idx(s,e,l,(l+r)/2,node*2);
	ll b=find_idx(s,e,(l+r)/2+1,r,node*2+1);
	return arr[a]>arr[b] ? b : a;
}

ll getarea(int l,int r){
	if(l>r) return 0;
	ll idx=find_idx(l,r,1,n,1);
	ll ret=(r-l+1)*arr[idx];
	ret=max(ret,getarea(l,idx-1));
	ret=max(ret,getarea(idx+1,r));
	return ret;
}

int main(){
	ios::sync_with_stdio(0); // C++ 입출력 버퍼 동기화 해제
    cin.tie(0); // cin과 cout의 묶임을 해제하여 버퍼 분리
	cout.tie(0);
	arr[0]=INF;
	cin >> n;
	for(int i=1;i<=n;i++) cin >> arr[i];
	init(1,n,1);
	cout << getarea(1,n) << '\n';
	
	return 0;
}