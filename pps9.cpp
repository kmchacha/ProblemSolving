/*
'******************************************************************************
' 파일명    : pps9.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/14
' 문제      : 모두의 약수
'
' 문제 설명 : 자연수 N이 입력되면 1부터 N까지의 각 숫자들의 약수의 개수를 출력하는 프로그램
'            
' 출력 설명 : 1부터 N까지 약수의 개수를 순서대로 출력한다
' 
'예제   8
'    => 1 2 2 3 2 4 2 4
'******************************************************************************
*/
#include <iostream>
using namespace std;
int cnt[50001];
int main(){
    //freopen("input.txt", "rt", stdin);
    int i, j, n;
    cin >> n;
    for(i=1;i<=n;i++){
        for(j=i;j<=n;j=j+i) {
            cnt[j]++;
        }
        cout << cnt[i] << " ";
    }
    cout << endl;
    return 0;
}