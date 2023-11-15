#include <iostream>
#include <vector>
#include <queue>


using namespace std;
int p = 1000000007;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    long long t,n,a;
    long long x,y,temp;
    cin >> t;
    for (int i = 0; i < t; i++) {
        priority_queue<long long> pq;
        long long sum = 1;
        cin >> n;
        for (long long j = 0; j < n; j++) {
            cin >> a;
            pq.push(-a);
        }
        while (pq.size() > 1) {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            temp = x * y;
            pq.push(-temp);
            temp = temp % p;
            sum = sum % p;
            sum = sum * temp;
			sum %= p;            
            
        }
        cout << sum << '\n';
    }
}