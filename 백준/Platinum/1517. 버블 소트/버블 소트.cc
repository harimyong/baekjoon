#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair<int, int>> arr;
vector<int> tree;

int init(int start, int end, int node) {
    if (start == end) return tree[node] = 1;
    return tree[node] = init(start, (start+end)/2, node*2) + init((start+end)/2+1, end, node*2+1);
}

int query(int start, int end, int left, int right, int node) {
    if (right < start || left > end) return 0;
    if (left <= start && end <= right) return tree[node];
    return query(start, (start+end)/2, left, right, node*2) + query((start+end)/2+1, end, left, right, node*2+1);
}

void update(int start, int end, int idx, int node, int value) {
    if (start > idx || end < idx) return;
    if (start == end) {
        if (start == idx) tree[node] = value;
        return;
    }
    update(start, (start+end)/2, idx, node*2, value);
    update((start+end)/2+1, end, idx, node*2+1, value);
    tree[node] = tree[node*2] + tree[node*2+1];
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        arr.push_back({x, i});
    }

    int h = (int)ceil(log2(N));
    int size = (1<<h+1);
    tree.resize(size);
    init(0, N-1, 1);
    sort(arr.begin(), arr.end());

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        int q = arr[i].second;
        ans += query(0, N-1, 0, q, 1)-1;
        update(0, N-1, q, 1, 0);
    }
    cout << ans;
    return 0;
}