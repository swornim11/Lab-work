#include <iostream>
using namespace std;

#define INF 9999

// Function to find vertex with minimum distance
int minDistance(int dist[], bool visited[], int n) {
    int min = INF, min_index;

    for (int i = 0; i < n; i++) {
        if (!visited[i] && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Dijkstra Algorithm
void dijkstra(int graph[10][10], int n, int source) {
    int dist[10];
    bool visited[10];

    // Initialize
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    dist[source] = 0;

    // Main loop
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output
    cout << "\nVertex\tDistance from Source\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << dist[i] << endl;
    }
}

int main() {
    int n, source;
    int graph[10][10];
    cout << "===== Swornim Maharjan =====\n";
    cout << "===== Dijkstra Algorithm =====\n";

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    cout << "(Enter 0 if no edge)\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter source vertex (0 to " << n-1 << "): ";
    cin >> source;

    dijkstra(graph, n, source);

    return 0;
}
