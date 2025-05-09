#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1e9 + 7;
const int N = 1e5 + 1;
const int INF = 1e18;

vector<pair<int, int>>adj[N];
vector<int>dist(N);
vector<int>parent(N);

// single source shortest path => dijkstra's shortest path algorithm

void print_path(int src, int destination){
    if(dist[destination] == INF){
        cout << "path not present" << endl;
        return;
    }

    vector<int>path;
    int curr = destination;
    do
    {
        path.push_back(curr);
        curr = parent[curr];
    } while (curr != parent[curr]);

    reverse(path.begin(), path.end());

    for(auto it: path){
        cout << it << " ";
    }
    cout << endl;
    
}



signed main() {
    int n, m; cin >> n >> m;

    // assume use vertex node: 0  - n-1
    for(int i = 0; i < m; i++){
        int u, v, w; cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    fill(dist.begin(), dist.end(), INF);
    for(int i = 0; i < n; i++){
        parent[i] = i;
    }

    int source; cin >> source;
    priority_queue< pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, source});
    dist[source] = 0;

    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        
        int wt = it.first;
        int node = it.second;

        for(auto nbr: adj[node]){
            int nbr_w = nbr.first;
            int nbr_v = nbr.second;
            if(wt + nbr_w < dist[nbr_v]){
                dist[nbr_v] = wt + nbr_w;
                parent[nbr_v] = node;
                pq.push({wt + nbr_w, nbr_v});
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout << dist[i] << " ";
    }
    cout << endl;
}



// 5 6
// 0 1 2
// 0 2 4
// 1 2 1
// 1 3 7
// 2 4 3
// 3 4 1
// 0
// 0 2 3 7 6