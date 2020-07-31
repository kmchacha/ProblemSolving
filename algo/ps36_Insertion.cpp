/*
'******************************************************************************
' 파일명    : pps36.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/13
' 문제      : Insertion sort
'
' 문제 설명 : N개의 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
'            정렬하는 방법은 삽입정렬을 이용
' 출력 설명 : 정렬된 결과를 출력한다
' 
'예제
'    6
'    11 7 5 6 10 9
'    => 5 6 7 9 10 11
'******************************************************************************
*/
#include <iostream>
using namespace std;
int main(){
    freopen("input.txt", "rt", stdin);
    int n, i, j, temp, a[100];
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=1;i<n;i++){
        temp = a[i];
        for(j=i-1;j>=0;j--){
            if(a[j] > temp){
                a[j+1] = a[j];
            }else break;
        }
        a[j+1] = temp;
    }
    for(i=0;i<n;i++){
        cout << a[i] << " ";
    }
    return 0;
}