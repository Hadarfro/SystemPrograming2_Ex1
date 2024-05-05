#include <iostream>
#include <vector>
#include <queue>
#include "Graph.hpp"

using namespace std;
namespace ariel{
    graph::graph(){//defult constractor
        this->V = 0;
        this->adjMat =NULL;
    }
    // Destructor to deallocate memory
    graph::~graph() {
        for (int i = 0; i < V; ++i) {
            delete[] adjMat[i];
        }
        delete[] adjMat;
    }

    // Function to add an edge to the graph
    void graph::addEdge(int u, int v) {
        adjMat[u][v] = 1;
        adjMat[v][u] = 1; // If it's an undirected graph
        this->V++;
    }


    // Depth-First Search (DFS)
    void graph::DFS(int v, bool visited[]) {
        visited[v] = true;
        for (unsigned int i = 0; i < V; ++i) {
            if (adjMat[v][i] && !visited[i]) {
                DFS((int)i, visited);
            }
        }
    }

        bool graph::DFSFindCycle(unsigned int u, std::vector<bool>& visited, std::vector<int>& parent) {
        visited[u] = true;
        for (unsigned int i = 0;i < this->V;i++) {
            if (!visited[i] && i != u) {
                parent[i] = (int)u;
                if (DFSFindCycle(i, visited, parent)) {
                    return true;
                }
            } else if (parent[u] != i) {
                return true;
            }
        }

        return false;
    }

    int graph::printPath(std::vector<int>& parent, unsigned int u) {
        std::vector<int> path;
        unsigned int v = u;
        int t = (int)u;

        // Construct the cycle path
        do {
            path.push_back((int)v);
            t = parent[v];
            v = (unsigned int)t;
        } while (v != u && t != u);

        // Print the cycle
        std::cout << "Cycle: ";
        for (unsigned int i = path.size() - 1; i >= 0; --i) {
            std::cout << path[i] << " ";
        }
        std::cout << std::endl;
        return 1;
    }

    int graph::getV(){
        return this->V;
    }

    int** graph::getAdjMat(){
        return this->adjMat;
    }

    void graph::loadGraph(vector<vector<int>> g) {
        // Reinitialize the current graph object with the new graph data
        this->V = g.size();

        // Deallocate memory for the existing adjacency matrix
        for (unsigned int i = 0; i < V; ++i) {
            delete[] adjMat[i];
        }
        delete[] adjMat;

        // Dynamically allocate memory for the new adjacency matrix
        adjMat = new int*[V];
        for (unsigned int i = 0; i < V; ++i) {
            adjMat[i] = new int[V];
            // Initialize all elements to 0
            for (unsigned int j = 0; j < V; ++j) {
                adjMat[i][j] = g[i][j];
            }
        }
    }

    void graph::printGraph(){//print the number of vertex and edges
        // Print the neighbor matrix
        std::cout << "Neighbor Matrix:" << std::endl;
        for (unsigned int i = 0; i < 5; ++i) {
            for (unsigned int j = 0; j < 5; ++j) {
                std::cout << this->adjMat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
    
};

using namespace ariel;
int main() { // Create a graph with 5 vertices
    vector<vector<int>> mygraph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    ariel::graph g(5,mygraph);

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