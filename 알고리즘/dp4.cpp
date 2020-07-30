/*
'******************************************************************************
' 파일명    : dp4.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/29
' 문제      : 최대 부분 증가수열
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int dp[1001];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    
    int n, i, j, a[1001], res=0;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }

    dp[1]=1;
    for(i=2;i<=n;i++){
        int max=0;
        for(j=i-1;j>=1;j--){
            if(a[i]>a[j] && dp[j]>max) {
                max = dp[j];
            }
        }
        dp[i] = max + 1;

        if(dp[i]>res) res=dp[i];
    }
    
    cout << res << endl;
    return 0;
}