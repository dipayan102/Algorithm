//
// Created by Dipayan Bhattacharya on 3/7/17.
//

#include "WeightedGraph.hpp"

using namespace std;

WeightedGraph::WeightedGraph(bool isDirected) {
    this->isDirected = isDirected;
}

void WeightedGraph::addEdge(int src, int dest, int weight) {
    if(adjList.find(src) != adjList.end()) {
        adjList[src]->push_back(new GraphNode(weight, dest));
    } else {
        vector<GraphNode *> *newNode = new vector<GraphNode *>;
        newNode->push_back(new GraphNode(weight, dest));
        adjList[src] = newNode;
    }
    if(!isDirected) {
        if(adjList.find(dest) != adjList.end()) {
            adjList[dest]->push_back(new GraphNode(weight, src));
        } else {
            vector<GraphNode *> *newNode = new vector<GraphNode *>;
            newNode->push_back(new GraphNode(weight, src));
            adjList[dest] = newNode;
        }
    }
}

ostream& operator<<(std::ostream &os, const WeightedGraph &graph) {

    for(auto it : graph.adjList) {
        if (!it.second->empty()) {
            os << it.first << " : ";
            for(GraphNode *j : (*it.second)) {
                os<<"[num="<<j->node_num<<",weight="<<j->weight<<"] ";
            }
            os<<endl;
        } else {
            os << it.first << " : empty" << endl;
        }
    }
    os<<endl;
    return os;
}

void WeightedGraph::rec_maxSumPath(int cur_node, vector<int>& result, int cur_sum, int& max_sum,
                    vector<int>& cur_path, unordered_set<int>& visited) {
    cur_path.push_back(cur_node);
    visited.insert(cur_node);
    for(GraphNode *i : (*adjList[cur_node])) {
        if(visited.find(i->node_num) != visited.end()
                  || adjList[i->node_num]->empty()) {
            if(max_sum < cur_sum + i->weight) {
                cur_path.push_back(i->node_num);
                result = cur_path;
                cur_path.pop_back();
                max_sum = cur_sum + i->weight;
            }
        } else {
            rec_maxSumPath(i->node_num, result, cur_sum + i->weight, max_sum, cur_path, visited);
        }
    }
    cur_path.pop_back();
    visited.erase(cur_node);
}

vector<int>* WeightedGraph::getMaxSumPath() {
    vector<int>* result = new vector<int>;
    unordered_set<int> visited;
    vector<int> cur_path;
    int max_sum = 0;
    for(auto it : adjList) {
        rec_maxSumPath(it.first, *result, 0, max_sum, cur_path, visited);
    }
    return result;
}

void WeightedGraph::rec_getAllPathsWithWeights(int cur_node, vector<pair<vector<int>, int> >& result, int cur_sum,
                                vector<int>& cur_path, unordered_set<int>& visited) {
    visited.insert(cur_node);
    cur_path.push_back(cur_node);
    for(GraphNode *node : (*adjList[cur_node])) {
        if(visited.find(node->node_num) != visited.end()
                  || adjList[node->node_num]->empty()) {
            cur_path.push_back(node->node_num);
            pair<vector<int>, int> p;
            p.first = cur_path;
            p.second = cur_sum + node->weight;
            result.push_back(p);
            cur_path.pop_back();
        } else {
            rec_getAllPathsWithWeights(node->node_num, result, cur_sum + node->weight, cur_path, visited);
        }
    }
    cur_path.pop_back();
    visited.erase(cur_node);
}

vector<pair<vector<int>, int> >* WeightedGraph::getAllPathsWithWeights() {
    vector<pair<vector<int>, int> > *result = new vector<pair<vector<int>, int> >;
    unordered_set<int> visited;
    vector<int> cur_path;
    int max_sum = 0;
    for(auto it : adjList) {
        rec_getAllPathsWithWeights(it.first, *result, 0, cur_path, visited);
    }
    return result;
}

void WeightedGraph::getUnweightedShortestPath(int node, int dest, unordered_set<int>& visited,
                            vector<int>& cur_path, vector<int>& cur_result) {
    visited.insert(node);
    cur_path.push_back(node);
    for(GraphNode *cur_node : (*adjList[node])) {
        if(cur_node->node_num == dest) {
            cur_path.push_back(cur_node->node_num);
            if(cur_path.size() < cur_result.size() || cur_result.empty()) {
                cur_result = cur_path;
            }
            cur_path.pop_back();
        } else if(visited.find(cur_node->node_num) == visited.end()) {
            getUnweightedShortestPath(cur_node->node_num, dest, visited, cur_path, cur_result);
        }
    }
    cur_path.pop_back();
    visited.erase(node);
}

vector<int> WeightedGraph::getUnweightedShortestPath(int src, int dest) {
    vector<int> result;
    unordered_set<int> visited;
    vector<int> cur_path;
    getUnweightedShortestPath(src, dest, visited, cur_path, result);
    return result;
}

void WeightedGraph::getWeightedShortestPath(int node, int dest, int& min_sum, int cur_sum,
                                              unordered_set<int>& visited,
                                              vector<int>& cur_path,
                                              vector<int>& cur_result) {
    visited.insert(node);
    cur_path.push_back(node);
    for(GraphNode *cur_node : (*adjList[node])) {
        if(cur_node->node_num == dest) {
            if(cur_sum + cur_node->weight < min_sum) {
                min_sum = cur_sum + cur_node->weight;
                cur_result = cur_path;
                cur_result.push_back(cur_node->node_num);
            }
        } else if(visited.find(cur_node->node_num) == visited.end()) {
            if(cur_sum + cur_node->weight < min_sum) {
                getWeightedShortestPath(cur_node->node_num, dest, min_sum, cur_sum + cur_node->weight,
                                        visited, cur_path, cur_result);
            }
        }
    }
    cur_path.pop_back();
    visited.erase(node);
}

pair<int, vector<int> > WeightedGraph::getWeightedShortestPath(int src, int dest) {
    int min_sum = INT_MAX;
    vector<int> cur_path, cur_result;
    unordered_set<int> visited;
    getWeightedShortestPath(src, dest, min_sum, 0, visited, cur_path, cur_result);
    return pair<int, vector<int> >(min_sum, cur_result);
}