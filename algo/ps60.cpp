/*
'******************************************************************************
' 파일명    : pps60.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/23
' 문제      : 합이 같은 부분집합(DFS)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int a[11], ch[11], n;
void dfs(int L){
    if(L > n) // L == n+1
    {
        int i, sum1=0, sum2=0;
        for(i=1;i<=n;i++){
            if(ch[i]==1){
                sum1 += a[i];
            }else {
                sum2 += a[i];
            }
        }
        if(sum1==sum2) {
            cout << "YES" << endl;
            exit(0);
        }
        return; 
    }
    else {
        ch[L]=1;
        dfs(L+1);
        ch[L]=0;
        dfs(L+1);
    }
}
int main(){
    //freopen("input.txt", "rt", stdin);
    int i;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    dfs(1);
    cout << "NO" << endl;
    return 0;
}