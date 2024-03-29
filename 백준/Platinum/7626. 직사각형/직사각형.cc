#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 400000
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n;

struct ST{
	int x;
	pii y;
	int val;
	bool operator < (ST &i){
		return x<i.x;
	}
};

vector<ST> arr;
vector<int> y;
ll seg[(MAX+1)*4],cnt[(MAX+1)*4];

void update(int s,int e,int l,int r,int node,int val){
	if(l>e || s>r) return;
	if(s<=l && r<=e){
		cnt[node]+=val;
	}else{
		int mid=(l+r)/2;
		update(s,e,l,mid,node*2,val);
		update(s,e,mid+1,r,node*2+1,val);	
	}
	
	if(cnt[node]) seg[node]=y[r]-y[l-1];
	else{
		if(l==r) seg[node]=0;
		else seg[node]=seg[node*2]+seg[node*2+1];	
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	for(int i=1;i<=n;i++){
		int a,b,c,d; cin >> a >> b >> c >> d;
		arr.push_back({a,{c,d},1});
		arr.push_back({b,{c,d},-1});
		y.push_back(c);
		y.push_back(d);
	}
	sort(arr.begin(),arr.end());
	sort(y.begin(),y.end());
	y.erase(unique(y.begin(),y.end()),y.end());
	
	ll ans=0;
	for(int i=0;i<arr.size();i++){
		if(i>0) ans+=(seg[1]*(arr[i].x-arr[i-1].x));
		int a=arr[i].y.first,b=arr[i].y.second;
		a=lower_bound(y.begin(),y.end(),a)-y.begin()+1;
		b=lower_bound(y.begin(),y.end(),b)-y.begin();
		update(a,b,1,MAX,1,arr[i].val);
	}
	cout << ans;
	
	return 0;
}