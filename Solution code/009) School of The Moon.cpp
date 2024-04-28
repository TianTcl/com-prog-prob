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
	/* Algorithm I *//*
	uint amount, student = 0, perGroup = 5, eachGroup = 0, score;
	float board = 0; pair<uint,float> first = {0, 0}, second = {0, 0};
	cin >> amount;
	while (student++ < amount) {
		cin >> score; board += score;
		if (++eachGroup < perGroup) continue;
		// Calculate mean and ranks
		board /= perGroup++;
		if (board > first.nd) {
			second = first;
			first = make_pair(perGroup - 5, board);
		} else if (board > second.nd)
			second = make_pair(perGroup - 5, board);
		// Reset
		board = eachGroup = 0;
	} printf("%d\n%.2f\n", second.st, second.nd); */
	/* Algorithm II */
	uint amount, student = 0, perGroup = 5, score;
	float board; pair<uint,float> first = {0, 0}, second = {0, 0};
	cin >> amount;
	loop((sqrt(81 + 8 * amount) - 9) / 2) {
		board = 0;
		loopi(perGroup) { cin >> score; board += score; }
		board /= perGroup++;
		if (board > first.nd) {
			second = first;
			first = make_pair(perGroup - 5, board);
		} else if (board > second.nd)
			second = make_pair(perGroup - 5, board);
	} printf("%d\n%.2f", second.st, second.nd);
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