#pragma GCC optmize("Ofast")
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stack>
#include <string>
#define MAX 100001
#define INF 100000000000
using namespace std;
int n,k,arr[MAX];
string s;
stack<char> tmp,ans;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	cin >> s;
	int cnt=0;
	for(int i=0;i<s.size();i++){
		char cur = s[i];
		while(!tmp.empty() && tmp.top()<cur && cnt<k){
			tmp.pop(); cnt++;
		}
		//cout << cur << ' ' << cnt << '\n';
		tmp.push(cur);
	}
	while (cnt < k){
        cnt++;
        tmp.pop();
    }
	while(!tmp.empty()){
		ans.push(tmp.top()); tmp.pop();
	}
	while(!ans.empty()){
		cout << ans.top(); ans.pop();
	}
	
	
 	return 0;
 }