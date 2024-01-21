#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define MAX 300001
using namespace std;
typedef long long ll;
int n;
map<int,int> m;
vector<int> tmp;
vector<pair<int,int> > v;
ll seg[MAX*4];



void update(int k,int l,int r,int node){
	if(l>k || k>r) return;
	if(l==r){
		seg[node]+=1;
		return;
	} 
	int mid=(l+r)/2;
	update(k,l,mid,node*2);
	update(k,mid+1,r,node*2+1);
	seg[node]=seg[node*2]+seg[node*2+1];
}


ll query(int s,int e,int l,int r,int node){	
	if(s>r || e<l) return 0;
	if(s<=l && r<=e) return seg[node];	
	int mid=(l+r)/2;
	return query(s,e,l,mid,node*2)+query(s,e,mid+1,r,node*2+1);
}




int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t; cin >> t;
	while(t--){
		cin >> n;
		for(int i=1;i<=n;i++){
			int a,b; cin >> a >> b;
			v.push_back({a,b});
			if(!m[b]){
				m[b]=1;
				tmp.push_back(b);	
			}
		}
		sort(tmp.rbegin(),tmp.rend());
		int idx=1;
		for(auto i : tmp){
			m[i]=idx++;
		}
		n=idx-1;
		for(int i=0;i<v.size();i++){
			v[i].second=m[v[i].second];
		}
		sort(v.begin(),v.end());
		
		ll ans=0;
		for(pair<int,int> i : v){
			int a=i.first,b=i.second;
			ans+=query(1,b,1,n,1);
			update(b,1,n,1);
		}
		m.clear();
		v.clear();
		tmp.clear();
		fill(seg,seg+(MAX*4),0);
		cout << ans << '\n';	
	}
	
	
	
	
	return 0;
}