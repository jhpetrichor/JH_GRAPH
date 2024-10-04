#ifndef JH_GRAPH_EDGE_HPP
#define JH_GRAPH_EDGE_HPP    

#include "graph.h"

template <class T>
Edge<T>::Edge(const T &u, const T &v) {
    if(source < v) {
        source = u;
        target = v;
    } else {
        target = u;
        source = v;
    }
}

template <class T>
bool Edge<T>::operator==(const Edge<T> &other) const { 
		return source == other.source && target == other.target;
}

template <class T>
bool Edge<T>::operator!=(const Edge<T> &other) const { 
	return source != other.source || target != other.target;
}

template <class T>
bool Edge<T>::operator<(const Edge<T> &other) const {
    if(source < other.source) {
        return true;
    } else if (source == other.source && target < other.target) {
        return true;
    }
    return false;
}

template <class T>
T& Edge<T>::operator[](std::size_t index) {
    if (index == 0) {
        return source;
    } else if (index == 1) {
        return target;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
const T& Edge<T>::operator[](std::size_t index) const {
    if (index == 0) {
        return source;
    } else if (index == 1) {
        return target;
    } else {
        throw std::out_of_range("Index out of range");
    }
}

template <class T>
std::ostream& operator<<(std::ostream &os, const Edge<T> &e) {
    os << "(" << std::get<0>(e) << ", " << std::get<1>(e) << ")";
    return os;
}

#endif // JH_GRAPH_EDGE_HPP