#include "link_prediction.h"

using namespace std;

template <class T>
std::vector<double> lp_jaccard(const Graph<T>& g,
                               std::vector<Edge<T>>& p_edges) {
    std::vector<double> result;
    for (const auto& e : p_edges) {
        double score_jaccard = g.jaccard(e[0], e[1]);
        result.emplace_back(score_jaccard);
    }

    return result;
}