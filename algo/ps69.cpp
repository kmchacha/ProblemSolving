/*
'******************************************************************************
' 파일명    : pps69.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/25
' 문제      : 이진 트리 넓이 우선 탐색(BFS) - level order (queue 이용)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int Q[100], front=-1, back=-1, ch[10];
vector<int> map[10];
int main(){
    freopen("input.txt", "rt", stdin);
    int i, a, b, x;
    for(i=1;i<=6;i++){
        cin >> a >> b;
        map[a].push_back(b);
        map[b].push_back(a);
    }
    Q[++back]=1; // Q에 root 노드를 넣어준다
    ch[1]=1;     // root노드 check
    while(front<back){
        x = Q[++front];
        cout << x << " ";
        for(i=0;i<map[x].size();i++){
            if(ch[map[x][i]]==0){
                ch[map[x][i]]=1;
                Q[++back] = map[x][i];
            }
        }
    }

    return 0;
}