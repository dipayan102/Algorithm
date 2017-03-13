//
// Created by Dipayan Bhattacharya on 2/25/17.
//

#include "Graph.hpp"
#include "WeightedGraph.hpp"

using namespace std;

/**
 *
 *    0 -----------> 1
 *    ^            /
 *    |          /
 *    |        /    / \
 *    |      /     \   /
 *    V   V         \ /
 *    2 ------------>3
 * @param g
 */
void generateGraph(Graph& g) {
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
}

void generateWeightedGraph(WeightedGraph& g) {
    g.addEdge(0, 1, 20);
    g.addEdge(0, 2, 40);
    g.addEdge(1, 2, 30);
    g.addEdge(2, 0, 10);
    g.addEdge(2, 3, 35);
    g.addEdge(3, 3, 0);
}

/**
 * http://d1hyf4ir1gqw6c.cloudfront.net//wp-content/uploads/Fig-11.jpg
 * @param g
 */
void generateBigUndirectedGraph(WeightedGraph& g) {
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(1, 2, 8);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 14);
    g.addEdge(3, 4, 9);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
}

void dfs_test_adjMatrix() {
    Graph g(4, false, true);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<g<<endl;
    g.dfs([](int i) { cout << i << " "; });
}

void dfs_test_adjList() {
    Graph g(4, false, false);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<g<<endl;
    g.dfs([](int i) { cout << i << " "; });
}

void bfs_test_adjList() {
    Graph g(4, false, true);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<g<<endl;
    g.bfs(2, [](int i) { cout << i << " "; });
}

void bfs_test_adjMatrix() {
    Graph g(4, true, true);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout<<g<<endl;
    g.bfs(2, [](int i) { cout << i << " "; });
}

void normal_test_adjlist() {
    Graph graph(5,false,false);
    graph.addEdge(0,1);
    graph.addEdge(0,4);
    graph.addEdge(1,4);
    graph.addEdge(1,3);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
    cout<<graph<<endl;
}

void normal_test_adjmatrix() {
    Graph graph(5,true,false);
    graph.addEdge(0,1);
    graph.addEdge(0,4);
    graph.addEdge(1,4);
    graph.addEdge(1,3);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(3,4);
    cout<<graph<<endl;
}

void test_getCycles() {
    Graph g1(4, false, true), g2(4, true, true);
    generateGraph(g1);
    generateGraph(g2);
    cout<<g1<<endl;
    vector<vector<int> > result = g1.getAllCycles();
    for(vector<int> i : result) {
        cout<<"[";
        for(int j : i) {
            cout<<j<<" ";
        }
        cout<<"] ";
    }
    cout<<endl;
    result.clear();

    cout<<g2<<endl;
    result = g2.getAllCycles();
    for(vector<int> i : result) {
        cout<<"[";
        for(int j : i) {
            cout<<j<<" ";
        }
        cout<<"] ";
    }
    result.clear();
}

void test_MaxSum() {
    WeightedGraph g(true);
    generateWeightedGraph(g);
    cout<<g<<endl;

    cout<<"All Paths :-"<<endl;
    vector<pair<vector<int>, int> >* allPaths = g.getAllPathsWithWeights();
    for(auto it1 : *allPaths) {
        cout<<"Path : [";
        for(int i : it1.first) {
            cout<<i<<" ";
        }
        cout<<"], Weight = "<<it1.second<<endl;
    }

    vector<int> *maxSumPath = g.getMaxSumPath();
    cout<<"MaxSumPath = ";
    for(int i : *maxSumPath) {
        cout<<i<<" ";
    }
    cout<<endl;
}

void test_unweighted_shortest_path() {
    WeightedGraph g(true);
    generateWeightedGraph(g);
    cout<<g<<endl;

    for(int i=0;i<=3;i++) {
        for(int j=0;j<=3;j++) {
            if(j != i) {
                cout << "Shortest path between " << i << " and " << j << " :- ";
                vector<int> result = g.getUnweightedShortestPath(i, j);
                for(int k : result) {
                    cout<<k<<" ";
                }
                if(result.empty()) {
                    cout<<" "<<i<<" cannot reach "<<j;
                }
                cout<<endl;
            }
        }
    }
}

void test_weighted_shortest_path() {
    WeightedGraph g(false);
    generateBigUndirectedGraph(g);
    cout<<g<<endl;

    cout<<"All Paths :-"<<endl;
    vector<pair<vector<int>, int> >* allPaths = g.getAllPathsWithWeights();
    for(auto it1 : *allPaths) {
        cout<<"Path : [";
        for(int i : it1.first) {
            cout<<i<<" ";
        }
        cout<<"], Weight = "<<it1.second<<endl;
    }
    cout<<endl;

    for(int i=0;i<=8;i++) {
        for(int j=0;j<=8;j++) {
            if(j != i) {
                cout << "Shortest path between " << i << " and " << j << " :- ";
                pair<int, vector<int> > result = g.getWeightedShortestPath(i, j);
                for(int k : result.second) {
                    cout<<k<<" ";
                }
                if(result.second.empty()) {
                    cout<<" "<<i<<" cannot reach "<<j;
                } else {
                    cout << " Cost = "<<result.first;
                }
                cout<<endl;
            }
        }
    }
}


int main(int argc, char **argv) {
    test_weighted_shortest_path();
//    test_unweighted_shortest_path();
//    test_MaxSum();
//    test_getCycles();
//    dfs_test_adjMatrix();
//    dfs_test_adjList();
//    bfs_test_adjMatrix();
//    bfs_test_adjList();
//    normal_test_adjlist();
//    normal_test_adjmatrix();
    return 0;
}
