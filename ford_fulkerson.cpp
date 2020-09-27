#include <vector>

#include <iostream>
#include <queue>
struct TEdge {
    long long to;
    long long weight;
};
struct TData  {
    std::vector<long long> parent;
    std::vector<bool> visited;
    std::vector<std::vector<long long>> graph;
    long long n,m;
};
bool BreadthFirstSearch(TData& tdata) {
    std::queue<long long> nextStep;
    for (int i = 0; i<tdata.n; ++i) {
        tdata.visited[i] = false;
    } 
    nextStep.push(0);
    tdata.visited[0] = true;
    while (!nextStep.empty()) {
        for (int i = 0; i<tdata.n; ++i) {
            long long v = nextStep.front();
            if (tdata.graph[v][i]!=0 && !tdata.visited[i]) {
                nextStep.push(i);
                tdata.visited[i] = true;
                tdata.parent[i] = v;
            }
        }
        nextStep.pop();
    }
    return tdata.visited[tdata.n-1];
}
long long FordFulkerson(TData& tdata) {
    long long maxFlow = 0;
    long long nowFlow = 0;

    while (BreadthFirstSearch(tdata)) {
        nowFlow = __LONG_LONG_MAX__;
        for (long long v = tdata.n-1; v!=0; v = tdata.parent[v]) {
            long long u = tdata.parent[v];
            nowFlow = std::min(nowFlow,tdata.graph[u][v]);
        }

        for (long long v = tdata.n-1; v!=0; v = tdata.parent[v]) {
            long long u = tdata.parent[v];
            tdata.graph[u][v]-=nowFlow;
            tdata.graph[v][u]+=nowFlow;
        }
        maxFlow+=nowFlow;
    }
    return maxFlow;


}
int main() {
    TData tdata;
    std::cin >> tdata.n >> tdata.m;
    long long edge1,edge2, weight;
    tdata.parent.resize(tdata.n,-1);
    tdata.graph.resize(tdata.n,std::vector<long long>(tdata.n,0));
    tdata.visited.resize(tdata.n,false);
    for (int i = 0; i<tdata.m; ++i) {
        std::cin >> edge1 >> edge2 >> weight;
        edge1--;
        edge2--;
        tdata.graph[edge1][edge2] = weight;
    }
    std::cout << FordFulkerson(tdata) << std::endl;
}