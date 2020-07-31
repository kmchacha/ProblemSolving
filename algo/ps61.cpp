/*
'******************************************************************************
' 파일명    : pps61.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/23
' 문제      : 특정 수 만들기(DFS)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a[11], ch[101], cnt;
void dfs(int L){
    if(L > n) {
        int sum = 0;
        for(int i=1;i<=n;i++){
            if(ch[i]==1) sum += a[i];
            else if(ch[i]==-1) sum -= a[i];
        }
        if(sum == m) cnt++;
        return;
    }
    else {
        ch[L] = 1;
        dfs(L+1);
        ch[L] = 0;
        dfs(L+1);
        ch[L] = -1;
        dfs(L+1);
    }
}
int main(){
    //freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    dfs(1);

    if(cnt==0) cout << "-1" << endl; 
    else cout << cnt << endl;

    return 0;
}