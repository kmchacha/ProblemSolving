/*
'******************************************************************************
' 파일명    : pps72.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/25
' 문제      : 공주 구하기(큐 자료구조로 해결)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int ch[1001];
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, k, i, x, cnt=0;
    queue<int> Q;
    cin >> n >> k;

    for(i=1;i<=n;i++){
        Q.push(i);
    }
    while(!Q.empty()){
        if(Q.size()==1) break;
        x=Q.front();
        Q.pop();
        cnt++;
        if(ch[x]==0 && cnt==k){
            ch[x]=1;
            cnt=0;
            continue;
        }
        Q.push(x);
    }
    for(i=1;i<=n;i++){
        if(ch[i]==0) cout << i << endl;
    }
    return 0;
}