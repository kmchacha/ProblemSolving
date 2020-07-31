/*
'******************************************************************************
' 파일명    : pps85.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/28
' 문제      : 수식 만들기
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, a[10] ,cnt[5], maxx=-2147000000, minn=2147000000;
void DFS(int L, int res){
    if(L==n){
        if(res>maxx) maxx=res;
        if(res<minn) minn=res;
    }else {
        if(cnt[0]>0){
            cnt[0]--;
            DFS(L+1,res+a[L]);
            cnt[0]++;
        }
        if(cnt[1]>0){
            cnt[1]--;
            DFS(L+1,res-a[L]);
            cnt[1]++;
        }
        if(cnt[2]>0){
            cnt[2]--;
            DFS(L+1,res*a[L]);
            cnt[2]++;
        }
        if(cnt[3]>0){
            cnt[3]--;
            DFS(L+1,res/a[L]);
            cnt[3]++;
        }
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<4;i++){
        cin >> cnt[i];
    }
    DFS(1, a[0]);
    cout << maxx << endl << minn << endl;
    return 0;
}