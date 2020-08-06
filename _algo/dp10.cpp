/*
'******************************************************************************
' 파일명    : dp10.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/31
' 문제      : 동전 교환
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m;
    cin >> n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    cin >> m;
    vector<int> dp(m+1, 2147000000);
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=a[i];j<=m;j++){
            dp[j] = min(dp[j-a[i]] + 1, dp[j]);    
        }
    }
    
    cout << dp[m] << '\n';
    return 0;
}