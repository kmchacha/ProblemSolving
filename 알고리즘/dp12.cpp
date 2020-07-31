/*
'******************************************************************************
' 파일명    : dp12.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/31
' 문제      : 플로이드 와샬(Floyed Warshall) 알고리즘 => 모든 정점에서 모든 정점으로 가는 알고리즘
' dis[i][j] =  min(dis[i][j],  dis[i][k] + dis[k][j]); 기존의 비용 vs i->k->j로 가는 비용
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > dis(n+1, vector<int>(n+1, 5000));
    for(int i=1;i<=n;i++) dis[i][i]=0; // 대각선 초기화
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b]=c;
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(dis[i][j]==5000) cout << "M ";
            else cout << dis[i][j] <<" ";
        }
        cout << '\n';
    }
    return 0;
}