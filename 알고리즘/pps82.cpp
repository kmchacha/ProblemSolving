/*
'******************************************************************************
' 파일명    : pps.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/26
' 문제      : 순열 구하기(DFS)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int ch[16], a[16] , path[16], n, m, cnt;
void DFS(int L){
    if(L==m){
        for(int i=0;i<L;i++){
            cout << path[i] << " ";
        }
        cout << endl;
        cnt++;
    }else {
        for(int i=1;i<=n;i++){
            if(ch[i]==0){
                path[L+1]=a[i];
                ch[i]=1;
                DFS(L+1);
                ch[i]=0;
            }
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    DFS(0);
    cout << cnt << endl;
    return 0;
}
// output
// 1 3 6
// 1 3 7
// 1 6 3
// 1 6 7
// 1 7 3
// 1 7 6
// 3 1 6
// 3 1 7
// 3 6 1
// 3 6 7
// 3 7 1
// 3 7 6
// 6 1 3
// 6 1 7
// 6 3 1
// 6 3 7
// 6 7 1
// 6 7 3
// 7 1 3
// 7 1 6
// 7 3 1
// 7 3 6
// 7 6 1
// 7 6 3
// 24