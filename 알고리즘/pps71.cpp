/*
'******************************************************************************
' 파일명    : pps71.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/25
' 문제      : 송아지 찾기(BFS, 상태 트리 탐색)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int ch[10001], d[3]={1,-1,5};
int main(){
    freopen("input.txt", "rt", stdin);
    int i, x, s, e;
    queue<int> Q;
    cin >> s >> e;
    ch[s]=1;
    Q.push(s);
    while(!Q.empty()){
        x=Q.front();
        Q.pop();

        for(i=0;i<3;i++){
            int pos=x+d[i];
            if(pos<=0 || pos>10000) continue;
            if(pos==e) {
                cout << ch[x]; 
                exit(0);
            }

            if(ch[pos]==0) {
                ch[pos]=ch[x]+1;
                Q.push(pos);
            }
        }
    }
    return 0;
}