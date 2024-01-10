#pragma GCC optmize("Ofast")
#include <iostream>
#include <stack>
#include <map>
#define MAX 1000001
#define INF 100000000000
using namespace std;
int n,f[MAX];
stack<int> s,tmp,ans;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=1;i<=n;i++){
		int a; cin >> a;
		s.push(a);
		f[a]++;
	}
	
	while(!s.empty()){
		int cur = s.top(); s.pop();
		//cout << cur << ' ' << f[cur] << '\n';
		while(!tmp.empty() && f[cur]>=f[tmp.top()]){
			tmp.pop();
		}
		if(!tmp.empty()){
			ans.push(tmp.top());
		}else{
			ans.push(-1);
		}
		tmp.push(cur);
	}
	
	while(!ans.empty()){
		cout << ans.top() << ' ';
		ans.pop();
	}
	
	
	
	
 	return 0;
 }