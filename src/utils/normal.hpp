#include "normal.h"

#include <numeric>
#include <functional>
#include <cmath>

const double PI = 3.14159265358979323846;

vector<double> min_max_normalization_vector(const vector<double>& data) {
	double max = *max_element(data.begin(), data.end());
	double min = *min_element(data.begin(), data.end());
	vector<double> normalized_data(data.size());
	transform(data.begin(), data.end(), 
		normalized_data.begin(), [&min, &max](double val) {
			return (val - min) / (max - min);
	});
	
	return normalized_data;
}

template <typename T>
std::map<T, double> min_max_normalization_map(const std::map<T, double>& data) {
    if (data.empty()) {
        return std::map<T, double>();
    }

    auto max_pair = *std::max_element(data.begin(), data.end(),
                                      [](const std::pair<T, double>& a, const std::pair<T, double>& b) {
                                          return a.second < b.second;
                                      });
    double max = max_pair.second;

    auto min_pair = *std::min_element(data.begin(), data.end(),
                                      [](const std::pair<T, double>& a, const std::pair<T, double>& b) {
                                          return a.second < b.second;
                                      });
    double min = min_pair.second;

    std::map<T, double> normalized_data;
    std::transform(data.begin(), data.end(), std::inserter(normalized_data, normalized_data.begin()),
                   [&min, &max](const std::pair<T, double>& val) {
                       if (max == min) {
                           // If all elements are the same, normalize them to 0.5 or some constant
                           return std::pair<T, double>(val.first, 0.5);
                       } else {
                           return std::pair<T, double>(val.first, (val.second - min) / (max - min));
                       }
                   });

    return normalized_data;
}

vector<double> mean_normalization_vector(const vector<double>& data) {
	double max = *max_element(data.begin(), data.end());
	double min = *min_element(data.begin(), data.end());
	double mean = std::accumulate(data.begin(), data.end(), 0.0) / data.size();
    vector<double> normalized_data(data.size());
    transform(data.begin(), data.end(), normalized_data.begin(),
			[&mean, &max, &min](double val){ 
			return (val - mean) / (max - min);
		});
    return normalized_data;
}

template <typename T>
std::map<T, double> mean_normalization_map(const std::map<T, double>& data) {
    if (data.empty()) {
        return std::map<T, double>();
    }

    auto max_pair = *std::max_element(data.begin(), data.end(),
                                      [](const std::pair<T, double>& a, const std::pair<T, double>& b) {
                                          return a.second < b.second;
                                      });
    double max = max_pair.second;

    auto min_pair = *std::min_element(data.begin(), data.end(),
                                      [](const std::pair<T, double>& a, const std::pair<T, double>& b) {
                                          return a.second < b.second;
                                      });
    double min = min_pair.second;

    double mean = std::accumulate(data.begin(), data.end(), 0.0, [](double sum, const std::pair<T, double>& b) {
        return sum + b.second;
    }) / data.size();

    std::map<T, double> normalized_data;
    std::transform(data.begin(), data.end(), std::inserter(normalized_data, normalized_data.begin()),
                   [&mean, &max, &min](const std::pair<T, double>& val) { return std::pair<T, double>(val.first, (val.second - mean)/(max - min)); });

    return normalized_data;
}

vector<double> atan_normalization_vector(const vector<double>& data) {
	vector<double> normalized_data(data.size());
	transform(data.begin(), data.end(), 
		normalized_data.begin(), [](double val) {
			return atan(val) * 2 / PI;
	});
	return normalized_data;
}

template <typename T>
std::map<T, double> atan_normalization_map(const std::map<T, double>& data) {
    std::map<T, double> normalized_data;
    std::transform(data.begin(), data.end(), std::inserter(normalized_data, normalized_data.begin()),
                   [](const std::pair<T, double>& val) {
                       return std::pair<T, double>(val.first, atan(val.second) * 2 / PI);
                   });
	return normalized_data;
}