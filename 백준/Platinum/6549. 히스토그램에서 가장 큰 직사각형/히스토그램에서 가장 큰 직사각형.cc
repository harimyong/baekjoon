#include <iostream>
#include <vector>
#include <algorithm>
#define INF 10000000000
using namespace std;
typedef long long ll;
const int MAX = 100005;
int n,q,u,v;
ll arr[MAX],seg[MAX*4];


ll mid(int l,int r){
	return (l+r)/2;
}

void init(int l,int r,int node){
	if(l==r) { seg[node]=l; return; }
	init(l,mid(l,r),node*2);
	init(mid(l,r)+1,r,node*2+1);
	seg[node] = arr[seg[node*2]]>arr[seg[node*2+1]] ? seg[node*2+1]:seg[node*2];
}

ll find_idx(int s,int e,int l,int r,int node){
	if(s>r || e<l) return 0;
	if(s<=l && r<=e) return seg[node];
	ll a=find_idx(s,e,l,mid(l,r),node*2);
	ll b=find_idx(s,e,mid(l,r)+1,r,node*2+1);
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
	ios::sync_with_stdio(false); // C++ 입출력 버퍼 동기화 해제
    cin.tie(NULL); // cin과 cout의 묶임을 해제하여 버퍼 분리
	cout.tie(NULL);
	arr[0]=INF;
	while(1){
		cin >> n;
		if(n==0) return 0;
		for(int i=1;i<=n;i++) cin >> arr[i];
		init(1,n,1);
		cout << getarea(1,n) << '\n';
	}
	
	return 0;
}