#include <iostream>
using namespace std;

#define MAX 20
#define INF 9999

struct Edge {
    int u, v, cost;
};

int parent[MAX];

// Find function
int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

// Union function
void unionSet(int i, int j) {
    parent[i] = j;
}

// Sort edges
void sortEdges(Edge e[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (e[j].cost > e[j+1].cost) {
                Edge temp = e[j];
                e[j] = e[j+1];
                e[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    int graph[MAX][MAX];
    Edge edges[MAX * MAX];
    int edgeCount = 0;

    cout << "===== Swornim Maharjan =====\n";
    cout << "===== Kruskal Algorithm =====\n";

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    cout << "(Enter 0 if no edge)\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];

            // Take only upper triangle to avoid duplicate edges
            if (graph[i][j] != 0 && i < j) {
                edges[edgeCount].u = i;
                edges[edgeCount].v = j;
                edges[edgeCount].cost = graph[i][j];
                edgeCount++;
            }
        }
    }

    // Initialize parent
    for (int i = 0; i < n; i++)
        parent[i] = i;

    // Sort edges
    sortEdges(edges, edgeCount);

    cout << "\nEdge\tCost\tRemark\n";

    int total = 0;

    for (int i = 0; i < edgeCount; i++) {
        int u = find(edges[i].u);
        int v = find(edges[i].v);

        if (u != v) {
            cout << edges[i].u << "-" << edges[i].v << "\t"
                 << edges[i].cost << "\tSelected\n";
            total += edges[i].cost;
            unionSet(u, v);
        } else {
            cout << edges[i].u << "-" << edges[i].v << "\t"
                 << edges[i].cost << "\tEliminated (Cycle)\n";
        }
    }

    cout << "\nTotal Minimum Cost = " << total << endl;

    return 0;
}
