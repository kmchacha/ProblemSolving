  #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[2000][2000];  // 인접 행렬
vector<int> g[2000];    // 인접 리스트
vector<pair<int, int> > edges;  // 간선 리스트

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int from, to;
        cin >> from >> to;

        // 인접 행렬
        a[from][to] = 1;
        a[to][from] = 1;
        // 인접 리스트
        g[from].push_back(to);
        g[to].push_back(from);
        // 간선 리스트
        edges.push_back({from, to});
        edges.push_back({to, from});

        m *= 2; // Undirected Graph
    }


    return 0;
}