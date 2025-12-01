#include <iostream>
#include <climits>  // For INT_MAX
using namespace std;

class student
{
public:
    string name;
    int id;

    student(string n = "", int a = -1) : name(n), id(a) {}
};

class Graph
{
public:
    int nodes;          // number of nodes
    int **weightMatrix; // adjacency matrix to store weights
    student *students;  // array to store student info

    Graph(int n)
    {
        nodes = n;
        weightMatrix = new int *[nodes]; // initialize adjacency matrix
        students = new student[nodes];   // initialize student array
        for (int i = 0; i < nodes; i++)
        {
            weightMatrix[i] = new int[nodes]; // create row
            for (int j = 0; j < nodes; j++)
            {
                weightMatrix[i][j] = 0; // no edges initially
            }
        }
    }

    // Destructor to prevent memory leaks
    ~Graph()
    {
        for (int i = 0; i < nodes; i++)
        {
            delete[] weightMatrix[i];
        }
        delete[] weightMatrix;
        delete[] students;
    }

    void addStudent(int index, string name, int id)
    {
        if (index >= 0 && index < nodes)
        {
            students[index] = student(name, id);
        }
    }

    void addEdge(int u, int v, int weight)
    {
        if (u >= 0 && u < nodes && v >= 0 && v < nodes)
        {
            weightMatrix[u][v] = weight;
            weightMatrix[v][u] = weight; // undirected graph
        }
    }

    void deleteEdge(int u, int v)
    {
        if (u >= 0 && u < nodes && v >= 0 && v < nodes)
        {
            weightMatrix[u][v] = 0;
            weightMatrix[v][u] = 0; // undirected graph
        }
    }

    int minDist(bool visited[], int dist[])
    {
        int minIndex = -1;
        int minDistance = INT_MAX;
        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i] && dist[i] < minDistance)
            {
                minDistance = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    void printPath(int parent[], int target)
    {
        if (parent[target] == -1)
        {
            cout << students[target].name;
            return;
        }
        printPath(parent, parent[target]);
        cout << " -> " << students[target].name;
    }

    void dijkstra(int start, int target)
    {
        if (start < 0 || start >= nodes || target < 0 || target >= nodes)
        {
            cout << "Error: Invalid start or target node index." << endl;
            return;
        }

        int *dist = new int[nodes];   // Stores shortest distance from start to each node
        int *parent = new int[nodes]; // Stores the predecessor node to reconstruct the path
        bool *visited = new bool[nodes]; // Track visited nodes

        // Initialize arrays
        for (int i = 0; i < nodes; i++)
        {
            dist[i] = INT_MAX;
            parent[i] = -1;
            visited[i] = false;
        }
        dist[start] = 0;

        for (int count = 0; count < nodes; count++)
        {
            int u = minDist(visited, dist);
            
            if (u == -1) { break; } // No more reachable nodes
            if (u == target) { break; } // Found target

            visited[u] = true;
            
            // Fix: Changed 'nodes++' to 'v++' in the loop condition
            for (int v = 0; v < nodes; v++)
            {
                int weight = weightMatrix[u][v];
                // Check if there's an edge and if we found a shorter path
                if (!visited[v] && weight > 0 && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    parent[v] = u;
                }
            }
        }

        // Print results
        cout << "\nDijkstra's Algorithm Results:" << endl;
        cout << "Shortest path from " << students[start].name << " to " << students[target].name << ": ";
        if (dist[target] == INT_MAX)
        {
            cout << "No path exists" << endl;
        }
        else
        {
            printPath(parent, target);
            cout << " (Total distance: " << dist[target] << ")" << endl;
        }

        // Clean up dynamic memory
        delete[] dist;
        delete[] parent;
        delete[] visited;
    }

    void display()
    {
        cout << "Adjacency Matrix (Weights):" << endl;
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << weightMatrix[i][j] << " ";
            }
            cout << endl;
        }

        cout << "\nStudent Information:" << endl;
        for (int i = 0; i < nodes; i++)
        {
            cout << "Node " << i << ": Name = " << students[i].name << ", ID = " << students[i].id << endl;
        }
    }
};

int main()
{
    Graph g(5);

    g.addStudent(0, "Alice", 101);
    g.addStudent(1, "Bob", 102);
    g.addStudent(2, "Charlie", 103);
    g.addStudent(3, "David", 104);
    g.addStudent(4, "Eve", 105);

    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 1, 4);
    g.addEdge(2, 3, 8);
    g.addEdge(2, 4, 2);
    g.addEdge(3, 4, 7);
    g.addEdge(4, 3, 9);

    g.display();
    g.dijkstra(0, 3);

    return 0;
}
