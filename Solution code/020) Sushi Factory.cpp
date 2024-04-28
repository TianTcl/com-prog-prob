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
typedef pair<int,int> pi;
typedef pair<int,pi> pii;
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
#define loop(n) for (int _ = 0; _ < n; _++)
#define loopi(n) for (int i = 0; i < n; i++)
#define loopi1(n) for (int i = 1; i <= n; i++)
#define loopj(n) for (int j = 0; j < n; j++)
#define loopj1(n) for (int j = 1; j <= n; j++)
#define mbr(n,m) get<m>(n)
#define DEBUG 0
#define CASES 0
#define endl "\n"
#define all(n) n.begin(), n.end()

struct Inquiry {
	uint dept, tmnl, price;
	Inquiry(uint dept, uint tmnl, uint price) : dept(dept), tmnl(tmnl), price(price) {}
	bool operator<(const Inquiry &other) const {
		return tmnl < other.tmnl;
	}
};
void real_process() {
	/* Algorithm by ChatGPT (original design) */
	uint n, dept, tmnl, price, inclProfit; cin >> n;
	vector<Inquiry> inq;
	loop(n) {
		cin >> price >> tmnl >> dept;
		inq.push_back(Inquiry(tmnl - dept + 1, tmnl, price));
	} sort(all(inq));
	vector<uint> dp(n);
	dp[0] = inq[0].price;
	int latestNonConflict;
	loopi1(n - 1) {
		latestNonConflict = -1;
		inclProfit = inq[i].price;
		loopj(i) if (inq[i - 1 - j].tmnl < inq[i].dept) {
			latestNonConflict = i - 1 - j; break;
		} if (latestNonConflict >= 0) inclProfit += dp[latestNonConflict];
		dp[i] = max(dp[i - 1], inclProfit);
	} cout << dp[n - 1] << endl;

	/* Algorithm by TianTcl *//*
	uint inquiries, maxPrice = 0, dept, tmnl, dist, tmpPrice;
	cin >> inquiries; vector<uint> prices(inquiries, 0);
	bool next; stack<pii> lookup; vector<pii> inquiry; pii buffer; vector<int> saves(inquiries, -1);
	loopi(inquiries) {
		cin >> dist >> tmnl >> dept;
		inquiry.push_back({dist, {tmnl - dept + 1, tmnl}});
		lookup.push({i, {0, i}});
	}; while(!lookup.empty()) {
		buffer = lookup.top(); lookup.pop();
		dist = inquiry[buffer.st].st; dept = inquiry[buffer.st].nd.st; tmnl = inquiry[buffer.st].nd.nd;
		next = false; tmpPrice = buffer.nd.st + dist;
		// printf("[Debugger]~$ Looking: %2d @%-2d [%-3d], next:", buffer.st, tmnl, buffer.nd.st + dist);
		loopi(inquiries) {
			if (i == buffer.st) continue;
			if (inquiry[i].nd.st > tmnl) {
				// cout << "[_R]~$ " << i << ": " << prices[i] << endl;
				if (!prices[i]) {
					lookup.push({i, {buffer.nd.st + dist, buffer.nd.nd}});
					// printf(" %d", i);
					next = true;
				} else tmpPrice = max(tmpPrice, buffer.nd.st + dist + prices[i]);
			}
		} if (!next) {
			// printf(", new: %3d | %3d", maxPrice, tmpPrice);
			maxPrice = max(maxPrice, tmpPrice);
			prices[buffer.nd.nd] = max(prices[buffer.nd.nd], tmpPrice);
		} // printf("\n");
	} cout << maxPrice << endl;
	// 5 / 10 - Timeouted */

	/* Algorithm by ChatGPT (from TianTcl, modified) *//*
	uint inquiries, dist, tmnl, dept, maxPrice = 0, tmpPrice;
	cin >> inquiries;
	vector<vector<int>> memo(inquiries, vector<int>(inquiries, -1));
	vector<uint> prices(inquiries, 0); vector<pii> inquiry;
	stack<pi> lookup; pi buffer;
	loop(inquiries) {
		cin >> dist >> tmnl >> dept;
		inquiry.push_back({dist, {tmnl - dept + 1, tmnl}});
	} loopi(inquiries) {
		lookup.push({i, 0});
		while(!lookup.empty()) {
			buffer = lookup.top(); lookup.pop();
			if (memo[i][buffer.st] >= 0) continue;
			tmpPrice = buffer.nd + inquiry[buffer.st].st;
			loopj(inquiries) {
				if (!(j != buffer.st && inquiry[j].nd.st > inquiry[buffer.st].nd.nd)) continue;
				if (prices[j] == 0) lookup.push({j, buffer.nd + inquiry[buffer.st].st});
				else tmpPrice = max(tmpPrice, buffer.nd + inquiry[buffer.st].st + prices[j]);
			} memo[i][buffer.st] = tmpPrice;
			maxPrice = max(maxPrice, tmpPrice);
		}
	} cout << maxPrice << endl;
	Completely wrong answer */
	// getchar();
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