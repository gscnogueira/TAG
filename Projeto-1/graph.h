#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <bits/stdc++.h>

#define vi vector<int>

using namespace std;
struct graph {

    vector<vi> adj_list;

    graph(string file_name);

    uint size();
    void show();
    vi get_neighbours(int v);

};

inline uint graph::size() {return adj_list.size();}

inline vi graph::get_neighbours(int v) {
    return adj_list[v];
}


#endif
