/*
'******************************************************************************
' 파일명    : pps74.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/25
' 문제      : STL Priority Queue (우선순위 큐), Min Heap
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    freopen("input.txt", "rt", stdin);
    int a;
    priority_queue<int> pQ;
    while(1){
        cin >> a;
        if(a==-1) break;
        if(a== 0) {
            if(pQ.empty()) cout << "-1" << endl;
            else {
                cout << -pQ.top() << endl;
                pQ.pop();
            }
        }
        else pQ.push(-a);
        
    }
    return 0;
}