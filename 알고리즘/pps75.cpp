/*
'******************************************************************************
' 파일명    : pps75.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/25
' 문제      : 최대 수입 스케줄(priority_queue 응용 문제)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int ch[10001];
int main(){
    //freopen("input.txt", "rt", stdin);
    int n , m, d, i, max_day=0, res=0;
    priority_queue<pair<int, int >> pQ;
    priority_queue<int> pQ2;
    cin >> n;
    for(i=1;i<=n;i++){
        cin >> m >> d;
        pQ.push(make_pair(d, m));
        if(max_day<d) max_day=d;
    }
    // cout << max_day << endl;
    // for(i=1;i<=n;i++){
    //     cout << pQ.top().first << " " << pQ.top().second << endl;
    //     pQ.pop();
    // }
    for(i=max_day;i>=1;i--){
        while(1){
            if(i>pQ.top().first || pQ.empty()) break;
            pQ2.push(pQ.top().second);
            pQ.pop();
        }
        if(!pQ2.empty()){
            res+=pQ2.top();
            //cout << pQ2.top() << endl;
            pQ2.pop();
        }
    }
    cout << res << endl;
    return 0;
}