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

/* Algorithm by TianTcl *//*
const int maxSize = 2005, direction = 4,
	dirX[] = {1, 0, -1, 0},
	dirY[] = {0, 1, 0, -1};
typedef struct coordinate { uint x, y; } coord;
// From input
uint mapSize, destination, discovered; coord base; vector<coord> dest; int height[maxSize][maxSize] = {-1};
// Temporary value
coord pos; bool visited[maxSize][maxSize]; uint dist;
// Memory value
set<uint> reached; uint minTime = LM, maxTime = 0; uint least[maxSize][maxSize];
void search(coord at, uint traveled = 0) {
	if (reached.size() == destination) return;
	least[at.y][at.x] = (least[at.y][at.x] ? min(least[at.y][at.x], traveled) : traveled);
	printf("[Debugger]~$ Walk to: (%-2d, %-2d) Time: %-2d hr, Height: %d\n", at.x, at.y, least[at.y][at.x], height[at.y][at.x]);
	loopi(destination) {
		if (dest[i].x != at.x || dest[i].y != at.y) continue;
		printf("[Debugger]~$ Dest: %-2d, Time: %2d hr\n", i, least[at.y][at.x]);
		minTime = min(minTime, least[at.y][at.x]);
		maxTime = max(maxTime, least[at.y][at.x]);
		reached.insert(i);
		break;
	} visited[at.y][at.x] = true;
	loopi(direction) {
		pos.x = at.x + dirX[i]; pos.y = at.y - dirY[i];
		if (pos.x < 1 || pos.x > mapSize) continue;
		if (pos.y < 1 || pos.y > mapSize) continue;
		if (height[pos.y][pos.x] == -1 || visited[pos.y][pos.x]) continue;
		dist = least[at.y][at.x] + abs(height[at.y][at.x] - height[pos.y][pos.x]);
		printf("[Debugger]~$ FromPos: (%-2d, %-2d) NextPos: (%-2d, %-2d) dist: %-2d (%d + %d |%d - %d|)\n", at.x, at.y, pos.x, pos.y, dist, least[at.y][at.x], abs(height[at.y][at.x] - height[pos.y][pos.x]), height[at.y][at.x], height[pos.y][pos.x]);
		search(pos, dist + 1);
	} visited[at.y][at.x] = false;
}
void real_process() {
	cin >> mapSize >> destination >> discovered >> base.y >> base.x; cin >> height[base.y][base.x];
	loop(destination) {
		cin >> pos.y >> pos.x >> height[pos.y][pos.x];
		dest.push_back(pos);
	} loop(discovered) cin >> pos.y >> pos.x >> height[pos.y][pos.x];
	search(base);
	if (reached.size() == destination) printf("%u\n%u\n", maxTime, minTime);
	else cout << destination - reached.size() << endl;
	// getchar();
	return;
} */

/* Algorithm by P'Ham */
int M, D, K, XS, YS, HS;
int destx[2005];
int desty[2005];
bool visited[2005][2005];
int dist[2005][2005];
int dx[5] = {-1, 0, 1, 0};
int dy[5] = {0, -1, 0, 1};
int mountain[2005][2005];
void real_process() {
	cin >> M >> D >> K >> XS >> YS >> HS;
	for (int i = 1; M >= i; i++) for (int j = 1; M >= j; j++) dist[i][j] = LM;
	for (int i = 1; M >= i; i++) for (int j = 1; M >= j; j++) mountain[i][j] = -2;
	mountain[XS][YS] = HS;
	int g, e = 0;
	for (int i = 0; D > i; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mountain[a][b] = c;
		destx[e] = a;
		desty[e] = b;
		e++;
	} g = e;
	for (int i = 0; K > i; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		mountain[a][b] = c;
	} queue<pii> q;
	dist[XS][YS] = 0;
	q.push({dist[XS][YS], {XS, YS}});
	while (!q.empty()) {
		pii s;
		s = q.front(); q.pop();
		int a = s.second.first;
		int b = s.second.second;
		int c = s.first;
		if (visited[a][b]) continue;
		for (int i = 0; 4 > i; i++) {
			int d = a + dx[i];
			int h = b + dy[i];
			int f = c + abs(mountain[d][h] - mountain[a][b]) + 1;
			if (mountain[a][b] == -2 || mountain[a][b] == -2) continue;
			if (mountain[d][h] == -1) continue;
			if (h > 0 && h <= M && d > 0 && d <= M && f < dist[d][h]) {
				dist[d][h] = f;
				q.push({dist[d][h], {d, h}});
			}
		}
	} int k = 0;
	for (int i = 0; g > i; i++) {
		int a = destx[i];
		int b = desty[i];
		if (dist[a][b] == LM) k++;
	} if (k > 0) {
		cout << k;
		return;
	} else {
		int maxint = -LM;
		for (int i = 0; g > i; i++) {
			int a = destx[i];
			int b = desty[i];
			if (dist[a][b] > maxint) maxint = dist[a][b];
		}
		int minint = LM;
		for (int i = 0; g > i; i++) {
			int a = destx[i];
			int b = desty[i];
			if (dist[a][b] < minint) minint = dist[a][b];
		} cout << maxint << endl << minint;
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