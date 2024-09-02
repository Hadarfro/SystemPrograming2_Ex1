/*
 * Author: Hadar Froimowich.
 * ID: 213118458
 * Email: hadarfro12@gmail.com
 */
#include "doctest.hpp"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;
using namespace ariel;
using namespace doctest;

TEST_CASE("Test isConnected"){
    // Case 1: Empty graph
    ariel::graph g1;
    CHECK(Algorithms::isConnected(g1) == true); // Empty graph is considered connected

    // Case 2: Single vertex
    ariel::graph g2;
    g2.loadGraph({{0}});
    CHECK(Algorithms::isConnected(g2) == true); // Single vertex graph is connected

    // Case 3: Disconnected graph with no edges
    ariel::graph g3;
    g3.loadGraph({{0, 0}, {0, 0}});
    CHECK(Algorithms::isConnected(g3) == false); // Disconnected graph

    ariel::graph g;
    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isConnected(g) == true);

    vector<vector<int>> graph5 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph5);
    CHECK(Algorithms::isConnected(g) == false);

    // Complete graph
    ariel::graph g6;
    g6.loadGraph({{0, 1, 1}, {1, 0, 1}, {1, 1, 0}});
    CHECK(Algorithms::isConnected(g6) == true); // Complete graph is connected

    // Disconnected graph with a single isolated vertex
    ariel::graph g7;
    g7.loadGraph({{0, 1, 0}, {1, 0, 0}, {0, 0, 0}});
    CHECK(Algorithms::isConnected(g7) == false); // Disconnected graph with an isolated vertex

    // Random disconnected graph
    ariel::graph g8;
    g8.loadGraph({{0, 1, 0, 0}, {1, 0, 0, 0}, {0, 0, 0, 1}, {0, 0, 1, 0}});
    CHECK(Algorithms::isConnected(g8) == false); // Disconnected graph
}

TEST_CASE("Test shortestPath")
{
    // Case 1: Single vertex
    ariel::graph g1;
    g1.loadGraph({{0}});
    CHECK(Algorithms::shortestPath(g1, 0, 0) == 0); // Shortest path from a vertex to itself

    // Case 2: No path
    ariel::graph g2;
    g2.loadGraph({{0, 0}, {0, 0}});
    CHECK(Algorithms::shortestPath(g2, 0, 1) == -1); // No path between vertices
    
    ariel::graph g;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::shortestPath(g, 0, 2) == 2);

    vector<vector<int>> graph2 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph2);
    CHECK(Algorithms::shortestPath(g, 0, 4) == -1);

    ariel::graph g4;
    g4.loadGraph({{0, 1, 0}, {0, 0, 1}, {1, 0, 0}});
    CHECK(Algorithms::shortestPath(g4, 0, 2) == 2); // Shortest path traverses the cycle
    
    ariel::graph g5;
    g5.loadGraph({{0, 1, 0}, {0, 0, 0}, {0, 0, 0}});
    CHECK(Algorithms::shortestPath(g5, 0, 2) == -1); // No path between disconnected vertices

}

TEST_CASE("Test isContainsCycle"){
    // Case 1: Empty graph
    ariel::graph g1;
    CHECK(Algorithms::isContainsCycle(g1) == false); // Empty graph doesn't contain cycles

    // Case 2: Single vertex
    ariel::graph g2;
    g2.loadGraph({{0}});
    CHECK(Algorithms::isContainsCycle(g2) == false); // Single vertex graph doesn't contain cycles

    ariel::graph g;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isContainsCycle(g) == false);

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isContainsCycle(g) == true);
}

TEST_CASE("Test isBipartite"){
    // Case 1: Empty graph
    ariel::graph g1;
    CHECK(Algorithms::isBipartite(g1) == 1); // Empty graph is trivially bipartite

    // Case 2: Single vertex
    ariel::graph g2;
    g2.loadGraph({{0}});
    CHECK(Algorithms::isBipartite(g2) == 1); // Single vertex graph is trivially bipartite

    ariel::graph g;
    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g.loadGraph(graph3);
    CHECK(Algorithms::isBipartite(g) == 1);

    vector<vector<int>> graph4 = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0}};
    g.loadGraph(graph4);
    CHECK(Algorithms::isBipartite(g) == 0);

    vector<vector<int>> graph5 = {
        {0, 1, 2, 0, 0},
        {1, 0, 3, 0, 0},
        {2, 3, 0, 4, 0},
        {0, 0, 4, 0, 5},
        {0, 0, 0, 5, 0}};
    g.loadGraph(graph5);
    CHECK(Algorithms::isBipartite(g) == 0);
}

TEST_CASE("Test negativeCycle") {
    // Case 1: No negative cycle
    ariel::graph g1;
    g1.loadGraph({{0, 1, 0}, {0, 0, 1}, {1, 0, 0}});
    CHECK(Algorithms::negativeCycle(g1) == false); // No negative cycle

    // Case 2: Negative cycle in a directed graph
    ariel::graph g2;
    g2.loadGraph({{0, 1, 0}, {0, 0, -2}, {-1, 0, 0}});
    CHECK(Algorithms::negativeCycle(g2) == true); // Negative cycle in directed graph

    // Case 3: Negative cycle in an undirected graph
    ariel::graph g3;
    g3.loadGraph({{0, -1, -1}, {-1, 0, -1}, {-1, -1, 0}});
    CHECK(Algorithms::negativeCycle(g3) == true); // Negative cycle in undirected graph

    // Case 4: No cycle
    ariel::graph g4;
    g4.loadGraph({{0, 1, 0}, {0, 0, 1}, {0, 0, 0}});
    CHECK(Algorithms::negativeCycle(g4) == false); // No cycle

}

TEST_CASE("Test invalid graph") {
    ariel::graph g;
    vector<vector<int>> graph6 = {
        {0, 1, 2, 0},
        {1, 0, 3, 0},
        {2, 3, 0, 4},
        {0, 0, 4, 0},
        {0, 0, 0, 5}};
    CHECK_THROWS(g.loadGraph(graph6)); // Pass graph6 to loadGraph function
}
