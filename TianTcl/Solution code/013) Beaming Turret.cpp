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

typedef struct coordinate { uint x, y, z; } pos;
const uint modulo = 25621;
void real_process() {
	uint N, M, O, turrets, barriers; cin >> N >> M >> O >> turrets >> barriers;
	struct { set<uint> x, y, z; } unsafe, align_t, align_b;
	vector<pos> turret, barrier; pos tmp_coord;
	loop(turrets) {
		cin >> tmp_coord.x >> tmp_coord.y >> tmp_coord.z;
		unsafe.x.insert(tmp_coord.x);
		unsafe.y.insert(tmp_coord.y);
		unsafe.z.insert(tmp_coord.z);
		turret.push_back(tmp_coord);
	} loop(barriers) {
		cin >> tmp_coord.x >> tmp_coord.y >> tmp_coord.z;
		barrier.push_back(tmp_coord);
	} ll safezone; // = (N - unsafe.x.size()) * (M - unsafe.y.size()) * (O - unsafe.z.size());
	// Turrets
	if (N == 1)		 safezone = (M == 1 || O == 1) ? 0 : (M - unsafe.y.size()) * (O - unsafe.z.size());
	else if (M == 1) safezone = (N == 1 || O == 1) ? 0 : (N - unsafe.x.size()) * (O - unsafe.z.size());
	else if (O == 1) safezone = (N == 1 || M == 1) ? 0 : (N - unsafe.x.size()) * (M - unsafe.y.size());
	else safezone = N * M * O
		- ((M + O) * unsafe.x.size() + (M + O) * unsafe.y.size() + (N + M) * unsafe.z.size())
		+ unsafe.x.size() * unsafe.y.size() * unsafe.z.size();;
	// Barriers
	set<uint>::iterator t_upper, t_lower, t_begin, t_end,
						b_upper, b_lower, b_begin, b_end;
	uint tmp_pos;
	loopi(barriers) {
		if (unsafe.x.find(barrier[i].x) == unsafe.x.end() && unsafe.y.find(barrier[i].y) == unsafe.y.end() && unsafe.z.find(barrier[i].z) == unsafe.z.end()) continue;
		safezone += 1;
		align_t.x.clear(); align_t.y.clear(); align_t.z.clear();
		align_b.x.clear(); align_b.y.clear(); align_b.z.clear();
		loopj(turrets) {
			if		(turret[j].x == barrier[i].x && turret[j].y == barrier[i].y) align_t.z.insert(turret[j].z);
			else if (turret[j].x == barrier[i].x && turret[j].z == barrier[i].z) align_t.y.insert(turret[j].y);
			else if (turret[j].y == barrier[i].y && turret[j].z == barrier[i].z) align_t.x.insert(turret[j].x);
		} loopj(barriers) {
			if (i == j) continue;
			if		(barrier[j].x == barrier[i].x && barrier[j].y == barrier[i].y) align_b.z.insert(barrier[j].z);
			else if (barrier[j].x == barrier[i].x && barrier[j].z == barrier[i].z) align_b.y.insert(barrier[j].y);
			else if (barrier[j].y == barrier[i].y && barrier[j].z == barrier[i].z) align_b.x.insert(barrier[j].x);
		} if (align_t.x.size()) { // and y and z
			tmp_pos = barrier[i].x;
			t_begin = align_t.x.begin(); t_end = align_t.x.end();
			t_lower = align_t.x.lower_bound(tmp_pos);
			t_upper = align_t.x.upper_bound(tmp_pos);
			b_begin = align_b.x.begin(); b_end = align_b.x.end();
			b_lower = align_b.x.lower_bound(tmp_pos);
			b_upper = align_b.x.upper_bound(tmp_pos);
			if ((tmp_pos == 0 && !(b_upper != b_end && tmp_pos < *b_upper)) || (tmp_pos == N && !(b_lower != b_begin && *b_lower < tmp_pos))) safezone += 0;
			else if (t_lower == t_begin && t_upper != t_end && !(b_upper != b_end && tmp_pos < *b_upper)) safezone += tmp_pos - 1;
			else if (t_lower != t_begin && t_upper == t_end && !(b_lower != b_begin && *b_lower < tmp_pos)) safezone += N - tmp_pos;
			else if (t_lower != t_begin && t_upper != t_end) {
				if ((b_lower == b_begin || *b_lower < *t_lower) && (b_upper == b_end || *b_upper > *t_upper)) safezone += 0;
				else if (b_lower != b_begin && *b_lower > *t_lower) safezone += tmp_pos - *b_lower;
				else if (b_upper != b_end && *b_upper < *t_upper) safezone += *b_upper - tmp_pos;
			}
		}
	}
	cout << safezone % modulo;
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