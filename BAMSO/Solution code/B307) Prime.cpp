#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> primes;
int N, K;
long long int dp[1150][20][200];

long long int solve(int n, int k, int i) {
    if (n > 0 && k == 0) return 0;
    if (k == 0 && n == 0)
        return 1;
    if (n < 0 || k < 0) return 0;
    if (primes[i] > N) return 0;
    if (dp[n][k][i] != -1) return dp[n][k][i];

    return dp[n][k][i] = solve(n - primes[i], k-1, i+1) + solve(n, k, i+1);
}

void ListPrime () {
    for(int n = 2; n <= 1150; n++) {
        int cnt = 0;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                cnt++;
        }
        if (cnt == 0) primes.push_back(n);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ListPrime(); int t; cin >> t;
    while(t--) {
        cin >> N >> K
        memset(dp, -1, sizeof dp);
        cout << solve(N, K, 0) << endl;
    }
    return 0 ;
}
