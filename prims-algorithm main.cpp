#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int V = 4;

    int graph[4][4] = {
        {0, 10, 6, 5},
        {10, 0, 0, 15},
        {6, 0, 0, 4},
        {5, 15, 4, 0}
    };

    bool selected[4] = {false};
    int edges = 0;
    int totalCost = 0;

    selected[0] = true;

    cout << "Roads selected:\n";

    while (edges < V - 1) {
        int minCost = INT_MAX;
        int x = -1, y = -1;

        for (int i = 0; i < V; i++) {
            if (selected[i]) {
                for (int j = 0; j < V; j++) {
                    if (!selected[j] && graph[i][j] > 0 &&
                        graph[i][j] < minCost) {
                        minCost = graph[i][j];
                        x = i;
                        y = j;
                    }
                }
            }
        }

        if (y == -1) {
            cout << "Graph is disconnected.\n";
            return 0;
        }

        cout << x + 1 << " - " << y + 1
             << " : Cost = " << minCost << endl;

        totalCost += minCost;
        selected[y] = true;
        edges++;
    }

    cout << "Minimum total cost = " << totalCost << endl;

    return 0;
}
