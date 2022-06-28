#include <bits/stdc++.h>
#include "graph.h"

#define LINE_LEN 1000

using namespace std;

graph::graph(string file_name) {
  
        int M, N, L;
        ifstream fin(file_name);

        while (fin.peek() == '%') fin.ignore(LINE_LEN, '\n');

        fin >> M >> N >> L;

        adj_list.resize(M,{});

        int u, v;
        for (int i = 0; i < L; i++) {
            fin>>u>>v;
            u--;v--;
            adj_list[u].push_back(v);
            adj_list[v].push_back(u);
        }
        fin.close();
}

void graph::show() {
    
    for (uint u=0; u < adj_list.size(); u++){
        printf("%2d:", u+1);
        for(auto v : adj_list[u])
            printf("(%u, %u) ", u+1, v+1);
        printf("\n");
    }
}
