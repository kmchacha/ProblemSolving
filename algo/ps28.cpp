/*
'******************************************************************************
' 파일명    : pps28.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/19
' 문제      : N! 에서 0의 개수
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <cmath>    // fmin()
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, j, temp, cnt2=0, cnt5=0;
    cin >> n;
    
    for(i=2;i<=n;i++){
        temp = i;
        j=2;
        while(1){
            if(temp%j==0) {
                if(j==2) cnt2++;
                else if(j==5) cnt5++;
                temp = temp/j;
            }
            else j++;

            if(temp==1) break;
        }
    }
    cout << fmin(cnt2,cnt5) << endl; //if(cnt1<cnt2) cout << cnt1 << endl; else cout << cnt2 << endl; 

    return 0;
}