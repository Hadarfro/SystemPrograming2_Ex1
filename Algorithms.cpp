#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;

namespace Algorithms{
    int isConnected(ariel::graph g){
        bool* visited = new bool[g.getV()]{false};
        // Start DFS from the first vertex
        g.DFS(0, visited);
        // Check if all vertices are connected
        for (std::vector<int>::size_type i = 0; i < g.getV(); i++){
            if (!visited[i]) {
                delete[] visited;
                return false;
            }
        }
        delete[] visited;
        return true;
    }

    int shortestPath(ariel::graph g,std::vector<int>::size_type start,std::vector<int>::size_type end){//use bellman-ford
        std::vector<int>::size_type V = (std::vector<int>::size_type)g.getV();
        std::vector<int> dist(V, std::numeric_limits<int>::max());
        std::vector<bool> visited(V, false);
        dist[start] = 0;
        for(int i = 0; i < V - 1; ++i) {
            std::vector<int>::size_type minDist = std::numeric_limits<int>::max();
            std::vector<int>::size_type minIndex = static_cast<std::vector<int>::size_type>(-1);
            // Find the vertex with the minimum distance
            for (std::vector<int>::size_type j = 0; j < V; ++j) {
                if (!visited[j] && dist[j] < minDist) {
                    minDist = static_cast<std::vector<int>::size_type>(dist[j]);
                    minIndex = j;
                }
            }
            visited[(decltype(visited.size()))minIndex] = true;
            // Update distances for adjacent vertices
            for (std::vector<int>::size_type j = 0; j < V; ++j) {
                if (!visited[j] && g.getAdjMat()[minIndex][j] != std::numeric_limits<int>::max() &&
                    dist[minIndex] + g.getAdjMat()[minIndex][j] < dist[j]) {
                    dist[j] = dist[minIndex] + g.getAdjMat()[minIndex][j];
                }
            }
        }
        if(dist[end] == 0){
            return -1;
        }
        return dist[end];
    }

    int isContainsCycle(ariel::graph g){
        std::vector<int>::size_type v = (std::vector<int>::size_type)g.getV();
        std::vector<int> parent(v, -1);
        std::vector<bool> visited(v, false);

        for (std::vector<int>::size_type u = 0; u < v; ++u){
            if (!visited[u] && g.DFSFindCycle(u, visited, parent)) {
                return g.printPath(parent, u);
            }
        }

        return 0;
    }

    int isBipartite(ariel::graph g){
        return 0;
    }

    int negativeCycle(ariel::graph g){//do relax v times and check if in the last relax there was a change
        return 0;
    }
}