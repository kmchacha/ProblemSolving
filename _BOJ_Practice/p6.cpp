#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <set>

using namespace std;

struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex=a, dis=b;
    }
    bool operator < (const Edge& b) const{
        return dis > b.dis;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, m, a, b, c;  // 
    cin >> n >> m >> a >> b >> c;
    // 교차로 개수, 골목 개수, 시작 점, 도착 점, 가진 돈
    vector<pair<int, int> > graph[n+1];
    vector<int> dist(n+1, 2147000000);
    vector<int> pre[n+1]; // 이전 노드 순
    priority_queue<Edge> pQ;
    for(int i=1;i<=m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
        graph[to].push_back(make_pair(from, cost));
    }
    dist[a]=0; pre[a].push_back(0);
    pQ.push(Edge(a, 0));
    while(!pQ.empty()){
        int cur = pQ.top().vex;
        int dis = pQ.top().dis;
        pQ.pop();
        if(dist[cur] < dis) continue;
        for(int i=0;i<graph[cur].size();i++){
            int next = graph[cur][i].first;
            int nextDis = graph[cur][i].second + dis;
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                pre[next].push_back(cur);
                pQ.push(Edge(next, nextDis));
            }
        }
    }
    if(dist[b] > c) cout << -1 << '\n';
    else {
        int idx = b, minn=2147000000;
        for(int i=0;i<pre[idx].size();i++){
            
        }
        cout << minn << '\n';;
    }
    return 0;
}