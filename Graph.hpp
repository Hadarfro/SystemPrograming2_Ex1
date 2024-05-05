#include <iostream>
#include <vector>
#include <queue>
#include <Graph.cpp>

//Graph(int v,vector<vector<int>> g) : V(v);
void addEdge(int u, int v);
int** buildNeighborMatrix();
void loadGraph(vector<vector<int>> g);
void printGraph();
void DFS(int v, bool visited[]);
int getV();
int** getAdjMat();
bool DFSFindCycle(int u, std::vector<bool>& visited, std::vector<int>& parent);