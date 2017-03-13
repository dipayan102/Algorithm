cmake_minimum_required(VERSION 3.5)
project(Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Algorithm ${SOURCE_FILES})

add_executable(BinarySearchTree BinarySearchTree.cpp BinarySearchTree.hpp BinarySearchTreeTest.cpp)
add_executable(LCA BinarySearchTree.cpp BinarySearchTree.hpp LCA.cpp)
add_executable(minheap MinHeap.cpp MinHeap.hpp MinHeapTest.cpp utils.cpp utils.hpp)
add_executable(median Median.cpp)
add_executable(trie trie.cpp trie.hpp trie_test.cpp)
add_executable(util_test UtilsTest.cpp utils.cpp utils.hpp)
add_executable(thread_test ThreadTest.cpp)
add_executable(scheduler Scheduler.cpp)
add_executable(graphtest Graph.cpp Graph.hpp GraphTest.cpp WeightedGraph.cpp WeightedGraph.hpp)
add_executable(coinchange coinchange.cpp)
add_executable(sorttest SortUtil.cpp SortUtil.hpp SortTest.cpp)