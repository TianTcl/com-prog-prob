#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

vector<int> dijkstra(int src, vector<vector<pair<int,int>>>& graph){
    vector<int> dist(graph.size(),1e6);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    dist[src] = 0;
    pq.push({0,src});
    while(!pq.empty()){
        int cur,cost;
        tie(cost,cur) = pq.top(); pq.pop();
        if(cost > dist[cur]) continue;
        for(auto& neigh : graph[cur]){
            int nextCost = cost+neigh.second;
            if(nextCost < dist[neigh.first]){
                dist[neigh.first] = nextCost;
                pq.push({nextCost,neigh.first});
            }
        }
    }
    return dist;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t,n,m,s,e,p,a,b,c; cin >> t;
    while(t--){
        cin >> n >> m >> s >> e >> p; s--; e--;
        vector<vector<pair<int,int>>> graph(n,vector<pair<int,int>>());
        vector<vector<pair<int,int>>> reverseGraph(n,vector<pair<int,int>>());
        queue<tuple<int,int,int>> edges;
        for(int i = 0; i < m; i++){
            cin >> a >> b >> c; a--; b--;
            graph[a].push_back({b,c});
            reverseGraph[b].push_back({a,c});
            edges.push(make_tuple(a,b,c));
        }
        vector<int> costFromS = dijkstra(s,graph);
        vector<int> costFromE = dijkstra(e,reverseGraph);
        int best = -1;
        while(!edges.empty()){
            tie(a,b,c) = edges.front(); edges.pop();
            int totalCost = costFromS[a] + c + costFromE[b];
            if(totalCost <= p)
                best = max(best,c);
        }
        cout << best << endl;
    }
    return 0;
}
