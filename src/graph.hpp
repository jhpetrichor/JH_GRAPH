#ifndef JH_GRAPH_GRAPH_HPP
#define JH_GRAPH_GRAPH_HPP

#include "graph.h"

#include <algorithm>
using namespace std;

template <class T>
[[nodiscard]]
unsigned Graph<T>::node_count() const {
    return nodes.size();
}

template <class T>
void Graph<T>::add_node(T vertex) {
    if (nodes.find(vertex) == nodes.end()) {
        nodes.insert(vertex);
        neighbors[vertex] = std::set<T>();
    }
}

template <class T>
bool Graph<T>::is_connected(T u, T v) const {
    return neighbors.at(u).find(v) != neighbors.at(u).end();
}

template <class T>
void Graph<T>::add_edge(T u, T v, float weight) {
    add_node(u);
    add_node(v);
    neighbors[u].insert(v);
    neighbors[v].insert(u);
    edges[{u, v}] = weight;
    edges[{v, u}] = weight;
    degree[u]++;
    degree[v]++;
}

// template <class T>
// void Graph<T>::add_edges(T u, T v) {

// }

template <class T>
std::set<T> Graph<T>::get_nth_neighbors(T vertex, unsigned n) const {
    std::set<T> result;
    if (n == 0) {
        result.insert(vertex);
        return result;
    }
    std::set<T> current_level = neighbors.at(vertex);
    for (unsigned i = 1; i < n; ++i) {
        std::set<T> next_level;
        for (const auto &neighbor : current_level) {
            const auto &further_neighbors = neighbors.at(neighbor);
            next_level.insert(further_neighbors.begin(),
                              further_neighbors.end());
        }
        current_level = next_level;
    }
    return current_level;
}

template <class T>
double Graph<T>::jaccard(const T &u, const T &v) const {
    // 分别获取节点的邻居
    std::set<T> u_neighbors = this->get_nth_neighbors(u, 1);
    std::set<T> v_neighbors = this->get_nth_neighbors(v, 1);
    std::set<T> common_neighbors;
    std::set_intersection(
        u_neighbors.begin(), u_neighbors.end(), v_neighbors.begin(),
        v_neighbors.end(),
        std::inserter(common_neighbors, common_neighbors.begin()));
    int size = common_neighbors.size();
    return static_cast<double>(size) /
           static_cast<double>(u_neighbors.size() + v_neighbors.size() - size);
}

template <class T>
std::map<Edge<T>, double> Graph<T>::distance_floyd() const {
    std::map<Edge<T>, double> distance;

    // Initialize the distance map with direct edge weights or 'infinity' if there is no edge
    for (const auto& node : nodes) {
        for (const auto& neighbor : neighbors.find(node)->second) {
            distance[Edge<T>(node, neighbor)] = edges.find(Edge<T>(node, neighbor))->second;
        }
        for (const auto& otherNode : nodes) {
            if (node != otherNode && neighbors.find(node)->second.find(otherNode) == neighbors.find(node)->second.end()) {
                distance[Edge<T>(node, otherNode)] =std::numeric_limits<double>::max(); // Infinity
            }
        }
    }

        // Floyd-Warshall algorithm
    for (const auto& intermediate : nodes) {
        for (const auto& from : nodes) {
            for (const auto& to : nodes) {
                if (distance[Edge<T>(from, to)] > distance[Edge<T>(from, intermediate)] + distance[Edge<T>(intermediate, to)]) {
                    distance[Edge<T>(from, to)] = distance[Edge<T>(from, intermediate)] + distance[Edge<T>(intermediate, to)];
                }
            }
        }
    }

    return distance;
}

#endif  // JH_GRAPH_GRAPH_HPP
