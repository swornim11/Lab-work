#include <iostream>
using namespace std;

#define MAX 20

int graph[MAX][MAX], visited[MAX];
int queueArr[MAX], front = -1, rear = -1;
int n;

// Enqueue
void enqueue(int value) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queueArr[++rear] = value;
}

// Dequeue
int dequeue() {
    if (front == -1)
        return -1;
    int value = queueArr[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;
    return value;
}

// BFS function
void bfs(int start) {
    int node;

    enqueue(start);
    visited[start] = 1;

    cout << "\nBFS Traversal: ";

    while (front != -1) {
        node = dequeue();
        cout << node << " ";

        for (int i = 0; i < n; i++) {
            if (graph[node][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int start;

    cout << "===== Swornim Maharjan =====\n";
    cout << "===== BFS Traversal =====\n";

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix (0/1):\n";

    for (int i = 0; i < n; i++) {
        visited[i] = 0;
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << "Enter starting vertex: ";
    cin >> start;

    bfs(start);

    return 0;
}
