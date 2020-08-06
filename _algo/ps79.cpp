/*
'******************************************************************************
' 파일명    : pps79.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/26
' 문제      : 원더랜드 Prim MST 알고리즘, priority_queue 활용
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int ch[101], n;
vector<int> map[30];
struct Edge{
    int e;
    int val;
    Edge(int a, int b){
        e=a;
        val=b;
    }
    bool operator < (const Edge &b) const{
        return val>b.val; // 최소 힙 val<b.val(최대 힙)
    }
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    vector<pair<int, int> > map[30];
    priority_queue<Edge> pQ;
    int i, n, m, a, b, c, res=0;
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));
    }
    pQ.push(Edge(1,0));
    while(!pQ.empty()){
        Edge tmp = pQ.top();
        pQ.pop();
        int v=tmp.e;
        int cost=tmp.val;
        if(ch[v]==0){
            res+=cost;
            ch[v]=1;
            for(i=0;i<map[v].size();i++){
                pQ.push(Edge(map[v][i].first, map[v][i].second));
            }
        }
    }
    cout << res << endl;
    return 0;
}