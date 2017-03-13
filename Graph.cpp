//
// Created by Dipayan Bhattacharya on 2/25/17.
//

#include "Graph.hpp"

using namespace std;

ostream& operator<<(std::ostream &os, const Graph &graph) {
    if(graph.isAdjMatrix) {
        for(int i=0;i<graph.numVertices;i++) {
            for(int j=0;j<graph.numVertices;j++) {
                os<<graph.adjMatrix[i][j]<<" ";
            }
            os<<endl;
        }
    } else {
        for (int i = 0; i < graph.numVertices; i++) {
            if (!graph.adjList[i].empty()) {
                os << i << " : ";
                for(int j : graph.adjList[i]) {
                    os<<j<<" ";
                }
                os<<endl;
            } else {
                os << i << " : empty" << endl;
            }
        }
    }
    return os;
}

Graph::Graph(unsigned int numVertices, bool isAdjMatrix, bool isDirected) {
    this->numVertices = numVertices;
    this->isAdjMatrix = isAdjMatrix;
    this->isDirected = isDirected;
    if(!isAdjMatrix) {
        adjList = new vector<int>[numVertices];
    } else {
        adjMatrix = new int*[numVertices];
        for(int i=0;i<numVertices;i++) {
            adjMatrix[i] = (int*)calloc(numVertices, sizeof(int));
        }
    }
}

void Graph::addEdge_adjList(int src, int dest) {
    adjList[src].push_back(dest);
    if(!isDirected) {
        adjList[dest].push_back(src);
    }
}

void Graph::addEdge_adjMatrix(int src, int dest) {
    adjMatrix[src][dest] = 1;
    if(!isDirected) {
        adjMatrix[dest][src] = 1;
    }
}

void Graph::bfs_adjList(int start, void (*func)(int)) {
    queue<int> q;
    unordered_set<int> visited(numVertices);
    q.push(start);
    visited.insert(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        func(cur);
        for(int i : adjList[cur]) {
            if(visited.find(i) == visited.end()) {
                visited.insert(i);
                q.push(i);
            }
        }
    }
}

void Graph::bfs_adjMatrix(int start, void (*func)(int)) {
    queue<int> q;
    unordered_set<int> visited(numVertices);
    q.push(start);
    visited.insert(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        func(cur);
        for(int i=0;i<numVertices;i++) {
            if(adjMatrix[cur][i]) {
                if(visited.find(i) == visited.end()) {
                    visited.insert(i);
                    q.push(i);
                }
            }
        }
    }
}

void Graph::recursive_dfs_adjList(int start, void (*func)(int),
                                  unordered_set<int>& visited) {
    visited.insert(start);
    func(start);
    for(int i : adjList[start]) {
        if(visited.find(i) == visited.end()) {
            recursive_dfs_adjList(i, func, visited);
        }
    }
}

void Graph::recursive_dfs_adjMatrix(int start, void (*func)(int),
                                    std::unordered_set<int>& visited) {
    visited.insert(start);
    func(start);
    for(int i=0;i<numVertices;i++) {
        if(visited.find(i) == visited.end()) {
            recursive_dfs_adjList(i, func, visited);
        }
    }
}

void Graph::getAllCycles_adjList(int start, unordered_set<int>& visited, vector<int>& cur,
                                vector<vector<int> >& result) {
    if(visited.find(start) != visited.end()) {
        if(!cur.empty() && cur[0] == cur.back()) {
            result.push_back(cur);
        }
        return;
    }
    visited.insert(start);
    for(int i : adjList[start]) {
        cur.push_back(i);
        getAllCycles_adjList(i, visited, cur, result);
        cur.pop_back();
    }
    visited.erase(start);
}

void Graph::getAllCycles_adjMatrix(int start, unordered_set<int>& visited, vector<int>& cur,
                                                   vector<vector<int> >& result) {
    if(visited.find(start) != visited.end()) {
        if(!cur.empty() && cur[0] == cur.back()) {
            result.push_back(cur);
        }
        return;
    }
    visited.insert(start);
    for(int i=0;i<numVertices;i++) {
        if(adjMatrix[start][i]) {
            cur.push_back(i);
            getAllCycles_adjMatrix(i, visited, cur, result);
            cur.pop_back();
        }
    }
    visited.erase(start);
}


void Graph::addEdge(int src, int dest) {
    if(isAdjMatrix) {
        addEdge_adjMatrix(src, dest);
    } else {
        addEdge_adjList(src, dest);
    }
}

void Graph::bfs(int start, void (*func)(int)) {
    if(isAdjMatrix) {
        bfs_adjMatrix(start, func);
    } else {
        bfs_adjList(start, func);
    }
}

void Graph::dfs(void (*func)(int)) {
    unordered_set<int> visited(numVertices);
    if(isAdjMatrix) {
        for(int i=0;i<numVertices;i++) {
            if(visited.find(i) == visited.end()) {
                recursive_dfs_adjMatrix(i, func, visited);
            }
        }
    } else {
        for(int i=0;i<numVertices;i++) {
            if(visited.find(i) == visited.end()) {
                recursive_dfs_adjList(i, func, visited);
            }
        }
    }
}

vector<vector<int> > Graph::getAllCycles() {
    unordered_set<int> visited(numVertices);
    vector<vector<int> > result;
    vector<int> cur;
    if(isAdjMatrix) {
        for(int i=0;i<numVertices;i++) {
            cur.push_back(i);
            getAllCycles_adjMatrix(i, visited, cur, result);
            cur.pop_back();
        }
    } else {
        for(int i=0;i<numVertices;i++) {
            cur.push_back(i);
            getAllCycles_adjList(i, visited, cur, result);
            cur.pop_back();
        }
    }
    return result;
}



