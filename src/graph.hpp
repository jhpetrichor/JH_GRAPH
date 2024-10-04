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

    // for (auto s : u_neighbors) {
    //     cout << s << " ";
    // }
    // cout << "\n";
    // for (auto s : v_neighbors) {
    //     cout << s << " ";
    // }
    // cout << "\n";
    // cout << "common neighbors: " << size << "\n";
    // for (auto s : common_neighbors) {
    //     cout << s << " ";
    // }
    // cout << "\n";

    return static_cast<double>(size) /
           static_cast<double>(u_neighbors.size() + v_neighbors.size() - size);
}

template <class T>
std::map<Edge<T>, double> Graph<T>::distance_floyd() const {

}

#endif  // JH_GRAPH_GRAPH_HPP
