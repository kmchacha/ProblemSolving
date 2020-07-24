/*
'******************************************************************************
' 파일명    : pps.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/24
' 문제      : 최소 비용(DFS, 가중치 방향 그래프 "인접리스트")
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ch[30], n, ans=2147000000;
vector<pair<int, int> > map[30];
void DFS(int v, int sum){
    if(v==n){
        ans = (ans > sum)? sum : ans;
    }else {
        for(int i=0;i<map[v].size();i++){
            if(ch[map[v][i].first]==0){
                ch[map[v][i].first]=1;
                DFS(map[v][i].first, sum+map[v][i].second);
                ch[map[v][i].first]=0;
            }
        }
    }
}
int main(){
    freopen("input.txt", "rt", stdin);
    int m, i, a, b, c;
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> a >> b >> c;
        map[a].push_back(make_pair(b, c));
    }
    ch[1]=1;
    DFS(1, 0);
    cout << ans << endl;
    return 0;
}