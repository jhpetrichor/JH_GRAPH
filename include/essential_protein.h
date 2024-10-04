#ifndef JH_GRAPH_ESSENTIAL_PROTEIN_H
#define JH_GRAPH_ESSENTIAL_PROTEIN_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 中心性相关算法
// 度中心性
template<class T>
std::map<T, double> degree_center(Graph<T>& g);

/*
* closeness centrality
* 由于PIN有不联通的情况，因此使用第三种紧密中心性算法
* C(x) = \sum_{y \in V \and y !=x } \frac{1}{d(x, y)}
*/
template<class T>
std::map<T, double> closeness_center(Graph<T>& g);

#include "centrality.hpp"

// 结构洞相关
#endif