#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    // DFS Search for a goal node
    bool DFS_Search(int start, int goal) {
        vector<bool> visited(V, false);
        stack<int> s;

        s.push(start);

        cout << "DFS Search Path: ";
        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited[node]) {
                cout << node << " ";
                visited[node] = true;

                if (node == goal) {
                    cout << "\nGoal node " << goal << " found using DFS.\n";
                    return true;
                }
            }

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }

        cout << "\nGoal node " << goal << " not found using DFS.\n";
        return false;
    }

    // BFS Search for a goal node
    bool BFS_Search(int start, int goal) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS Search Path: ";
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            if (node == goal) {
                cout << "\nGoal node " << goal << " found using BFS.\n";
                return true;
            }

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }

        cout << "\nGoal node " << goal << " not found using BFS.\n";
        return false;
    }
};

int main() {
    Graph g(7);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);

    int start = 0;
    int goal = 5;

    cout << "Searching using DFS...\n";
    g.DFS_Search(start, goal);

    cout << "\nSearching using BFS...\n";
    g.BFS_Search(start, goal);

    return 0;
}