/*
'******************************************************************************
' 파일명    : pps76.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/25
' 문제      : 이항 계수 (메모이제이션)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int memo[21][21];
int DFS(int n, int r){
    if(memo[n][r]>0) return memo[n][r];
    
    if(n==r || r==0) return 1;
    else {
        memo[n][r] = DFS(n-1,r) + DFS(n-1,r-1);
        return memo[n][r];
    }
}
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, r;
    cin >> n >> r;
    cout << DFS(n,r) << endl;
    return 0;
}