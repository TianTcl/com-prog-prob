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
#define loopk(n) for (int k = 0; k < n; k++)
#define mbr(n,m) get<m>(n)
#define DEBUG 0
#define CASES 0
#define endl "\n"
#define all(n) n.begin(), n.end()

/* Algorithm by ChatGPT modified by Namo Ratchapong, TianTcl refined *//*
typedef vector<int> vi;
// const double EPSILON = 1e-4;
long double tmpVal;
bool solve(vi &nums, int *target) {
	uint n = nums.size();
	if (n == 1) return nums[0] == *target;
	loopi(n) loopj(n) {
		if (i == j) continue;
		vi new_nums;
		loopk(n) if (k != i && k != j) new_nums.push_back(nums[k]);
		if (j < i) {
			new_nums.push_back(nums[i] + nums[j]);	if (solve(new_nums, target)) return true; new_nums.pop_back();
			new_nums.push_back(nums[i] * nums[j]);	if (solve(new_nums, target)) return true; new_nums.pop_back();
		} new_nums.push_back(nums[i] - nums[j]);	if (solve(new_nums, target)) return true; new_nums.pop_back();
		if (nums[j] != 0 && nums[i] % nums[j] == 0) {
			new_nums.push_back(nums[i] / nums[j]);	if (solve(new_nums, target)) return true; new_nums.pop_back();
		} tmpVal = pow(nums[i], nums[j]);
		if (floor(tmpVal) == tmpVal && tmpVal <= (long double)LM) {
			new_nums.push_back((int)tmpVal);		if (solve(new_nums, target)) return true; new_nums.pop_back();
		} if (nums[j] != 0) {
			new_nums.push_back(nums[i] % nums[j]);	if (solve(new_nums, target)) return true; new_nums.pop_back();
		}
	} return false;
}
void real_process() {
	vi nums; uint num_count, target_count;
	cin >> num_count >> target_count;
	int num, target;
	loop(num_count) {
		cin >> num;
		nums.push_back(num);
	} loop(target_count) {
		cin >> target;
		cout << (solve(nums, &target) ? "P" : "N") << endl;
	} // getchar();
	return;
} */

/* Algorithm by ChatGPT *//*
typedef vector<int> vi;
unordered_map<string, bool> memo;
long double tmpVal;
bool solve(const vi &nums, int *target) {
	string key = to_string(*target) + "_";
	for (uint num: nums) key += to_string(num) + ",";
	if (memo.find(key) != memo.end()) return memo[key];
	uint n = nums.size();
	if (n == 1) return nums[0] == *target;
	bool result = false;
	loopi(n) loopj(n) {
		if (i == j) continue;
		vi new_nums;
		loopk(n) new_nums.push_back(nums[k]);
		new_nums.push_back(nums[i] + nums[j]);		result |= solve(new_nums, target); new_nums.pop_back(); if (result) goto skipToMemo;
		new_nums.push_back(nums[i] - nums[j]);		result |= solve(new_nums, target); new_nums.pop_back(); if (result) goto skipToMemo;
		new_nums.push_back(nums[i] * nums[j]);		result |= solve(new_nums, target); new_nums.pop_back(); if (result) goto skipToMemo;
		if (nums[j] != 0 && nums[i] % nums[j] == 0) {
			new_nums.push_back(nums[i] / nums[j]);	result |= solve(new_nums, target); new_nums.pop_back(); if (result) goto skipToMemo;
		} tmpVal = pow(nums[i], nums[j]);
		if (floor(tmpVal) == tmpVal && tmpVal <= (long double)LM) {
			new_nums.push_back((int)tmpVal);		result |= solve(new_nums, target); new_nums.pop_back(); if (result) goto skipToMemo;
		}
		if (nums[j] != 0) {
			new_nums.push_back(nums[i] % nums[j]);	result |= solve(new_nums, target); new_nums.pop_back(); if (result) goto skipToMemo;
		}
	} skipToMemo:
	memo[key] = result;
	return result;
}
void real_process() {
	vi nums; uint num_count, target_count;
	cin >> num_count >> target_count;
	int num, target;
	loop(num_count) {
		cin >> num;
		nums.push_back(num);
	} loop(target_count) {
		cin >> target;
		cout << (solve(nums, &target) ? "P" : "N") << endl;
	} // getchar();
	return;
} // Not working */

/* Algorithm by ChatGPT modified by Namo Ratchapong, TianTcl refined, Neo optimized */
typedef vector<int> vi;
set<int> possible;
void propability(vi &nums) {
	uint n = nums.size();
	if (n == 1) possible.insert(nums[0]);
	else loopi(n) loopj(n) {
		if (i == j) continue;
		vi new_nums;
		loopk(n) if (k != i && k != j) new_nums.push_back(nums[k]);
		if (j < i) {
			new_nums.push_back(nums[i] + nums[j]);			propability(new_nums); new_nums.pop_back();
			new_nums.push_back(nums[i] * nums[j]);			propability(new_nums); new_nums.pop_back();
		}	new_nums.push_back(nums[i] - nums[j]);			propability(new_nums); new_nums.pop_back();
		if (nums[j] != 0 && nums[i] % nums[j] == 0) {
			new_nums.push_back(nums[i] / nums[j]);			propability(new_nums); new_nums.pop_back();
		} if (nums[j] >= 0 && abs(nums[i]) + nums[j] <= 10) {
			new_nums.push_back((int)pow(nums[i], nums[j]));	propability(new_nums); new_nums.pop_back();
		} if (nums[j] != 0) {
			new_nums.push_back(nums[i] % nums[j]);			propability(new_nums); new_nums.pop_back();
		}
	}
}
void real_process() {
	vi nums; uint num_count, target_count;
	cin >> num_count >> target_count;
	int num, target;
	loop(num_count) {
		cin >> num;
		nums.push_back(num);
	} propability(nums);
	loop(target_count) {
		cin >> target;
		cout << (possible.find(target) != possible.end() ? "P" : "N") << endl;
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