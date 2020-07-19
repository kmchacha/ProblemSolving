/*
'******************************************************************************
' 파일명    : pps29.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/19
' 문제      : 3의 개수는 (small)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, tmp, i ,cnt=0, digit;
    cin >> n;
    for(i=1;i<=n;i++){
        tmp = i;
        while(tmp>0) {
            digit = tmp % 10;
            if(digit==3) cnt++;
            tmp = tmp/10;
        }
    }
    cout << cnt << endl;
    return 0;
}