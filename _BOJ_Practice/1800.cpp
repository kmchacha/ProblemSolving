#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

// 목표: N번 컴퓨터가 인터넷에 연결하는 것이다
// 원장선생님이 내게 되는 최소의 값
struct Edge{
    int v;
    int dist;
    Edge(int a, int b){
        v=a; dist=b;
    }
    bool operator < (const Edge &b) const{
        return dist > b.dist;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, p, k; // n 학생의 수, p 케이블 선의 수, k 공짜로 제공하는 케이블 선의 수
    cin >> n >> p >> k;
    vector<pair<int, int> > graph[n+1];
    vector<int> dist(n+1, 2147000000);
    for(int i=1;i<=p;i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b,c));
        graph[b].push_back(make_pair(a,c));
    }
    priority_queue<Edge> pQ;
    pQ.push(Edge(1,0));
    dist[1]=0;
    while(!pQ.empty()){
        int now = pQ.top().v;
        int cost = pQ.top().dist;
        pQ.pop();                                   // ************* POP 꼭 해주기 ***************
        if(dist[now] > cost) continue;
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i].first;
            int nextDis = graph[now][i].second + cost;
            if(dist[next] > nextDis) {
                dist[next] = nextDis;
                pQ.push(Edge(next,nextDis));
            }
        }
    }
    if(dist[n] == 2147000000) { cout << -1 << '\n'; exit(0);}
    
    return 0;
}