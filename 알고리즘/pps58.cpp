/*
'******************************************************************************
' 파일명    : pps58.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/22
' 문제      : 이진 트리 깊이우선탐색(DFS)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// dfs(1)->dfs(2)->dfs(4)->dfs(8),dfs(9)->dfs(5)->dfs(10),dfs(11)
// ->dfs(3)->dfs(6)->dfs(12),dfs(13)->dfs(7)->dfs(14),dfs(15)
void dfs(int v){
    if(v>7) return;
    else {
        cout << v << " "; // WO
        dfs(2*v);
        dfs(2*v+1);       
    }
}
int main(){
    freopen("input.txt", "rt", stdin);
    dfs(1);

    return 0;
}