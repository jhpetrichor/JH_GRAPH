# JH_GRAPH 简易复杂网络处理库
## usgae
+ 使用*xmake*管理代码
+ C++泛型实现

### example
```cpp
    Graph<string> g;
    auto edges = read_edges_string("../data/karate_club.txt");
    for (auto e : edges) {
        g.add_edge(get<0>(e), get<1>(e));
    }

    std::map<Edge<string>,double> distence = g.distance_floyd();
    for(auto const& d : distence) {
        // cout << std::get<0>(d.first) << "\t" << d.second << endl;
        cout << (d.first)[0] << "\t" << (d.first)[1] << "\t" << d.second << endl;
    }
```