#ifndef __GRAPH_H__
#define __GRAPH_H__

#include <bits/stdc++.h>

using namespace std;
struct graph {

    vector<vector<int>> adj_list;

    graph(string file_name);

    void show();
};

#endif
