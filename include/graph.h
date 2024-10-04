#ifndef JH_GRAPH_GRAPH_H
#define JH_GRAPH_GRAPH_H

#include <iostream>
#include <map>
#include <set>
#include <tuple>

template <class T>
class Edge {
public:
    std::tuple<T, T> edge;
    Edge() = default;

    Edge(const T &u, const T &v) : edge(u, v) {}

    bool operator==(const Edge<T> &other) const { return edge == other.edge; }
    bool operator!=(const Edge<T> &other) const { return edge != other.edge; }

    bool operator<(const Edge<T> &other) const { return edge < other.edge; }

    T &operator[](std::size_t index) {
        if (index == 0) {
            return std::get<0>(edge);
        } else if (index == 1) {
            return std::get<1>(edge);
        } else {
            throw std::out_of_range("Index out of range");
        }
      }

    const T &operator[](std::size_t index) const {
        if (index == 0)
            return std::get<0>(edge);
        else if (index == 1)
            return std::get<1>(edge);
        else
            throw std::out_of_range("Index out of range");
    }

    friend std::ostream &operator<<(std::ostream &os, const Edge<T> &e) {
        os << "(" << e.get_u() << ", " << e.get_v() << ")";
        return os;
    }
};

template <class T>
class Graph {
public:
    std::map<T, unsigned int> degree;
    std::map<T, std::set<T>> neighbors;
    std::map<Edge<T>, float> edges;
    std::set<T> nodes;

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
}

#include "graph.hpp"

#endif  // endif GRAPH_GRAPH_H