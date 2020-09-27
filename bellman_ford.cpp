#include <iostream>
#include <vector>
#include <fstream>
#include <queue>
struct  Edge
{
    int64_t from;
    int64_t to;
    int64_t weight;


};


int main() {
     std::ofstream fs;
    std::ifstream input;
    fs.sync_with_stdio(false);
    fs.tie(nullptr);
    input.sync_with_stdio(false);
    input.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int64_t m,n,s,f;
    std::vector<std::vector<Edge>> edges;
    std::cin >> n >> m >> s >> f;
    edges.resize(n,std::vector<Edge>(0));

    s--;
    f--;
    for (int i = 0; i < m; ++i) {
        int64_t v1,v2,weight;
        std::cin >> v1 >> v2 >> weight;
        v1--;
        v2--;
        edges[v1].push_back({v1,v2,weight});    
    }
    std::vector<int64_t> ans;
    std::queue<uint64_t> nowV;
    ans.resize(n,INT64_MAX);
    ans[s] = 0;
    nowV.push(s);
    if (s==f) {
        std::cout << 0 << std::endl;
        return 0;
    }

    while (!nowV.empty())
    {
        int64_t j = nowV.front();
        nowV.pop();
        for (int k = 0; k <edges[j].size(); ++k) {
            if (ans[edges[j][k].to]>ans[j]+edges[j][k].weight) {
                ans[edges[j][k].to] = ans[j]+edges[j][k].weight;
                nowV.push(edges[j][k].to);
            }
        }
    }
    
    if (ans[f]==INT64_MAX) {
        std::cout << "No solution" << std::endl;
        return 0;
    }
    std::cout << ans[f] << std::endl;
}
