/* Author: Gabriel da Silva Corvino Nogueira
 * Email : gab.nog94@gmail.com
 * Github: https://github.com/nosgueira
 */

#include <bits/stdc++.h>
#include "graph.h"
#include "utils.h"

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

bool graph::connected(int a, int b) {
    auto n = get_neighbours(a);
    for(auto e : n){
        if (e == b)
            return true;
    }
    return false;
}

int choose_pivot(graph g, bset candidates) {
    
    vector<pair<int, int>> rank;
    for( uint v =0; v<g.size(); v++)
        if(candidates.test(v))
            rank.push_back({g.get_neighbours(v).size(), v});

    sort(rank.rbegin(), rank.rend());
    return rank[0].second;

}

void KB(graph g,bool pivoting, bset p, bset r, bset x) {

    if (p.none() && r.none() && x.none()) {
        p.set();
        p = ~(p&(p<<g.size()));
    }

    else if (p.none() && x.none()) {
        show_set(r);
        return;
    }

    bset v_neighbours, pv_neighbours;

    if (pivoting) {
        int pv = choose_pivot(g, p|x);
        pv_neighbours = vect2set(g.get_neighbours(pv));
    }

    for (uint v = 0; v < g.size(); v++) {

        if(not (p&(~pv_neighbours)).test(v))
            continue;

        bset p_new, r_new, x_new;

        v_neighbours = vect2set(g.get_neighbours(v));
        p_new = p & v_neighbours;
        r_new = r;
        r_new.set(v);
        x_new = x & v_neighbours;

        KB(g, pivoting, p_new, r_new, x_new);
        p.reset(v);
        x.set(v);

        v_neighbours.reset();
    }
}

double clustering_coefficient(graph g) {
    double cc=0;

    for(uint v = 0; v < g.size(); v++){
        auto n = g.get_neighbours(v);

        if (n.size() < 2)
            continue;

        int t = 0;
        for (uint i = 0; i<n.size(); i++){
            for (uint j = i+1; j<n.size(); j++){
                if(g.connected(n[i], n[j]))
                    t++;
            }
        }
        
        cc+=2.0*t/(n.size()*(n.size()-1));
    }
    cc/=g.size();

    return cc;
}
