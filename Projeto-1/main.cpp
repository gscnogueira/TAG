#include <bits/stdc++.h>

#define LINE_LEN 1000

using namespace std;

struct graph {

    vector<vector<int>> adj_list;

    graph(string file_name){

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

    void show(){
        for (uint i=0; i < adj_list.size(); i++){
            printf("%2d:", i+1);
            for(auto e : adj_list[i])
                printf("(%u, %u) ", i+1, e+1);
            printf("\n");
        }
    }
};

int main() {

    graph g("soc-dolphins.mtx");
    g.show();

}
