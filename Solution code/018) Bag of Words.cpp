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

const uint alphabets = 26, longest = 18;
const char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
void real_process() {
	uint letters, words; cin >> letters >> words;
	string letter; cin >> letter;
	uint has[alphabets] = {0}, use[alphabets];
	loopi(letters) has[letter[i] - 'A'] += 1;
	string word; uint least, left;
	loopi(words) {
		cin >> word;
		memset(use, 0, sizeof(use));
		loopj(word.length()) use[word[j] - 'A'] += 1;
		least = TT; left = 0;
		loopj(alphabets) if (use[j] > 0) least = min(least, (uint)floor(has[j] / use[j]));
		loopj(alphabets) left += has[j] - use[j] * least;
		if (left) cout << least << endl;
		else cout << "perfect" << endl;
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