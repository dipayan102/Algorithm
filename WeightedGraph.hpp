//
// Created by Dipayan Bhattacharya on 3/7/17.
//

#ifndef ALGORITHM_WEIGHTEDGRAPH_HPP
#define ALGORITHM_WEIGHTEDGRAPH_HPP

#include "Graph.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_set>

class GraphNode {
public:
    int weight;
    int node_num;

    GraphNode(int weight, int node_num) {
        this->weight = weight;
        this->node_num = node_num;
    }
};

class WeightedGraph {
private:
    std::map<int, std::vector<GraphNode *>*> adjList;
    bool isDirected;
    void rec_maxSumPath(int cur_node, std::vector<int>& result, int cur_sum, int& max_sum,
                        std::vector<int>& cur_path, std::unordered_set<int>& visited);
    void rec_getAllPathsWithWeights(int cur_node, std::vector<std::pair<std::vector<int>, int> >& result, int cur_sum,
            std::vector<int>& cur_path, std::unordered_set<int>& visited);
    void getUnweightedShortestPath(int node, int dest, std::unordered_set<int>& visited,
                                   std::vector<int>& cur_path, std::vector<int>& cur_result);
    void getWeightedShortestPath(int node, int dest, int& min_sum, int cur_sum,
                                                std::unordered_set<int>& visited,
                                                std::vector<int>& cur_path,
                                                std::vector<int>& cur_result);

public:
    WeightedGraph(bool isDirected);
    void addEdge(int src, int dest, int weight);
    std::vector<int>* getMaxSumPath();
    std::vector<std::pair<std::vector<int>, int> >* getAllPathsWithWeights();
    std::vector<int> getUnweightedShortestPath(int src, int dest);
    std::pair<int, std::vector<int> > getWeightedShortestPath(int src, int dest);
    friend std::ostream& operator<<(std::ostream &os, const WeightedGraph &graph);
};


#endif //ALGORITHM_WEIGHTEDGRAPH_HPP
