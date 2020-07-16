/*
'******************************************************************************
' 파일명    : pps15.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/16
' 문제      : 소수의 개수
'
' 문제 설명 : 자연수 N이 입력되면 1부터 N까지의 소수의 개수를 출력하는 프ㅗ그램
'            
' 출력 설명 : 소수의 개수를 출력한다 
' 
'예제
'    
'    => 
'******************************************************************************
*/
#include <iostream>
using namespace std;

int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, j,cnt=0, flag;
    cin >> n;
    for(i=2;i<=n;i++){
        flag = 1;
        for(j=2;j*j<=i;j++){
            if(i%j==0){
                flag = 0;
                break;
            }
        }
        if(flag==1) cnt++;
    }
    cout<< cnt << endl;
    return 0;
}