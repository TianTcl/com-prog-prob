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

void real_process() {
	/* Algorithm by Beta Jinatta Sriboonjaroenchai */
	uint T, F; cin >> T >> F;
	uint arr[F] = {0}, aru[T] = {0};
	ll ans = TM, r = 0, mid, l = TM; uint use;
	loopi(F) cin >> arr[i];
	while (r <= l) {
		mid = (r + 1) / 2;
		loopi(T) aru[i] = mid;
		use = 0;
		loopi(F) {
			while (aru[use] < arr[i] && use < T) use += 1;
			if (use == T) break;
			aru[use] -= arr[i];
		} if (use == T) r = mid + 1;
		else {
			ans = min(ans, mid);
			l = mid - 1;
		}
	} cout << ans;
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