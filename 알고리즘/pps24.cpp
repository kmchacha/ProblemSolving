/*
'******************************************************************************
' 파일명    : pps24.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/18
' 문제      : Jolly Jumpers
'******************************************************************************
*/
#include <iostream>
#include <algorithm> // abs();
using namespace std;
bool ch[100];
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, now, pre, s=0;
    cin >> n;
    cin >> pre;
    for(i=1;i<n;i++){
        cin >> now;
        if(now > pre) {
            ch[now-pre] = true; // pos = abs(pre-now);
        }                       // if(pos>0 && pos<n && ch[pos]==0) ch[pos] =1
        else {                  // else cout << "NO" << endl; return 0;
            ch[pre-now] = true;
        }
        pre = now;
    }
    for(i=1;i<n;i++){
        if(ch[i]==false)  s=1;
    }
    if(s==0)  cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}