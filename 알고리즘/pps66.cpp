/*
'******************************************************************************
' 파일명    : pps66.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/24
' 문제      : 경로 탐색(DFS, 인접리스트 방법)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ch[30], cnt=0, n;
vector<int> map[30];
void DFS(int v){
    int i;
    if(v == n) {
        cnt++;
    }else {
        for(i=0;i<map[v].size();i++){
            if(ch[map[v][i]]==0){
                ch[map[v][i]]=1;
                DFS(map[v][i]);
                ch[map[v][i]]=0;
            }
        }
    }
}
int main(){
    freopen("input.txt", "rt", stdin);
    int m, i, a, b;
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> a >> b;
        map[a].push_back(b);
    }
    ch[1]= 1;
    DFS(1);
    cout << cnt << endl;
    return 0;
}