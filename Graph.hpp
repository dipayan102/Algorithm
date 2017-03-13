//
// Created by Dipayan Bhattacharya on 2/25/17.
//

#ifndef ALGORITHM_GRAPH_HPP
#define ALGORITHM_GRAPH_HPP

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

class Graph {
private:
    std::vector<int> *adjList;
    int **adjMatrix;
    unsigned int numVertices;
    bool isDirected;
    bool isAdjMatrix;
    void addEdge_adjList(int src, int dest);
    void addEdge_adjMatrix(int src, int dest);
    void bfs_adjList(int, void (*)(int));
    void bfs_adjMatrix(int, void (*)(int));
    void recursive_dfs_adjList(int, void (*)(int), std::unordered_set<int>&);
    void recursive_dfs_adjMatrix(int, void (*)(int), std::unordered_set<int>&);
    void getAllCycles_adjList(int start, std::unordered_set<int>& visited, std::vector<int>& cur,
                              std::vector<std::vector<int> >& result);
    void getAllCycles_adjMatrix(int start, std::unordered_set<int>& visited, std::vector<int>& cur,
                                std::vector<std::vector<int> >& result);
public:
    Graph(unsigned int numVertices)
            : Graph(numVertices, false, false) {
    }
    Graph(unsigned int numVertices, bool isAdjMatrix)
            : Graph(numVertices, isAdjMatrix, false) {
    }
    Graph(unsigned int numVertices, bool isAdjMatrix, bool isDirected);
    void addEdge(int src, int dest);
    void bfs(int start, void (*func)(int));
    void dfs(void (*func)(int));
    std::vector<std::vector<int> > getAllCycles();
    friend std::ostream& operator<<(std::ostream &os, const Graph &graph);
};


#endif //ALGORITHM_GRAPH_HPP
