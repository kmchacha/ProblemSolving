/*
'******************************************************************************
' 파일명    : dp3.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/29
' 문제      : 계단 오르기(메모이제이션)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[50];
int DFS(int n){
    if(dp[n] > 0) return dp[n];

    if(n==1 || n==0){
        return 1;
    }else 
    {
        dp[n] = DFS(n-1) + DFS(n-2);
        return dp[n];
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    dp[0]=1;
    dp[1]=1;
    cin >> n;
    cout << DFS(n) << endl;
    return 0;
}