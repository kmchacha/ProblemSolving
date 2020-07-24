/*
'******************************************************************************
' 파일명    : pps63.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/24
' 문제      : 인접 행렬(가중치 방향 그래프)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[21][21];
int main(){
    freopen("input.txt", "rt", stdin);
    int V, E, i, j;
    cin >> V >> E;
    for(i=1;i<=E;i++){
        int x, y, w;
        cin >> x >> y >> w;
        map[x][y] = w;
    }
    for(i=1;i<=V;i++){
        for(j=1;j<=V;j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}