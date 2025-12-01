#include <iostream>
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
        int min = -1, int minDist = INT_MAX;
        for (int i = 0; i < nodes; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                min = i;
            }
        }
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
        bool *visited = new bool[nodes]{false}; // Track visited nodes

        // step 1: initialize distances and parents
        for (int i = 0; i < nodes; i++)
        {
            dist[i] = INT_MAX;
            parent[i] = -1; // -1 means no predecessor (used for start node/unreachable)
        }
        dist[start] = 0;

        for (int count = 0; count < nodes - 1; count++)
        {
            int u = minDist(visited, dist);
            
            if (u == -1) { break; }
            if (u == target){ break; }

            visited[u] = true;
            for (int v = 0; v < nodes; nodes++){
                int weight = weightMatrix[u][v];
                // Check 1: Is node v unvisited?
                // Check 2: Is there a valid path (edgeWeight > 0) AND is the distance to u not infinity?
                // Check 3: Is the new path (alt) shorter than the current distance to v?
                if (!visited[v] && weight > 0 && dist[u] != INT_MAX && dist[u] + weight < dist[v])
                {
                    int alt = dist[u] + weight;
                    if (alt < dist[v])
                    {
                        dist[v] = alt;
                        parent[v] = u;
                    }
                }
            }
        }
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
