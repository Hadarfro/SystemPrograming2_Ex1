#include <iostream>
#include <vector>
#ifndef GRAPH_HPP
#define GRAPH_HPP

using namespace std; 
namespace ariel{
    class graph{
        private:
            int V; // Number of vertices
            int** adjMat; // Adjacency matrix that represent the edges of the graph

        public:
            graph(int v,vector<vector<int>> g);
            graph();
            ~graph();
            void addEdge(int u, int v);
            int** buildNeighborMatrix();
            int printPath(std::vector<int>& parent, unsigned int u);
            void loadGraph(vector<vector<int>> g);
            void printGraph();
            void DFS(int v, bool visited[]);
            int getV();
            int** getAdjMat();
            bool DFSFindCycle(unsigned int u, std::vector<bool>& visited, std::vector<int>& parent);
    };
};
#endif // GRAPH_HPP