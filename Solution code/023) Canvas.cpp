#include <stdio.h>
// #include <conio.h>
// #include <math.h>
// #include <cmath>
// #include <ctype.h>
// #include <stdlib.h>
#include <bits/stdc++.h>
// #include <string.h>
// #include <sstream>
// #include <algorithm>
// #include <regex>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef pair<uint, uint> pi;
typedef pair<uint, pi> pii;
typedef pair<ll,ll> pl;
// #define INFint numeric_limits<int>::max()
// #define INFfloat numeric_limits<float>::infinity()
#define st first
#define nd second
const int MX = 2e9 + 7;
const int LM = INT_MAX;
const int TM = 1e6 + 2;
const int TT = 1e5 + 3;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
const ll UI = 1e15;
#define loop(n) for (uint _ = 0; _ < n; _++)
#define loopi(n) for (uint i = 0; i < n; i++)
#define loopi1(n) for (uint i = 1; i <= n; i++)
#define loopj(n) for (uint j = 0; j < n; j++)
#define loopj1(n) for (uint j = 1; j <= n; j++)
#define loopk(n) for (uint k = 0; k < n; k++)
#define loopk1(n) for (uint k = 1; k <= n; k++)
#define mbr(n,m) get<m>(n)
#define DEBUG 0
#define CASES 0
#define endl "\n"
#define all(n) n.begin(), n.end()
#define allrev(n) n.rbegin(), n.rend()

typedef vector<string> pc;
void real_process() {
	uint doodlets, W, H, C, R; cin >> doodlets >> W >> H;
	char ref; string line;
	map<char, pair<pi, pc>> blueprint; pc plan, buffer;
	vector<uint> rowHeight(H, 0), colWidth(W, 0); pi size(0, 0);
	loopi(doodlets) {
		cin >> ref >> C >> R;
		buffer.clear();
		loop(R) {
			cin >> line;
			buffer.push_back(line);
		} blueprint[ref] = make_pair(make_pair(C, R), buffer);
	} loopi(H) {
		cin >> line;
		plan.push_back(line);
		loopj(W) {
			ref = plan[i][j];
			rowHeight[i] = max(rowHeight[i], blueprint[ref].st.nd);
			colWidth[j] = max(colWidth[j], blueprint[ref].st.st);
		}
	} cout << accumulate(all(colWidth), 0) << " " << accumulate(all(rowHeight), 0) << endl;
	loopi(H) loopk(rowHeight[i]) {
		loopj(W) {
			ref = plan[i][j];
			if (k < rowHeight[i] - blueprint[ref].st.nd) loop(colWidth[j]) cout << " ";
			else {
				loop(colWidth[j] - blueprint[ref].st.st) cout << " ";
				cout << blueprint[ref].nd[k - (rowHeight[i] - blueprint[ref].st.nd)];
			}
		} cout << endl;
	} // getchar();
	return;
}

int main() {
	#ifndef DEBUG
	freopen("test_case.in", "r", stdin);
	freopen("test_case.out", "w", stdout);
	#endif
	cin.tie(nullptr) -> ios::sync_with_stdio(false);
	int t(1);
	if (CASES) cin >> t;
	while(t--) real_process();
	return 0;
}