#include <iostream>
#include <algorithm>
using namespace std;
int num[2002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    for(int i=0; i<n; i++) {
        cin >> num[i];
    }
    sort(num, num+n);
    int cnt = 0;
    for(int i=0; i<n; i++) {
        int left = 0, right = n-1;
        int key = num[i];
        
        while(left < right) {
            if(left == i) { left++;}
            else if (right == i) { right--;}
            else if (key > num[left] + num[right]){left++;}
            else if (key == num[left] + num[right]) {
                cnt++; break;
            } else { right --;}
        }
    }
    cout << cnt;
}