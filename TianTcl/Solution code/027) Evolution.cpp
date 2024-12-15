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

/* Algorithm by Ren Achira */
void real_process() {
	int N, D; cin >> N >> D;
	int F[D], J[N], E[N][4], A[N][D], B[N][D], Ans[N];
	loopi(D) cin >> F[i];
	loopi(N) {
		cin >> J[i];
		loopj(4) {
			float test = pow(sqrt((J[i] / 3.00)), j + 1);
			if (test-floor(test) == 0) E[i][j] = test;
			else E[i][j] = ceil(test);
		} Ans[i] = 2*D;
	} loopi(D) loopj(N) {
		B[j][i] = 0;
		A[j][i] = -1;
		for (int k = 0; k < 4 && E[j][k] <= F[i]; k++) A[j][i]++;
	} loopi(N) {
		loopj(D) {
			int dummy = 0;
			for (int k=j; k < D && dummy < 4; k++) {
				if (dummy <= A[i][k]) dummy++;
				B[i][j]++;
			} if (dummy == 4) Ans[i] = min(Ans[i], B[i][j]);
		} if (Ans[i] == 4) continue;
	} loopi(N) cout << Ans[i] << endl;
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