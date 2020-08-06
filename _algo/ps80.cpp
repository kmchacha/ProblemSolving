/*
'******************************************************************************
' 파일명    : pps80.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/27
' 문제      : 다익스트라 알고리즘
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
struct Edge{
    int vex;
    int dis;
    Edge(int a, int b){
        vex=a;
        dis=b;
    }
    bool operator < (const Edge &b) const{
        return dis>b.dis; 
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    priority_queue<Edge> pQ;
    vector<pair<int, int> > graph[30];
    int i, n, m, a, b, c;
    cin >> n >> m;
    vector<int> dist(n+1);
    for(i=1; i<=m; i++){
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
    }
    for(i=0; i<=n; i++) dist[i]=2147000000;
    pQ.push(Edge(1,0));
    dist[1]=0;
    while(!pQ.empty()){
        int now = pQ.top().vex;
        int cost = pQ.top().dis;
        pQ.pop();
        if(cost>dist[now]) continue;
        for(i=0;i<graph[now].size();i++){
            int next=graph[now][i].first;
            int nextDis=cost+graph[now][i].second;
            if(dist[next]>nextDis){
                dist[next]=nextDis;
                pQ.push(Edge(next, nextDis));
            }
        }
    }
    for(i=2;i<=n;i++){
        if(dist[i]==2147000000) {
            cout << i << " : " << "impossible" << endl;
            continue;
        }
        cout << i << " : " << dist[i] << endl;
    }
    return 0;
}