/*
'******************************************************************************
' 파일명    : pps40.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/14
' 문제      : 교집합(투 포인트 알고리즘)
'
' 문제 설명 : 두 집합 A, B가 주어지면 두 집합의 교집합을 출력하는 프로그램을 작성하시오
'            
' 출력 설명 : 두 집합의 교집합을 오름차순 정렬하여 출력한다
' 
'예제   5
'       2 7 10 5 3
'       5
'       3 10 5 17 12
'    => 3 5 10
'******************************************************************************
*/
#include <iostream>
#include <vector>       // sort 
#include <algorithm>
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
    vector<int> b(m), c(n+m);
    for(i=0;i<m;i++){
        cin >> b[i];
    }
    sort(a.begin(), a.end(), less<int>());
    sort(b.begin(), b.end(), less<int>());
    i=0; j=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            c[pos++] = a[i++];
            j++;
        }else if(a[i]<b[j]){
            i++;
        }else {
            j++;
        }
    }
    for(i=0;i<pos;i++){
        cout << c[i] << " ";
    }
    return 0;
}