#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
struct TData {
    std::vector<std::vector<long long>> ans;
    std::vector<std::vector<long long>> graph;
    std::vector<bool> used;
    long long  n,m;
    long long ansIndex;
};

void DepthFirstSearch(int v, TData& tdata) {
    if (!tdata.used[v]) {
        tdata.used[v] = true;
        tdata.ans[tdata.ansIndex].push_back(v);
        for (long long i:tdata.graph[v]) {
            DepthFirstSearch(i,tdata);
        }
    }
}
int main() {
    TData tdata;
  
    std::cin >> tdata.n >> tdata.m;
    tdata.graph.resize(tdata.n,std::vector<long long>());
    tdata.used.resize(tdata.n,false);
    tdata.ansIndex = 0;
    long long edge1, edge2;
    for (int i = 0; i<tdata.m;++i) {
        std::cin >> edge1  >> edge2;
        edge1--;
        edge2--;
        tdata.graph[edge1].push_back(edge2);
        tdata.graph[edge2].push_back(edge1);
    }
    for (int i = 0; i<tdata.n;++ i) {
       if (!tdata.used[i]) {
        //    std::cout << "sfsdfsfs\n";
           tdata.ans.resize(tdata.ansIndex+1);
           DepthFirstSearch(i, tdata);
           tdata.ansIndex++;
       }
    }
    for (int i = 0; i<tdata.ansIndex; ++i) {
        std::sort(tdata.ans[i].begin(),tdata.ans[i].end());
        for (long long v:tdata.ans[i]) {
            std::cout << v+1 << " ";
        }
        std::cout << std::endl;
    }
}