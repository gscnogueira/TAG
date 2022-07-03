#include <bits/stdc++.h>
#include "graph.h"


using namespace std;

int main() {

    graph g("soc-dolphins.mtx");

    printf("+-------------------------------------------+\n");
    printf("|     BRON-KERBOSCH (COM PIVOTEAMENTO)      |\n");
    printf("+-------------------------------------------+\n");
    KB(g, true);

    printf("+-------------------------------------------+\n");
    printf("|     BRON-KERBOSCH (SEM PIVOTEAMENTO)      |\n");
    printf("+-------------------------------------------+\n");
    KB(g, false);

    printf("---------------------------------------------\n");
    printf("==> coeficiente de alglomeração médio: %lf\n", clustering_coefficient(g));


}
