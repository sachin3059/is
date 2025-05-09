#include<bits/stdc++.h>
using namespace std;


int main(){
    int v, e; cin >> v >> e;
    vector<pair<int, int>>adj[v];

    for(int i = 0; i < e; i++){
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});

    }

    priority_queue<pair<int, int>, vector<pair<int, int>> , greater<pair<int, int>> > pq;

    vector<int>vis(v, 0);

    pq.push({0, 0});
    int sum = 0;

    while(!pq.empty()){
        auto it = pq.top(); pq.pop();
        int node = it.second;
        int wt = it.first;

        if(vis[node]) continue;
        vis[node] = 1;

        sum += wt;

        for(auto it: adj[node]){
            int adjNode = it.first;
            int edW = it.second;

            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        }
    }

    cout << "minimum spanning tree sum: " << sum << endl;
}



// 5 6
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8
// 1 4 5
// 2 4 7
// minimum spanning tree sum: 16