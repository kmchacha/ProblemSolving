/*
'******************************************************************************
' 파일명    : pps59.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/23
' 문제      : 부분 집합 (DFS)
'******************************************************************************
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int ch[11] ,n;
void dfs(int L){
    int i;
    if(L > n) // if(L==n+1) 
    {
        for(i=1;i<=n;i++){
            if(ch[i]==1) cout << i << " ";
        }
        cout << endl;   
        return;
    }
    else {
        ch[L] = 1;
        dfs(L+1);
        ch[L] = 0;
        dfs(L+1);
    }
}
int main(){
    //freopen("input.txt", "rt", stdin);
    cin >> n;
    dfs(1);
    return 0;
}