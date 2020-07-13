/*
'******************************************************************************
' 파일명    : dp1.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/14
' 문제      : 네트워크 선 자르기 (Top down)
'
' 문제 설명 : ...
'            
' 출력 설명 : ...
' 
'예제   7
'      => 21
'******************************************************************************
*/
#include <iostream>
using namespace std;
int dp[50];
int DFS(int n){
    if(dp[n] != 0)  return dp[n];

    if(n==1 || n==2) return n;
    else {
        dp[n] = DFS(n-1)+DFS(n-2);
        return dp[n];
    }
}
int main(){
    int n;
    cin >> n;
    cout << DFS(n) << endl;
    return 0;
}