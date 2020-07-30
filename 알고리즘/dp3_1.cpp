/*
'******************************************************************************
' 파일명    : dp3_1.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/29
' 문제      : 돌다리 건너기(Bottom up)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[50];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n+1;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n+1] << endl;
    return 0;
}