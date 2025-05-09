#include<bits/stdc++.h>
using namespace std;

bool isSafe(vector<vector<int>>& graph, vector<int>& colors, int v, int c){
    for(int i = 0; i < graph.size(); i++){
        if(graph[v][i] && colors[i] == c) return false;
    }
    return true;
}

bool graphColoringUntil(vector<vector<int>>& graph, vector<int>& colors, int v, int m){
    if(v == graph.size()) return true;

    for(int c = 1; c <= m; c++){
        if(isSafe(graph, colors, v, c)){
            colors[v] = c;
            if(graphColoringUntil(graph, colors, v + 1, m)) return true;
            colors[v] = 0; // backtrack
        }
    }

    return false;
}

void graphColoring(vector<vector<int>>& graph, int m){
    int v = graph.size();
    vector<int> colors(v, 0);

    if(!graphColoringUntil(graph, colors, 0, m)){
        cout << "Solution does not exist" << endl;
        return;
    }

    cout << "Solution:" << endl;
    for(int i = 0; i < v; i++){
        cout << "Vertex " << i << " ---> Color " << colors[i] << endl;
    }
}

int main(){
    int v, e, m;
    cin >> v >> e >> m;

    vector<vector<int>> graph(v, vector<int>(v, 0));

    for(int i = 0; i < e; i++){
        int u, w;
        cin >> u >> w;
        graph[u][w] = 1;
        graph[w][u] = 1;
    }

    graphColoring(graph, m);

    return 0;
}


/*
4 5 3
0 1
0 2
1 2
1 3
2 3
Solution:
Vertex 0 ---> Color 1
Vertex 1 ---> Color 2
Vertex 2 ---> Color 3
Vertex 3 ---> Color 1

*/
