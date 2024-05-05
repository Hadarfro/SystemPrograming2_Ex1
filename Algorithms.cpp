#include <iostream>
#include "Graph.hpp"
#include <limits>

using namespace std;
using namespace ariel;

namespace Algorithms{
    int isConnected(Graph g){
        bool* visited = new bool[g.getV()]{false};
        // Start DFS from the first vertex
        DFS(0, visited);
        // Check if all vertices are connected
        for (int i = 0; i < g.getV(); i++){
            if (!visited[i]) {
                delete[] visited;
                return false;
            }
        }
        delete[] visited;
        return true;
    }

    int shortestPath(Graph g,int start,int end){//use bellman-ford
        int V = g.getV();
        std::vector<int> distance(V, std::numeric_limits<int>::max());
        std::vector<bool> visited(V, false);
        distance[start] = 0;
        for (int i = 0; i < V - 1; ++i) {
            int minDist = std::numeric_limits<int>::max();
            int minIndex = -1;
            // Find the vertex with the minimum distance
            for (int j = 0; j < V; ++j) {
                if (!visited[j] && distance[j] < minDist) {
                    minDist = distance[j];
                    minIndex = j;
                }
            }
            visited[minIndex] = true;
            // Update distances for adjacent vertices
            for (int j = 0; j < V; ++j) {
                if (!visited[j] && g.getAdjMat()[minIndex][j] != std::numeric_limits<int>::max() &&
                    distance[minIndex] + g.getAdjMat()[minIndex][j] < distance[j]) {
                    distance[j] = distance[minIndex] + g.getAdjMat()[minIndex][j];
                }
            }
        }
        if(distance[end] == 0){
            return -1;
        }
        return distance[end];
    }

    int isContainsCycle(Graph g){
        std::vector<int> parent(g.getV(), -1);
        std::vector<bool> visited(g.getV(), false);

        for (int u = 0; u < g.getV(); ++u){
            if (!visited[u] && g.DFSFindCycle(u, visited, parent)) {
                return g.printPath(parent, u);
            }
        }

        return 0;
    }

    int isBipartite(Graph g){
        
    }

    int negativeCycle(Graph g){//do relax v times and check if in the last relax there was a change

    }
}