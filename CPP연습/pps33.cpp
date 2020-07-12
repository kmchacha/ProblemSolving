/*
'******************************************************************************
' 파일명    : pps33.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/13
' 문제      : 3등의 성적은?
''
' 문제 설명 : N명의 수학성적이 주어지면 그 중 3등을 한 수학성적을 출력하는 프로그램을 작성하세요.
'             만약 한색의 점수가 100점이 3명, 99점이 2명, 98점이 명 97점이 3명 이런식을 점수가 분포되면
'             1등은 3명이며, 2등은 2명, 3등은 5명이 되어 98점이 3등을 한 점수가 됩니다
' 
' 출력 설명 : 3등을 한 점수를 출력
' 
'예제
'    7
'    80 96 75 82 96 92 100
'    => 92
'******************************************************************************
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int a[101], idx, n, i, j, temp, cnt=0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=0;i<n-1;i++){
        idx = i;
        // find max
        for(j=i+1;j<n;j++){
            if(a[idx] < a[j]) idx = j;
        }
        // swap
        temp = a[i];
        a[i] = a[idx];
        a[idx] = temp;
    }

    for(i=1;i<n;i++){
        if(a[i-1] != a[i]) cnt++;
        if(cnt == 2) {
            cout << a[i] << endl;
            break;
        }   
    }
    //cout << a[cnt] << endl;
    return 0;
}