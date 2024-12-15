#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, x, y, ans, sum;
char emap[1001][1001], filled[1001][1001], land;
void FloodFill(int x, int y) {
    if(y < 0)   y = m - 1;
    if(y >= m)  y = 0;
    if(x < 0 || x >= n)
        return ;
    if(filled[x][y] != 0 || emap[x][y] != land)
        return ;
    filled[x][y] = 1;
    sum++;
    FloodFill(x+1, y);
    FloodFill(x, y+1);
    FloodFill(x-1, y);
    FloodFill(x, y-1);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> x >> y;
    for(int i = 0; i < n; i++) cin >> emap[i];
    land = emap[x][y];
    FloodFill(x, y);
    ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum = 0;
            FloodFill(i, j);
            if(sum > ans)
                ans = sum;
        }
    }
    cout << ans << endl;
    return 0;
}

