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

/* Algorithm by TianTcl */
/* const uint characters = 26, longest = 18;
float stdev(uint *amount, float *mean, vector<float> &list) {
	float sum = 0;
	for (auto weight: list) sum += pow(weight - *mean, 2);
	return sqrt(sum / (*amount - 1));
}
void real_process() {
	uint word_amount; string order; cin >> word_amount >> order;
	bool reverse = order[0] != 'A'; int score[characters];
	loopi(characters) cin >> score[i];
	string word; float calc, mean; struct statistics {
		float min, max, sum;
	} stat = {15, -5, 0};
	map<float, vector<string>> weight; vector<float> weight_list, weight_data;
	loop(word_amount) {
		calc = 0; word.clear();
		cin >> word; word[0] += 32;
		loopi(word.length()) calc += score[word[i] - 97];
		word[0] -= 32;
		calc /= word.length();
		stat.min = min(stat.min, calc);
		stat.max = max(stat.max, calc);
		stat.sum += calc;
		if (weight.find(calc) == weight.end()) {
			vector<string> new_chain; new_chain.push_back(word);
			weight[calc] = new_chain;
			weight_list.push_back(calc);
		} else weight[calc].push_back(word);
		weight_data.push_back(calc);
	} if (!reverse) sort(all(weight_list));
	else sort(all(weight_list), greater<float>());
	sort(all(weight_data));
	for (auto weight_idx: weight_list) {
		if (!reverse) sort(all(weight[weight_idx]));
		else sort(all(weight[weight_idx]), greater<string>());
		for (auto word_idx: weight[weight_idx]) printf("%s\n", word_idx.c_str()); // Print duplicates ?!
	} mean = stat.sum / word_amount;
	printf("%.2f %.2f %.2f %.2f",
		stat.max - stat.min,
		mean,
		word_amount % 2 ? weight_data[(word_amount + 1) / 2 - 1] : ((weight_data[word_amount / 2 - 1] + weight_data[word_amount / 2]) / 2),
		stdev(&word_amount, &mean, weight_data)
	); // getchar();
	return;
} */

/* Algorithm by Ren Achira */
void real_process() {
	map<int, int> pam;
	map<float, set<string>> dex;
	set<float> tes;
	uint n;
	string str;
	cin >> n >> str;
	string word[n + 1];
	float count = 0, number = 0, Max = -1e5 + 3, Min = 1e5 + 3, Sum = 0, SD = 0, K[n + 1];
	loopi(26) {
		cin >> pam[i + 65];
		pam[i + 97] = pam[i + 65];
	} loopi(n) {
		cin >> word[i];
		count = 0;
		loopj(word[i].length()) count += pam[(int)word[i][j]];
		number = count / word[i].length();
		dex[number].insert(word[i]);
		tes.insert(number);
		Max = max(Max, number);
		Min = min(Min, number);
		Sum += number;
	} float avg = Sum / n; uint i = 1;
	if (str[0] == 65) {
		for (auto it = tes.begin(); it != tes.end(); it++) for (auto ti = dex[*it].begin(); ti != dex[*it].end(); ti++) {
			printf("%s\n", (*ti).c_str());
			SD += pow(*it - avg, 2);
			K[i] = *it;
			i += 1;
		}
	} else {
		for (auto it = tes.rbegin(); it != tes.rend(); it++) for (auto ti = dex[*it].rbegin(); ti != dex[*it].rend(); ti++) {
			printf("%s\n", (*ti).c_str());
			SD += pow(*it - avg, 2);
			K[i] = *it;
			i += 1;
		}
	}
	printf("%.2f %.2f %.2f %.2f\n",
		Max - Min,
		avg,
		(n % 2 ? K[(n + 1) / 2] : (K[n / 2] + K[(n / 2) + 1]) / 2),
		sqrt(SD / (n - 1))
	); // getchar();
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