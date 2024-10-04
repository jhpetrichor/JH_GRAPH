#include <iostream>

#include "graph.h"
#include "link_prediction.h"
#include "utils.h"
#include "essential_protein.h"
#include "normal.h"

using namespace std;

int main() {
    Graph<string> g;
    auto edges = read_edges_string("../data/dip.txt");
    for (auto e : edges) {
        g.add_edge(get<0>(e), get<1>(e));
    }

    cout << "Node count: " << g.node_count() << endl;
    Edge<string> e = {"YPL139C", "YPL181W"};
    vector<Edge<string>> p_edges = {e, {"YPL253C", "YPR141C"}};
    auto result = lp_jaccard(g, p_edges);
    for (auto r : result) {
        cout << r << endl;
    }

    auto degree = degree_center(g);
    for(const auto& it: degree) {
        cout << it.first << ": " << it.second << endl;
    }

    //std::map<string, double> degree = {{"YPL139C", 2.0}, {"YPL181W", 3.0}, {"YPL253C", 1.0}, {"YPR141C", 210}};


    auto data = mean_normalization_map(degree);
    for(const auto& it: data) {
        cout << it.first << ": " << it.second << endl;
    }

    
    auto data1 = atan_normalization_map(degree);
    for(const auto& it: data1) {
        cout << it.first << ": " << it.second << endl;
    }

    return 0;
}