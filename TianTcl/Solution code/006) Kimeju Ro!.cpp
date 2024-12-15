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

typedef struct { uint current, best, worst; } stats;
void real_process() {
	/* TianTcl's Algorithm *//*
	uint player; cin >> player;
	uint power[2][player + 5] = {0}, winners[2] = {0}, active[2] = {0};
	stats streak[2] = {{ .current = 0, .best = 0, .worst = LM }}; bool result = false;
	// Lookup normal round
	loopi(2) loopj(player) cin >> power[i][j];
	while (max(active[0], active[1]) < player) {
		if (power[0][active[0]] > power[1][active[1]]) {
			if (streak[0].current == 0) winners[0] += 1;
			streak[0].current += 1;
			streak[0].best = max(streak[0].best, streak[0].current);
			active[1] += 1;
			if (streak[1].current > 0) streak[1].worst = min(streak[1].worst, streak[1].current);
			streak[1].current = 0;
		} else if (power[0][active[0]] < power[1][active[1]]) {
			if (streak[1].current == 0) winners[1] += 1;
			streak[1].current += 1;
			streak[1].best = max(streak[1].best, streak[1].current);
			active[0] += 1;
			if (streak[0].current > 0) streak[0].worst = min(streak[0].worst, streak[0].current);
			streak[0].current = 0;
		} else loopi(2) { // Case equal
			streak[i].best = max(streak[i].best, streak[i].current);
			active[i] += 1;
			if (streak[i].current > 0) streak[i].worst = min(streak[i].worst, streak[i].current);
			streak[i].current = 0;
		}
	} if (active[0] != active[1]) {
		result = true;
		loopi(2) { if (streak[i].worst == LM) streak[i].worst = 0; }
		cout << winners[0] + winners[1] << endl;
		cout << max(streak[0].best, streak[1].best) - min(streak[0].worst, streak[1].worst) << endl;
		cout << (active[0] > active[1] ? "RED" : "BLUE") << endl;
	} // Lookup backup round
	loopi(5) loopj(2) cin >> power[j][player + i];
	while (max(active[0], active[1]) < player + 5) {
		if (power[0][active[0]] > power[1][active[1]]) {
			if (streak[0].current == 0) winners[0] += 1;
			streak[0].current += 1;
			streak[0].best = max(streak[0].best, streak[0].current);
			active[1] += 1;
			if (streak[1].current > 0) streak[1].worst = min(streak[1].worst, streak[1].current);
			streak[1].current = 0;
		} else if (power[0][active[0]] < power[1][active[1]]) {
			if (streak[1].current == 0) winners[1] += 1;
			streak[1].current += 1;
			streak[1].best = max(streak[1].best, streak[1].current);
			active[0] += 1;
			if (streak[0].current > 0) streak[0].worst = min(streak[0].worst, streak[0].current);
			streak[0].current = 0;
		} else loopi(2) { // Case equal
			streak[i].best = max(streak[i].best, streak[i].current);
			active[i] += 1;
			if (streak[i].current > 0) streak[i].worst = min(streak[i].worst, streak[i].current);
			streak[i].current = 0;
		}
	} if (!result) {
		loopi(2) { if (streak[i].worst == LM) streak[i].worst = 0; }
		cout << winners[0] + winners[1] << endl;
		cout << max(streak[0].best, streak[1].best) - min(streak[0].worst, streak[1].worst) << endl;
		cout << (active[0] == active[1] ? "TIE" : (active[0] > active[1] ? "RED" : "BLUE")) << endl;
	} */
	/* Ren Achira's Algorithm (Modified) */
	uint n; cin >> n;
	uint blue[n + 6], red[n + 6];
	loopi(n) cin >> blue[i];
	loopi(n) cin >> red[i];
	loopi(5) cin >> blue [i + n] >> red [i + n];
	uint i = 0, j = 0; uint Min = 0, Max = 0, Count = 0, Current = 0, Data = 0, Stat = 0, First = 0;
	while ((i < n && j < n && blue[n - 1] != red[n - 1]) || (i < n + 5 && j < n + 5 && blue[n - 1] == red[n - 1])) {
		if (Current != Data) {
			Stat += 1;
			Data = Current;
			if (First == 1) Min = Count - 1;
			else if (First > 1) Min = min(Min, Count);
			Count = 1;
			First += 1;
		} if (blue[i] > red[j]) {
			j += 1;
			Count += 1;
			Current = blue[i];
		} else if (blue[i] < red[j]) {
			i += 1;
			Count += 1;
			Current = red[j];
		} else if (i <= n || j <= n) {
			i = n;
			j = n;
			Count = 0;
		} else {
			i += 1;
			j += 1;
		} if (Current == Data) Max = max(Max, Count);
	} bool isTie = (blue[n - 1] == red[n - 1] && blue[n + 4] == red[n + 4]);
	cout << Stat << endl << Max - Min << endl << (isTie ? "TIE" : (i > j ? "RED" : "BLUE")) << endl;
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