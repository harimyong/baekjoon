#include<cstdio>
#include<queue>
#define mod int(1e9+7)
using namespace std;
int t, n;
int main() {
    for (scanf("%d", &t); t--;) {
        scanf("%d", &n);
        priority_queue<long long> pq;
        long long c, t;
        while (n--) scanf("%lld", &c), pq.push(-c);
        int res = 1;
        while (pq.size() > 1) {
            t = pq.top(); pq.pop();
            t *= pq.top(); pq.pop();
            res = t%mod*res%mod;
            pq.push(-t);
        }
        printf("%d\n", res);
    }
    return 0;
}