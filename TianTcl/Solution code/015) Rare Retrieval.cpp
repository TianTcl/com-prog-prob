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

void real_process() {
	uint usage, rate, storage, destination; cin >> usage >> rate >> storage >> destination;
	uint barrel[destination], compression[destination]; loopi(destination) cin >> barrel[i] >> compression[i];
	uint pick[destination + 1][storage + 1]; memset(pick, 0, sizeof(pick));
	loopi(destination + 1) loopj(storage + 1) {
		if (!i || !j) pick[i][j] = 0;
		else if (barrel[i - 1] <= j) pick[i][j] = max(compression[i - 1] + pick[i - 1][j - barrel[i - 1]], pick[i - 1][j]);
		else pick[i][j] = pick[i - 1][j];
	}; uint most = pick[destination][storage], power = 0, ore = 0, j = storage;
	// printf("$[Debugger]~: total=%d\n$[Debugger]~: incl=", most);
	vector<uint> collected;
	for (uint i = destination; i > 0 && most > 0; i--) {
		if (most == pick[i - 1][j]) continue;
		// printf("%d ", barrel[i - 1]);
		power += compression[i - 1];
		collected.push_back(barrel[i - 1]);
		ore += barrel[i - 1] * compression[i - 1];
		most -= compression[i - 1];
		j -= barrel[i - 1];
	} cout << power << endl;
	sort(all(collected), greater<uint>());
	// printf("\n$[Debugger]~: power=%d\tore=%d\n", power, ore);
	for (auto collection: collected) cout << collection << " ";
	cout << endl << usage * rate - ore << endl;
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