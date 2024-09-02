/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */

#include <iostream>
#include <stdexcept>
#include <vector>
#include "Graph.hpp"
#include "Algorithms.hpp"
using namespace std;
using namespace ariel;
using namespace Algorithms;

int main()
{
    ariel::graph g;
     // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph1); // Load the graph to the object.

    g.printGraph();                    // Should print: "Graph with 3 vertices and 3 edges."
    Algorithms::isConnected(g);        // Should print: "1" (true).
    Algorithms::shortestPath(g, 0, 2); // Should print: "0->1->2".
    Algorithms::isContainsCycle(g);    // Should print: "0" (false).
    Algorithms::isBipartite(g);        // Should print: "The graph is bipartite: A={0, 2}, B={1}".
    Algorithms::negativeCycle(g);

    // 5x5 matrix that represents a non-connected graph with a cycle.
    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};

    g.loadGraph(graph2); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 8 edges."
    Algorithms::isConnected(g);        // Should print: "0" (false).
    Algorithms::shortestPath(g, 0, 4); // Should print: "-1" (there is no path between 0 and 4).
    Algorithms::isContainsCycle(g);    // Should print: "The cycle is: 0->1->2->0".
    Algorithms::isBipartite(g);        // Should print: "0" (false).

    // 5x5 matrix that represents a connected weighted graph.
    vector<vector<int>> graph3 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph3); // Load the graph to the object.

    g.printGraph();                                    // Should print: "Graph with 5 vertices and 10 edges."
    Algorithms::isConnected(g) ;        // Should print: "1" (true).
    Algorithms::shortestPath(g, 0, 4) ; // Should print: "0->2->3->4".
    Algorithms::isContainsCycle(g);    // Should print: "0" (false).
    Algorithms::isBipartite(g);        // Should print: "The graph is not bipartite"
    

     // 5x4 matrix that represents an invalid graph.
    vector<vector<int>> graph4 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    try
    {
        g.loadGraph(graph4); // Load the graph to the object.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print: "Invalid graph: The graph is not a square matrix."
    }
}
