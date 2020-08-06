/*
'******************************************************************************
' 파일명    : pps39.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/14
' 문제      : 두 배열 합치기
'
' 문제 설명 : 오름차순으로 정렬이 도니 두 배열이 주어지면 두 배열을 오름차순으로 합쳐 출력하는 프로그램을 작성하시오
'            
' 출력 설명 : 오름차순으로 정렬된 배열을 출력한다
' 
'예제
'    3
'    1 3 5
'    5 
'    2 3 6 7 9
'    => 1 2 3 3 5 6 7 9
'******************************************************************************
*/
#include <iostream>
#include <vector>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, m, i, j, pos=0;
    cin >> n;
    vector<int> a(n);
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    
    cin >> m;
    vector<int> b(n);
    for(i=0;i<n;i++){
        cin >> b[i];
    }
    
    vector<int> c(n+m);
    i=0, j=0;
    while(i<n && j<m){
        if(a[i]>b[j]){
            c[pos++] = b[j++];
        }else {
            c[pos++] = a[i++];
        }
    }
    while(i<n){
        c[pos++] = a[i++];
    }
    while(j<m){
        c[pos++] = b[j++];
    }
    for(i=0;i<(n+m);i++){
        cout << c[i] << " ";
    }
    return 0;
}