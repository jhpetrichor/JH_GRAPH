#include "utils.h"

#include <fstream>
#include <sstream>
#include <type_traits> // for std::enable_if, std::is_same
#include <cstddef> 

// Helper to read a tuple from istream
template <std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
read_tuple(std::istream &, std::tuple<Tp...> &) { }

template <std::size_t I = 0, typename... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
read_tuple(std::istream & is, std::tuple<Tp...>& t) {
    is >> std::get<I>(t);
    read_tuple<I + 1, Tp...>(is, t);
}

// Define operator >> for a tuple
template<typename... Ts>
std::istream& operator>>(std::istream& in, std::tuple<Ts...>& t) {
    read_tuple(in, t);
    return in;
}

// Generic function template for reading edges
template <typename... Args>
vector<tuple<Args...>> read_edges_generic(const string& filename) {
    ifstream infile(filename);
    if (!infile.is_open()) {
        cerr << "[Error] Error opening file: " << filename << endl;
        exit(1);
    }

    vector<tuple<Args...>> edges;
    string line;
    while (getline(infile, line)) {
        istringstream iss(line);
        tuple<Args...> edge;
        iss >> edge;
        edges.emplace_back(edge);
    }

    return edges;
}

// Explicit instantiation of the function template for required types
template vector<tuple<string, string>> 
read_edges_generic<string, string>(const string& filename);

template vector<tuple<string, string, double>>
read_edges_generic<string, string, double>(const string& filename);

template vector<tuple<int, int>> 
read_edges_generic<int, int>(const string& filename);

template vector<tuple<int, int, double>> 
read_edges_generic<int, int, double>(const string& filename);

// Wrapper functions
vector<tuple<string, string>> read_edges_string(const string& filename) {
    return read_edges_generic<string, string>(filename);
}

vector<tuple<string, string, double>> read_edges_string_weight(const string& filename) {
    return read_edges_generic<string, string, double>(filename);
}

vector<tuple<int, int>> read_edges_int(const string& filename) {
    return read_edges_generic<int, int>(filename);
}

vector<tuple<int, int, double>> read_edges_int_weight(const string& filename) {
    return read_edges_generic<int, int, double>(filename);
}