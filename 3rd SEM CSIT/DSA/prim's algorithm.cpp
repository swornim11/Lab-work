#include <iostream>
using namespace std;

#define INF 9999

// Function to find minimum key vertex
int minKey(int key[], bool mstSet[], int n) {
    int min = INF, min_index;

    for (int i = 0; i < n; i++) {
        if (!mstSet[i] && key[i] < min) {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

// Prim's Algorithm
void primMST(int graph[10][10], int n) {
    int parent[10];   // Store MST
    int key[10];      // Minimum weight
    bool mstSet[10];  // Included in MST

    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;      // Start from vertex 0
    parent[0] = -1;  // Root node

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    // Output MST
    cout << "\nEdge \tWeight\n";
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
    }
}

int main() {
    int n;
    int graph[10][10];

    cout << "===== Swornim Maharjan =====\n";
    cout << "===== Prim's Algorithm =====\n";

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    cout << "(Enter 0 if no edge)\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    primMST(graph, n);

    return 0;
}
