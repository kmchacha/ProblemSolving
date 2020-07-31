/*
'******************************************************************************
' 파일명    : pps.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/21
' 문제      : 멀티태스킹(카카오 먹방 문제 변형)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, k, i, j, cnt=0, bp=0, pos=0;
    cin >> n;
    vector<int> a(n+1);
    for(i=1;i<=n;i++){
        cin >> a[i];
    }
    cin >> k;
    while(1){
        pos = (pos % n) + 1;
        if(cnt==k && a[pos]>0) break;
        else if(cnt==k) {
            bp++;
            if(bp==n) {
                cout << "-1" << endl;
                exit(0);
            }
        }
        if(a[pos] > 0)  {
            a[pos]--;
            cnt++;
        }
    }
    cout << pos << endl;
    return 0;
}