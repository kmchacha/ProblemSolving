/*
'******************************************************************************
' 파일명    : pps10.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/14
' 문제      : 자릿수의 합
'
' 문제 설명 : 자연수 N이 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합의 최대인 자연수를 출력하는 프로그램
'            
' 출력 설명 : 자릿수의 합이 최대인 자연수를 출력한다. 
' 
'예제   8
'    => 1 2 2 3 2 4 2 4
'******************************************************************************
*/
#include <iostream>
using namespace std;
int a[101];
int digit_sum(int num){
    if(num<10)    return num;
    else {
        int temp = num % 10;
        return temp + digit_sum(num/10);
    }

    // int tmp, sum=0;
    // while(x>0) {
    //  tmp=x%10;
    //  sum+=tmp;
    //  x=x/10;
    // }
    // return sum;
}
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, max_index=0;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> a[i];
    }
    for(i=1;i<n;i++){
        if(digit_sum(a[max_index]) < digit_sum(a[i])) {
            max_index = i;
        }else if(digit_sum(a[max_index]) == digit_sum(a[i])){
            max_index = (a[max_index] > a[i])? max_index: i;
        }
    }
    cout << a[max_index] << endl;
    return 0;
}