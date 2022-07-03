#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <bits/stdc++.h>
#include "utils.h"

#define vi vector<int>

using namespace std;


struct graph {

    vector<vi> adj_list;

    graph(string file_name);

    uint size();
    void show();
    vi get_neighbours(int v);
    bool connected(int a, int b);

};

inline uint graph::size() {return adj_list.size();}

inline vi graph::get_neighbours(int v) {
    return adj_list[v];
}

int choose_pivot(graph g, bset candidates);

void KB(graph g,bool pivoting, bset p={}, bset r={}, bset x={});

double clustering_coefficient(graph g);

#endif
