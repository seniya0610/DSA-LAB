#include <iostream>
using namespace std;

class Student {
public:
    string name;
    int id;
    Student() { name = ""; id = 0; }
    Student(string n, int i) { name = n; id = i; }
};

class Graph {
public:
    int V;
    int** adj;
    int** weight;
    Student* nodes;

    Graph(int vertices) {
        V = vertices;
        adj = new int*[V];
        weight = new int*[V];
        nodes = new Student[V];
        for(int i=0; i<V; i++) {
            adj[i] = new int[V];
            weight[i] = new int[V];
            for(int j=0; j<V; j++) {
                adj[i][j] = 0;
                weight[i][j] = 0;
            }
        }
    }

    void setStudent(int idx, string name, int id) {
        nodes[idx] = Student(name, id);
    }

    void insertEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    void insertWeightedEdge(int u, int v, int w) {
        adj[u][v] = 1;
        adj[v][u] = 1;
        weight[u][v] = w;
        weight[v][u] = w;
    }

    void deleteEdge(int u, int v) {
        adj[u][v] = 0;
        adj[v][u] = 0;
        weight[u][v] = 0;
        weight[v][u] = 0;
    }

    void BFS(int start) {
        bool* visited = new bool[V];
        for(int i=0; i<V; i++) visited[i] = false;

        int* q = new int[V];
        int f = 0, r = 0;

        visited[start] = true;
        q[r++] = start;

        cout << "BFS: ";
        while(f < r) {
            int v = q[f++];
            cout << "(" << nodes[v].name << "," << nodes[v].id << ") ";

            for(int u=0; u<V; u++) {
                if(adj[v][u] && !visited[u]) {
                    visited[u] = true;
                    q[r++] = u;
                }
            }
        }
        cout << endl;

        delete[] visited;
        delete[] q;
    }

    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << "(" << nodes[v].name << "," << nodes[v].id << ") ";
        for(int u=0; u<V; u++) {
            if(adj[v][u] && !visited[u]) DFSUtil(u, visited);
        }
    }

    void DFS(int start) {
        bool* visited = new bool[V];
        for(int i=0; i<V; i++) visited[i] = false;
        cout << "DFS: ";
        DFSUtil(start, visited);
        cout << endl;
        delete[] visited;
    }

    int minDistance(int dist[], bool visited[]) {
        int index = -1;
        int minVal = 999999;
        for(int i=0; i<V; i++) {
            if(!visited[i] && dist[i] < minVal) {
                minVal = dist[i];
                index = i;
            }
        }
        return index;
    }

    void Dijkstra(int start) {
        int* dist = new int[V];
        bool* visited = new bool[V];

        for(int i=0; i<V; i++) {
            dist[i] = 999999;
            visited[i] = false;
        }

        dist[start] = 0;

        for(int c=0; c<V-1; c++) {
            int u = minDistance(dist, visited);
            if(u == -1) break;
            visited[u] = true;

            for(int v=0; v<V; v++) {
                if(adj[u][v] && !visited[v]) {
                    int nd = dist[u] + weight[u][v];
                    if(nd < dist[v]) dist[v] = nd;
                }
            }
        }

        cout << "Dijkstra from (" << nodes[start].name << "," << nodes[start].id << "):\n";
        for(int i=0; i<V; i++) {
            cout << "To (" << nodes[i].name << "," << nodes[i].id << ") = ";
            if(dist[i] == 999999) cout << "Infinity";
            else cout << dist[i];
            cout << endl;
        }

        delete[] dist;
        delete[] visited;
    }

    void printAdjMatrix() {
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) cout << adj[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    Graph G(5);

    return 0;
}
