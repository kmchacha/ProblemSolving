/*
'******************************************************************************
' 파일명    : pps.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/21
' 문제      : 공주 구하기
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, k, i, cnt=0, bp=1;
    cin >> n >> k;
    vector<int> ch(n+1);
    while(1) {
        for(i=1;i<=n;i++) {
            if(ch[i]==1)    continue;
            else {
                cnt++;
                if(cnt==k)  {
                    ch[i]=1;
                    cnt=0;
                    bp++;
                }
            }
        }
        if(bp==n)    break;
    }
    for(i=1;i<=n;i++){
        if(ch[i]==0)    cout << i << endl;
    }
    return 0;
}