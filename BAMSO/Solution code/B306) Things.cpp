#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    unsigned long long int dp[25][25][25]; dp[1][1][1] = 1;
    for(int N = 2; N < 24; N++) for(int P = 1; P <= N; P++) for(int R = 1; R <= N; R++){
        long long int middle = dp[N-1][P][R]*(N-2);
        long long int f = dp[N-1][P-1][R];
        long long int b = dp[N-1][P][R-1];
        dp[N][P][R] = middle + f + b;
    }
    int t,n,p,r; cin >> t;
    while(t--){
        cin >> n >> p >> r;
        cout << dp[n][p][r] << endl;
    }
}
