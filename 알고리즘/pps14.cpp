/*
'******************************************************************************
' 파일명    : .cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/16
' 문제      : 뒤집은 소수
'
' 문제 설명 : N개의 자연수가 입력되면 각 자연수를 뒤집은 후 그 뒤집은 수가 소수이면 그 수를 출력하는 프로그램
'            
' 출력 설명 : 소수를 출력한다. 출력순서는 입력된 순서대로 출력한다
' 
'예제   5
'      32 55 62 3700 250
'    => 23 73
'******************************************************************************
*/
#include <iostream>
using namespace std;
int reverse(int x){
    int res = 0, tmp;
    while(x>0){
        tmp=x%10;
        res = res*10 + tmp;
        x=x/10;
    }
    return res;
}
bool isPrime(int x){
    if(x==1)    return false;

    int i;
    bool flag = true;
    for(i=2;i<x;i++){
        if(x%i==0)  {
            flag = false;
            break;
        }
    }
    return flag;
}
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i , num, tmp;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> num;
        tmp = reverse(num);
        if(isPrime(tmp))    cout << tmp << " ";
    }
    cout << endl;
    return 0;
}