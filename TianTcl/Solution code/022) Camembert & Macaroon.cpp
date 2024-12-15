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

/* Algorith by TianTcl (copied) *//*
const int maxSize = 3001;
uint dp[maxSize][maxSize], weight[maxSize], value[maxSize];
void real_process() {
	uint couple, gifts; cin >> couple >> gifts;
	loopi1(couple) cin >> value[i];
	loopi1(couple) cin >> weight[i];
	loopi1(couple) loopj(gifts + 1) {
		dp[i][j] = dp[i - 1][j];
		if(j - weight[i] >= 0) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
	} cout << dp[couple][gifts];
	// getchar();
	return;
} */

/* Algorithm by Beta Jinatta Sriboonjaroenchai *//*
const int maxG = 3001, maxP = 1001;
ll arr[maxG], dp[maxP][maxG];
void real_process() {
	uint P, G; cin >> P >> G;
	loopi1(G) cin >> arr[i];
	loopi1(P) loopj1(G) {
		if (j < i * 2) dp[i][j] = TM;
		else dp[i][j] = min(dp[i][j - 1], dp[i - 1][j - 2] + arr[j] - arr[j - 1]);
	} cout << dp[P][G];
	// getchar();
	return;
} */

/* Algorithm by Ren Achira */
void real_process() {
	uint P, G; cin >> P >> G;
	uint a, b; cin >> a;
	multiset<int> Answer;
	loopi1(G - 1) {
		cin >> b;
		Answer.insert(b - a);
		a = b;
	} int Tuo = 0, Count = 0;
	for (auto i = Answer.begin(); i != Answer.end() && Count < P; i++) {
		Tuo += *i;
		Count += 1;
	} cout << Tuo;
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