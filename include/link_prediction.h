#ifndef JH_GRAPH_LINK_PREDICTION_H
#define JH_GRAPH_LINK_PREDICTION_H

#include "graph.h"

#include <iostream>
#include <vector>

// 定义链路预测算法1
template <class T>
std::vector<double> lp_jaccard(const Graph<T>& g, std::vector<Edge<T>>& p_edges);

#include "jaccard.hpp"

#endif