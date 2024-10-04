#include "essential_protein.h"

template<class T>
std::map<T, double> degree_center(Graph<T>& g) {
	std::map<string, double> degree_center_result;
	for(const auto& node: g.degree) {
		degree_center_result[node.first] = static_cast<double>(node.second);
	}

    return degree_center_result;
}

template<class T>
std::map<T, double> closeness_center(Graph<T>& g) {
	std::map<Edge<T>, double> distance = g.distance_floyd();
	
}