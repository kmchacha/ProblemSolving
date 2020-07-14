/*
'******************************************************************************
' 파일명    : pps32.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/13
' 문제      : Selection Sort
''
' 문제 설명 : N개의 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오
'             정렬하는 방법은 selection sort로 정렬한다
'
' 출력 설명 : 오름차순으로 정렬된 수열을 출력
' 
' 예제
'    6
'    13 5 11 7 23 15
'    => 5 7 11 13 15 23
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    freopen("input.txt", "rt", stdin);
    int a[100], idx, n, i, j, temp;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=0;i<n-1;i++){
        idx = i;
        // find min
        for(j=i+1;j<n;j++){
            if(a[idx] > a[j]) idx = j;
        }
        // swap
        temp = a[i];
        a[i] = a[idx];
        a[idx] = temp;
    }
    for(i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}