/*
'******************************************************************************
' 파일명    : dp14.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/31
' 문제      : 위상 정렬(Topological Sort) -> 일의 선후 관계를 유지하면서 전체 일의 순서를 짜는 알고리즘
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, m, a, b, score;
    cin >> n >> m;
    vector<vector<int> > graph(n+1, vector<int>(n+1,0));
    vector<int> degree(n+1);
    queue<int> Q;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        graph[a][b]=1;
        degree[b]++;
    }
    for(int i=1;i<=n;i++){
        if(degree[i]==0) Q.push(i);
    }
    while(!Q.empty()){
        int now=Q.front();
        Q.pop();
        cout << now << " ";
        for(int i=1;i<=n;i++){
            if(graph[now][i]==1) {
                degree[i]--;
                if(degree[i]==0) Q.push(i);
            }
        }
    }
    return 0;
}