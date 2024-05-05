#include "Graph.hpp"
#include <vector>

using namespace std; 
using namespace ariel;
int isConnected(ariel::graph g);
int shortestPath(ariel::graph g,int start,int end);
int isContainsCycle(ariel::graph g);
int isBipartite(ariel::graph g);
int negativeCycle(ariel::graph g);
