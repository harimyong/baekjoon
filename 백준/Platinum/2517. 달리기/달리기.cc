#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
vector<int> stree;
pair<int,int> pr;
vector<pair<int,int> > stat;
int update(int l, int r, int idx, int val, int node){
	
	if(l>idx || r<idx){
		return stree[node];
	}
	
	if(l==r){
		stree[node]=val;
		return stree[node];	
	}
	
	int mid=(l+r)/2;
	int lv=update(l,mid,idx,val,node*2);
	int rv=update(mid+1,r,idx,val,node*2+1);
	stree[node]=lv+rv;
	return stree[node];
}

int query(int s, int e, int l, int r, int node){

    if (s>r || e<l)
        return 0;
    if (s<=l && r<=e)
        return stree[node];
    int mid=(l+r)/2;
    int lv=query(s,e,l,mid,node*2);
    int rv=query(s,e,mid+1,r,node*2+1);
    return lv+rv;
}



int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	stree.resize(n*4,0);
	for(int i=0;i<n;i++){
		int a;
		cin >> a;
		stat.push_back(make_pair(a,i+1));
	}
    sort(stat.begin(), stat.end());
	for(int i=0;i<n;i++){
		stat[i].first=i+1;
		swap(stat[i].first, stat[i].second);
	}
	sort(stat.begin(), stat.end());
	
	for (int i = 0; i < n; i++) {
        int temp = stat[i].second;
		update(0,n-1,temp-1,1,1);
  		cout << i+1-query(0,temp-2,0,n-1,1) <<'\n';
    }
 
	
	
	return 0;
}