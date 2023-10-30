#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>
#include <limits.h>
#include <vector>
#include <math.h>
#include <stack>
#include <bitset>
#include <string>
typedef long long ll;
using namespace std;
int n, m;
vector<int> tree, arr;
string s;
void input() {
		arr.resize(n);
		tree.resize(4 * n);
		for (int i = 0;i < n;i++) {
			cin >> arr[i];
			if (arr[i] > 0) arr[i] = 1;
			else if (arr[i] < 0) arr[i] = -1;

		}
}

int init(int i, int S, int E) {
	if (S == E) return tree[i] = arr[S];
	else return tree[i] = init(2 * i, S, (S + E) / 2)
		* init(2 * i + 1, (S + E) / 2 + 1, E);
}

int update(int i, int S, int E, int idx, int mul) {
	if (idx < S || E < idx) return tree[i];
	if (S == E) return tree[i] = mul;
	return tree[i] = update(2 * i, S, (S + E) / 2, idx, mul)
		*update(2 * i + 1, (S + E) / 2 + 1, E, idx, mul);

}
int query(int i, int S, int E, int L, int R) {
	if (E < L || R < S) return 1;
	if (L <= S && E <= R) return tree[i];
	return query(2 * i, S, (S + E) / 2, L, R) 
		* query(2 * i + 1, (S + E) / 2 + 1, E, L, R);
}

void output() {
	char a;
	int b, c;
	for (int i = 0;i < m;i++) {
		cin >> a >> b >> c;
		if (a == 'C') {
			if (c > 0) c = 1;
			else if (c < 0) c = -1;
			update(1, 0, n - 1, b - 1, c);
		}
		else {
			int res = query(1, 0, n - 1, b - 1, c - 1);
			if (res == 0)s+="0";
			else if (res > 0) s+= "+";
			else s+= "-";
		}
	}
	cout << s;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while (cin >> n >> m) {
		input();
		init(1, 0, n - 1);
		s = "";
		output();
		cout << '\n';
	}
	return 0;
}