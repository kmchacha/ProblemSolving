#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

// 다익스트라 알고리즘 --> struct, priority queue(pop)
struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex = a;
        dis = b;
    }
    bool operator < (const Edge &b) const {
        return dis > b.dis;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m, s, e, cnt=1; // 도시의 개수, 버스의 개수 , 시작 노드, 도착 노드
    cin >> n;
    cin >> m;
    vector<int> dist(n+1, 2147000000), pre_path(n+1);
    vector<pair<int, int> > graph[n+1];
    priority_queue<Edge> pQ;
    for(int i=1;i<=n;i++) pre_path[i]=i;
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
    }
    cin >> s >> e;
    dist[s]=0;
    pQ.push(Edge(s, 0));
    while(!pQ.empty()){
        int now = pQ.top().vex;
        int cost = pQ.top().dis;
        pQ.pop();
        if(cost > dist[now]) continue;
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            int nextDis = graph[now][i].second + cost;
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                pre_path[next] = now;
                pQ.push(Edge(next,nextDis));
            }
        }
    }
    cout << dist[e] << '\n';   // s 에서 e 까지 가는 최소거리 출력
    vector<int> ans(n+1);       // s 에서 e 까지의 경로 저장 공간
    ans[cnt]=e;
    int tmp=e;
    while(tmp != s){
        tmp = pre_path[tmp];
        cnt++;
        ans[cnt] = tmp;
    }
    cout << cnt << '\n'; 
    for(int i=cnt;i>=1;i--){
        cout << ans[i] << " ";
    }
    return 0;
}
