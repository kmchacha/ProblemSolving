/*
'******************************************************************************
' 파일명    : pps67.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/24
' 문제      : 최소 비용(DFS, 인접행렬)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[21][21], ch[21], sum=0, n, ans=2147000000;
void DFS(int v){
    int i;
    if(v==n){
        ans = min(ans, sum);
    }else {
        for(i=1;i<=n;i++){
            if(map[v][i]>0 && ch[i]==0){
                ch[i]=1;
                sum += map[v][i];
                DFS(i);
                ch[i]=0;
                sum -= map[v][i];
            }
        }
    }
}

int main(){
    freopen("input.txt", "rt", stdin);
    int m, i, j, a, b, w;
    cin >> n >> m;
    for(i=1;i<=m;i++){
        cin >> a >> b >> w;
        map[a][b] = w;
    }
    ch[1]=1;
    DFS(1);
    cout << ans << endl;
    return 0;
}