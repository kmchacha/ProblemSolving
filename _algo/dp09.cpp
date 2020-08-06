/*
'******************************************************************************
' 파일명    : dp9.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/31
' 문제      : 가방 문제 (Knapsack algorithm)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[501];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        int w, v;
        cin >> w >> v;
        for(int j=w;j<=m;j++){
            if(dp[j] < dp[j-w] + v) dp[j] = dp[j-w] + v;
        }
    }

    cout << dp[m] << '\n';
    return 0;
}