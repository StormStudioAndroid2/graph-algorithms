#include <vector>
#include <iostream>
#include <set>
struct Edge
{
    uint64_t to;
    uint64_t weight;
};


struct  V
{
    std::vector<Edge> edges;
    uint64_t ans;
    uint64_t ind;
    
};
struct Compare {
    bool operator() (const V& lhs, const V& rhs) const {
        return lhs.ans<rhs.ans;
    }
};
struct TData {
    std::vector<V> graph;
    uint64_t s,f,m,n;
    std::vector<bool> used;
};
int main() {
    TData tdata;
    std::cin >> tdata.n >> tdata.m >> tdata.s >> tdata.f;
    tdata.s--;
    tdata.f--;
   
    tdata.graph.resize(tdata.n, {std::vector<Edge>(0),UINT64_MAX, 0 });
     for (int i = 0; i <tdata.n; ++i) {
        tdata.graph[i].ind = i;
    }
    tdata.used.resize(tdata.n,false);
    for (int i = 0 ; i < tdata.m; ++ i) {
        uint64_t v1, v2, weight;
        std::cin >> v1 >> v2 >> weight;
        v1--;
        v2--;
        tdata.graph[v1].edges.push_back({v2,weight});
        tdata.graph[v2].edges.push_back({v1,weight});
    }
    if (tdata.s==tdata.f) {
        std::cout << 0 << std::endl;
        return 0;
    }
    tdata.graph[tdata.s].ans = 0;
    std::set<V,Compare> mins;
    mins.insert(tdata.graph[tdata.s]);
    for (int i =  0; !mins.empty(); ++ i ) {
            uint64_t min = mins.begin()->ind;
            mins.erase(mins.begin());
        tdata.used[min] = true;

        for (int j = 0; j < tdata.graph[min].edges.size(); ++j) {
            if (tdata.graph[min].ans+tdata.graph[min].edges[j].weight<tdata.graph[tdata.graph[min].edges[j].to].ans) {
                tdata.graph[tdata.graph[min].edges[j].to].ans = tdata.graph[min].ans+tdata.graph[min].edges[j].weight;
                if (!tdata.used[tdata.graph[min].edges[j].to]) {
                    mins.insert(tdata.graph [tdata.graph[min].edges[j].to]);
                }
            }
        }
    }
    if (tdata.graph[tdata.f].ans==UINT64_MAX) {
        std::cout << "No solution" << std:: endl;
        return 0;
    }
    std::cout << tdata.graph[tdata.f].ans << std::endl;
 
}