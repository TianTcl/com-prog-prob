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
	/* Algorithm by Ren Achira */
	int P, W, U, S; cin >> P >> W >> U >> S;
	multiset<int> Lum; map<int, int> Pam;
	int Dum, Tuo = 0, Tuo2 = 0;
	loop(S) {
		cin >> Dum;
		Lum.insert(Dum);
		if (Pam[Dum] == -1) Pam[Dum] = 1;
		else Pam[Dum] += 1;
	} W = W * U / 100;
	for (auto i = Lum.rbegin(); i != Lum.rend(); i++) {
		if (Pam[*i] <= 0) continue;
		Dum = W;
		Tuo += 1;
		Pam[*i] -= 1;
		Dum -= *i;
		for (auto j = Lum.rbegin(); j != Lum.rend() && Dum > 0; j++) {
			if (Pam[*j] <= 0 || *j > Dum) continue;
			Pam[*j] -= 1;
			Dum -= *j;
		} Tuo2 += Dum;
	} cout << Tuo << endl << Tuo2;
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