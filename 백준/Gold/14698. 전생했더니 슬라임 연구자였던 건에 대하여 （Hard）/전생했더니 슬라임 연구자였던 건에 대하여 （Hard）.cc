#include <iostream>
#include <vector>
#include <queue>


using namespace std;
long long p = 1000000007;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t; cin >> t;
    while(t--){
    	int n; cin >> n;
    	priority_queue<long long> pq;
    	for(int i=0;i<n;i++){
    		long long a; cin >> a;
    		pq.push(-a);
		}
		long long sum=1;
		while(pq.size()>=2){
			long long x=pq.top(); pq.pop();
			long long y=pq.top(); pq.pop();
			sum*=((x%p)*(y%p))%p;
			sum%=p;
			pq.push(-(x*y));
		}
		cout << sum << '\n';
	}
    return 0;
}