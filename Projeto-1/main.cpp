#include <bits/stdc++.h>
#include "graph.h"

#define vi vector<int>
#define bset bitset<100>

using namespace std;


void show_set(bset s) {
    printf("{");
    for (uint i = 0; i < s.size(); i++) 
      if (s.test(i)) 
        printf("%d, ", i);
    printf("}\n");
}

void KB(graph g, bset p={}, bset r={}, bset x={}) {

    if (p.none() && r.none() && x.none()) {
        p.set();
        // Inicializa conjunto p com todos os vértices :
        p = ~(p&(p<<g.size()));
    }

    else if (p.none() && x.none()) {
        printf("{");
        for (uint i =0; i<g.size(); i++) 
            if(r.test(i))
                printf("%d,", i+1);
        printf("}\n");
        return;
    }

    // show_set(p);
    vi neighbours;
    bset neighbours_set;
    for (uint i = 0; i < g.size(); i++) {

        if(not p.test(i))
            continue;

        bset p_new, r_new, x_new;

        neighbours = g.get_neighbours(i);
        for (auto neighbour:neighbours) neighbours_set.set(neighbour);

        p_new = p & neighbours_set;
        r_new = r;
        r_new.set(i);
        x_new = x & neighbours_set;

        KB(g, p_new, r_new, x_new);
        p.reset(i);
        x.set(i);

        neighbours_set.reset();
    }
}

int main() {

    graph g("soc-dolphins.mtx");
    vi P, R, X;
    KB(g);

}
