#include <iostream>
#include <vector>
#include <queue>
using namespace std;
namespace ariel{//build defult constractor!!!!!!!!!!!!!!!
    class Graph{
    private:
        int V; // Number of vertices
        int** adjMat; // Adjacency matrix that represent the edges of the graph

    public:
        Graph(int v,vector<vector<int>> g) : V(v) {//check if the matix is a square matrix
            // Dynamically allocate memory for the adjacency matrix
            adjMat = new int*[V];
            for (int i = 0; i < V; i++) {
                adjMat[i] = new int[V];
                // Initialize all elements to 0
                for (int j = 0; j < V; ++j) {
                    adjMat[i][j] = g[i][j];
                }
            }
        }
        // Destructor to deallocate memory
        ~Graph() {
            for (int i = 0; i < V; ++i) {
                delete[] adjMat[i];
            }
            delete[] adjMat;
        }

        // Function to add an edge to the graph
        void addEdge(int u, int v) {
            adjMat[u][v] = 1;
            adjMat[v][u] = 1; // If it's an undirected graph
            this->V++;
        }

        // Function to build the neighbor matrix using BFS
        int** buildNeighborMatrix() {
            int** neighborMatrix = new int*[V];
            for (int i = 0; i < V; ++i) {
                neighborMatrix[i] = new int[V];
                // Initialize all elements to 0
                for (int j = 0; j < V; ++j) {
                    neighborMatrix[i][j] = 0;
                }
            }

            // Perform BFS from each vertex
            for (int i = 0; i < V; ++i) {
                std::queue<int> q;
                bool* visited = new bool[V] {false};

                q.push(i);
                visited[i] = true;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v = 0; v < V; ++v) {
                        if (adjMat[u][v] == 1 && !visited[v]) {
                            neighborMatrix[i][v] = 1;
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }

                delete[] visited;
            }

            return neighborMatrix;
        }

         // Depth-First Search (DFS)
        void DFS(int v, bool visited[]) {
            visited[v] = true;
            for (int i = 0; i < V; ++i) {
                if (adjMat[v][i] && !visited[i]) {
                    DFS(i, visited);
                }
            }
        }

        bool DFSFindCycle(int u, std::vector<bool>& visited, std::vector<int>& parent) {
        visited[u] = true;
        for (int i = 0;i < this->V;i++) {
            if (!visited[i] && i != u) {
                parent[i] = u;
                if (DFSFindCycle(i, visited, parent)) {
                    return true;
                }
            } else if (parent[u] != i) {
                return true;
            }
        }

        return false;
    }

         int printPath(std::vector<int>& parent, int u) {
            std::vector<int> path;
            int v = u;

            // Construct the cycle path
            do {
                path.push_back(v);
                v = parent[v];
            } while (v != u);

            // Print the cycle
            std::cout << "Cycle: ";
            for (int i = path.size() - 1; i >= 0; --i) {
                std::cout << path[i] << " ";
            }
            std::cout << std::endl;
            return 1;
        }

        int getV(){
            return this->V;
        }

        int** getAdjMat(){
            return this->adjMat;
        }

        void loadGraph(vector<vector<int>> g){
            Graph graph(sizeof(g),g);
        }

        void printGraph(){//print the number of vertex and edges
            // Print the neighbor matrix
            std::cout << "Neighbor Matrix:" << std::endl;
            for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                    std::cout << this->adjMat[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
    };
}

using namespace ariel;
int main() { // Create a graph with 5 vertices
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    Graph g(5,graph);

    // Add edges
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    // Build the neighbor matrix
    int** neighborMatrix = g.buildNeighborMatrix();

    // Print the neighbor matrix
    std::cout << "Neighbor Matrix:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << neighborMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    // Deallocate memory for neighbor matrix
    for (int i = 0; i < 5; ++i) {
        delete[] neighborMatrix[i];
    }
    delete[] neighborMatrix;

    return 0;
}