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

typedef struct coordinate { int x, y, z; } pos;
const float threshold = 1e-9;
uint dist(const pos &dept, const pos &tmnl) {
	return ceil(sqrt(pow(dept.x - tmnl.x, 2) + pow(dept.y - tmnl.y, 2) + pow(dept.z - tmnl.z, 2)));
}
bool areCollinear(const pos &init, const pos &midp, const pos &endp) {
	return abs(
		(midp.x - init.x) * (endp.y - init.y) * (endp.z - init.z) +
		(endp.x - init.x) * (midp.y - init.y) * (midp.z - init.z) +
		(midp.z - init.z) * (endp.x - init.x) * (endp.y - init.y) -
		(endp.z - init.z) * (midp.x - init.x) * (midp.y - init.y) -
		(midp.y - init.y) * (endp.x - init.x) * (endp.z - init.z) +
		(endp.y - init.y) * (midp.z - init.z) * (midp.x - init.x)
	) < threshold;
}
void real_process() {
	uint stations, cost; cin >> stations >> cost;
	vector<pos> location; pos tmp_coord;
	loop(stations) {
		cin >> tmp_coord.x >> tmp_coord.y >> tmp_coord.z;
		location.push_back(tmp_coord);
	} uint tunnel = 0, distance = 0, tmp_dist; bool collide;
	loopi(stations) loopj(stations - i - 1) {
		collide = false;
		for (uint k = 0; k < stations; k++) {
			if (k != i && k != j + i + 1 && areCollinear(location[i], location[j + i + 1], location[k])) {
				collide = true;
				break;
			}
		} if (!collide) {
			tunnel += 1;
			distance += dist(location[i], location[j + i + 1]);
		}
	} cout << distance << " " << tunnel * cost << endl;
	// getchar();
	// Code by ChatGPT (Modified)
	/***
	 * The prompt:
	 * Given the amount of points and positions of each point in a 3d plain.
Write me a code to calculate the total amount of lines to connect each and every point to each other, except one that collides together (in this case means if there is 3 points aligned in a straight line, a line can be eliminated) and calculate total distance for the remaining lines in C++
	 ***/
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