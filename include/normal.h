/**
 * 归一化
 * 目前实现三种归一化方法
 * */

#ifndef JH_GRAPH_NORMAL_H
#define JH_GRAPH_NORMAL_H

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <type_traits>

using namespace std;

// 线性归一化
// 最小-最大归一化 归一化区间（0， 1）
vector<double> min_max_normalization_vector(const vector<double>& data);
template <typename T>
std::map<T, double> min_max_normalization_map(const std::map<T, double>& data);

// 平均归一化 结果区间(-1, 1)
vector<double> mean_normalization_vector(const vector<double>& data);
template <typename T>
std::map<T, double> mean_normalization_map(const std::map<T, double>& data);

// 非线性归一化
// 反余切函数转化
vector<double> atan_normalization_vector(const vector<double>& data);
template <typename T>
std::map<T, double> atan_normalization_map(const std::map<T, double>& data);

#include "normal.hpp"
#endif