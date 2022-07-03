#include <bits/stdc++.h>
#include "utils.h"

#define vi vector<int>
#define bset bitset<100>

using namespace std;

bset vect2set(vi vec) {
    bset s;
    for (auto e:vec) s.set(e);
    return s;
}

void show_set(bset s) {
    printf(" * %lu vértices: ", s.count());

    printf("{");
    for (uint i = 0; i < s.size(); i++) 
      if (s.test(i)) 
        printf("%d, ", i+1);
    printf("}\n");
}
