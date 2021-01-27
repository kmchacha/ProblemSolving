#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int candidate[101];

struct Edge{
    int vertex;
    int dist;
    Edge(int a, int b){
        vertex = a;
        dist = b;
    }
    bool operator < (const Edge& b) const{
        return dist > b.dist;
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int T, n, m, t, s, g, h;
    cin >> T;
    while(T-->0){
        cin >> n >> m >> t;
        cin >> s >> g >> h;
        vector<pair<int, int> > graph[n+1];
        vector<int> dist(n+1, 2147000000);
        vector<int> dist_g(n+1, 2147000000);
        // 가중치 그래프 만들기
        for(int i=1;i<=m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            graph[a].push_back(make_pair(b,c));
            graph[b].push_back(make_pair(a,c));
        }
        // 목적지 후보 입력 받기
        for(int i=1;i<=t;i++){
            cin >> candidate[i];
        }
        priority_queue<Edge> pQ;    // Min priority queue 만들기
        pQ.push(Edge(s, 0));   // s번 vetex의 가중치가 0이다
        dist[s]=0;
        while(!pQ.empty()){
            int now = pQ.top().vertex;
            int cost = pQ.top().dist;
            pQ.pop();
            if(dist[now] > cost) continue;
            for(int i=0;i<graph[now].size();i++){
                int next = graph[now][i].first;
                int nextDis = cost + graph[now][i].second;
                if(dist[next] > nextDis){
                    dist[next] = nextDis;
                    pQ.push(Edge(next,nextDis));
                }
            }
        }
        // 더 거리가 먼 곳을 g로 고정
        if(dist[g] <= dist[h]) {
            int temp = g;
            g = h;
            h = temp;
        }
        pQ.push(Edge(g, 0));
        dist_g[g] = 0;
        while(!pQ.empty()){
            int now = pQ.top().vertex;
            int cost = pQ.top().dist;
            pQ.pop();
            if(dist_g[now] > cost) continue;
            for(int i=0;i<graph[now].size();i++){
                int next = graph[now][i].first;
                int nextDis = cost + graph[now][i].second;
                if(dist_g[next] > nextDis){
                    dist_g[next] = nextDis;
                    pQ.push(Edge(next,nextDis));
                }
            }
        }
        sort(candidate+1, candidate+1+t);
        for(int i=1;i<=t;i++){
            int cand = candidate[i];
            if(dist[cand] == (dist[g] + dist_g[cand])) cout << cand << " ";
        }
        cout << '\n';
    }

    return 0;
}