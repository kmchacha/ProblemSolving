/*
'******************************************************************************
' 파일명    : pps70.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/25
' 문제      : 그래프 최단거리(BFS, library <queue> 이용)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <queue> // #
#include <algorithm>
using namespace std;
int ch[30], dist[30];
vector<int> map[21];
queue<int> Q;
int main(){
    freopen("input.txt", "rt", stdin);
    int n, m, i, a ,b, x;
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> a >> b;
        map[a].push_back(b);
    }
    Q.push(1);
    ch[1] = 1;
    while(!Q.empty()){
        x = Q.front();
        Q.pop();
        for(i=0;i<map[x].size();i++){
            if(ch[map[x][i]]==0){
                ch[map[x][i]]=1;
                Q.push(map[x][i]);
                dist[map[x][i]] = dist[x]+1;;
            }
        }
    }

    for(i=2;i<=n;i++){
        cout << i << " : " << dist[i] << endl;
    }
    return 0;
}