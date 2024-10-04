#ifndef JH_GRAPH_UTILS_H
#define JH_GRAPH_UTILS_H

#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

// io.cpp
using namespace std;

template <typename... Args>
vector<tuple<Args...>> read_edges_generic(const string& filename);

vector<tuple<string, string>> read_edges_string(const string& filename);
vector<tuple<string, string, double>> read_edges_string_weight(const string& filename);
vector<tuple<int, int>> read_edges_int(const string& filename);
vector<tuple<int, int, double>> read_edges_int_weight(const string& filename);


#endif JH_// GRAPH_UTILS_H
