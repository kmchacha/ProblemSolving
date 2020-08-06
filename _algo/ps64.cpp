/*
'******************************************************************************
' 파일명    : pps64.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/24
' 문제      : 경로 탐색(DFS)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[21][21], ch[21], V, E, cnt=0;
void DFS(int L){
    if(L==V){
        cnt++;
    }else {
        for(int i=1;i<=V;i++){
            if(map[L][i]==1 && ch[i]==0){
                ch[i]=1;
                DFS(i);
                ch[i]=0;
            }
        }
    }
}
int main(){
    freopen("input.txt", "rt", stdin);
    cin >> V >> E;
    for(int i=1;i<=E;i++){
        int a, b;
        cin >> a >> b;
        map[a][b]=1;
    }
    ch[1]=1;
    DFS(1);
    cout << cnt << endl;
    return 0;
}