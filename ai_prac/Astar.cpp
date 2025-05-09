#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

// Heuristic function: Tile Replacement
int heuristic(vector<vector<int>>& a, vector<vector<int>>& goal) {
    int mismatch = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (a[i][j] != 0 && a[i][j] != goal[i][j])
                mismatch++;
        }
    }
    return mismatch;
}

// Check if the position is valid
bool isValid(int x, int y) {
    return x >= 0 && x < 3 && y >= 0 && y < 3;
}

// Print puzzle state and heuristic value
void printPuzzle(const vector<vector<int>>& puzzle, int heuristicValue) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << puzzle[i][j] << " ";
        cout << endl;
    }
    cout << "Heuristic Value: " << heuristicValue << endl;
    cout << "------\n";
}

struct State {
    vector<vector<int>> puzzle;
    int x, y, level, cost;
};

struct Compare {
    bool operator()(const State& a, const State& b) {
        return a.cost > b.cost;
    }
};

void aStarPuzzle(vector<vector<int>> start, vector<vector<int>> goal, int startX, int startY) {
    priority_queue<State, vector<State>, Compare> pq;
    set<vector<vector<int>>> visitedStates;

    // Initial state and heuristic
    State initial = {start, startX, startY, 0, heuristic(start, goal)};
    pq.push(initial);

    while (!pq.empty()) {
        State curr = pq.top();
        pq.pop();

        // Print current state and its heuristic value
        printPuzzle(curr.puzzle, curr.cost - curr.level);

        if (curr.puzzle == goal) {
            cout << "Goal Reached!\n";
            return;
        }

        visitedStates.insert(curr.puzzle);

        // Explore the neighbors
        for (int i = 0; i < 4; ++i) {
            int newX = curr.x + dx[i];
            int newY = curr.y + dy[i];

            if (isValid(newX, newY)) {
                vector<vector<int>> newPuzzle = curr.puzzle;
                swap(newPuzzle[curr.x][curr.y], newPuzzle[newX][newY]);

                // If the new puzzle state was visited, continue
                if (visitedStates.count(newPuzzle)) continue;

                int newLevel = curr.level + 1;
                int newCost = newLevel + heuristic(newPuzzle, goal);

                pq.push({newPuzzle, newX, newY, newLevel, newCost});
            }
        }
    }
}

int main() {
    // A* Algorithm (Tile Replacement)
    vector<vector<int>> initial(3, vector<int>(3));
    vector<vector<int>> goal(3, vector<int>(3));
    int blankX, blankY;

    cout << "\nEnter initial puzzle state (use 0 for blank):\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> initial[i][j];
            if (initial[i][j] == 0) {
                blankX = i;
                blankY = j;
            }
        }
    }

    cout << "Enter goal puzzle state (use 0 for blank):\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cin >> goal[i][j];
        }
    }

    cout << "\nA* Algorithm (8 Puzzle using Tile Replacement Heuristic):\n";
    aStarPuzzle(initial, goal, blankX, blankY);

    return 0;
}
