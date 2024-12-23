#include <bits/stdc++.h>
using namespace std;
using std::multiset;
const int MAXV = 200;
int V, D, MST;
int u, v, w;
int P[MAXV];
struct edge {
    int u, v, w;
    bool operator < (const edge &e) const { return w < e.w; }
};

multiset<edge> S;
multiset<edge>::iterator it, tmp;

int FIND( int x ) {
    if ( P[x] != x ) P[x] = FIND(P[x]);
    return P[x];
}

void UNION( int x, int y ) {
    P[FIND(y)] = FIND(x);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> V >> D;
    while ( D-- )  {
        scanf( "%d %d %d", &u, &v, &w );
        u--; v--;
        MST = 0;
        for ( int i = 0; i < V; i++ )
            P[i] = i;
        S.insert( ( edge ) { u, v, w } );
        for ( it = S.begin(); it != S.end(); ) {
            u = (*it).u;
            v = (*it).v;
            w = (*it).w;
            if ( FIND( u ) != FIND( v ) ) {
                UNION( u, v );
                MST += w;
                it++;
            } else {
                tmp = it; it++;
                S.erase( tmp );
            }
        }
        printf("%d\n", S.size() == V-1 ? MST :-1 );
    }
    return 0;
}
