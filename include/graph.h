#ifndef JH_GRAPH_GRAPH_H
#define JH_GRAPH_GRAPH_H

#include <iostream>
#include <map>
#include <set>
#include <tuple>
#include <memory>

template <class T>
class Edge {
public:
    T source;
    T target;

public:
    Edge() = default;
    Edge(const T &u, const T &v);
    bool operator==(const Edge<T> &other) const;
    bool operator!=(const Edge<T> &other) const;
    bool operator<(const Edge<T> &other) const;
    T &operator[](std::size_t index);
    const T &operator[](std::size_t index) const;
    friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e);
    // friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {
    //     os << "(" << std::get<0>(e) << ", " << std::get<1>(e) << ")";
    //     return os;
    // }
};

template <class T>
class Graph {
public:
    std::map<T, unsigned int> degree;
    std::map<T, std::set<T>> neighbors;
    std::map<Edge<T>, double> edges;
    std::set<T> nodes;
    std::map<Edge<T>, double>* distance;   //

   public:
    [[nodiscard]]
    unsigned node_count() const;
    void add_node(T vertex);
    void add_edge(T u, T v, float weight = 1);
    // void add_edges(T u, T v);
    bool is_connected(T u, T v) const;
    std::set<T> get_nth_neighbors(T vertex, unsigned n) const;
    double jaccard(const T &u, const T &v) const;  // 获取节点对之间的jaccard系数
    std::map<Edge<T>, double> distance_floyd() const;  // 弗洛伊德算法，获取所有节点之间的距离
};

#include "graph.hpp"
#include "edge.hpp"

#endif  // endif GRAPH_GRAPH_H