/*
'******************************************************************************
' 파일명    : dp5.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/30
' 문제      : 최대 선 연결하기
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    
    int n, i, j, res=0;
    cin >> n;
    vector<int> a(n+1), dp(n+1);
    for(i=1;i<=n;i++){
        cin >> a[i];
    }

    dp[1]=1;
    for(i=2;i<=n;i++){
        int max=0;
        for(j=i-1;j>=1;j--){
            if(a[i]>a[j] && dp[j]>max){
                max = dp[j];
            }
        }
        dp[i] = max + 1;
        
        if(res<dp[i]) res=dp[i];
    }
    cout << res << endl;

    return 0;
}