#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define f first
#define s second
const int maxn = 2e5 + 1;
vector<pii> adj[maxn];
map<ll, ll> info[maxn];
ll dist[maxn], sum[maxn], ret;
int N, K;

void precomp(int u, int p, ll c, int h) {
	info[u][c] = h;
	sum[u] = c;
	dist[u] = h;
	for (auto n : adj[u]) {
		if (p == n.f) { continue; }
		precomp(n.f, u, c + n.s, h + 1);
	}
}

void small_to_large_merge(int u, int p) {
	ll target = K + 2 * sum[u];
	for (auto n : adj[u]) {
		if (n.f == p) { continue; }
		small_to_large_merge(n.f, u);
		if (info[n.f].size() > info[u].size()) { swap(info[n.f], info[u]); }
		for (auto i : info[n.f]) {
			if (info[u].find(target - i.f) != info[u].end()) {
				ret = min(ret, info[u][target - i.f] + i.s - 2 * dist[u]);
			}
		}
		for (auto i : info[n.f]) {
			if (info[u].find(i.f) == info[u].end()) {
				info[u].insert(i);
			} else {
				info[u][i.f] = min(info[u][i.f], i.s);
			}
		}
	}
}

int Solve(int n, int k, int edges[][2], int weights[]) {
	if (k == 1) { return 0; }
	N = n;
	K = k;
	ret = INT_MAX;
	for (int i = 0; i < n - 1; i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		adj[u].pb(pii(v, weights[i]));
		adj[v].pb(pii(u, weights[i]));
	}
	precomp(0, -1, 0, 0);
	small_to_large_merge(0, -1);
	return ret == INT_MAX ? -1 : ret;
}

int main() {
    cin >> N >> K;
    int H[N-1][2],L[N-1];
    for(int i = 0; i < N-1; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> H[i][j];
        }
        cin >> L[i];
    }
    cout << Solve(N,K,H,L);
    return 0;
}
