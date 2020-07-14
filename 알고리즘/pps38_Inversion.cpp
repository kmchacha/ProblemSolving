/*
'******************************************************************************
' 파일명    : pps38_Inversion.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/14
' 문제      : Inversion Sequence
'
' 문제 설명 : 1부터 n까지의 수를 한 번씩만 사용하여 이루어진 수열이 ㅇㅆ을때, 1부터 n까지 각각의 수 앞에 놓여 있는
'            자신보다 큰 수들의 개수를 수열로 표현한 것을 Inversion Sequence라고 한다
'            4 8 6 2 5 1 3 7
'            1 앞에 놓인 1보다 큰 수는 4, 8, 6, 2, 5 이렇게 5개이고
'            2 앞에 놓인 2보다 큰 수는 4, 8, 6 이렇게 3개
'            3 앞에 놓인 3보다 큰 수는 4, 8, 6, 5 이렇게 4개이다
'            따라서, Inversion sequence 는 5 3 4 0 2 1 1 0 이 된다
'            Inverison Sequence가 주어졌을 때, 원래의 수열을 출력하는 프로그램을 작성하시오              
' 출력 설명 : 오름차순으로 정렬된 수열을 출력한다
' 
'예제
'    8
'    5 3 4 0 2 1 1 0
'    => 4 8 6 2 5 1 3 7
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, i, j, pos;
    cin >> n;
    vector<int> is(n+1), os(n+1);  // inversion sequence ,  original sequence
    for(i=1;i<=n;i++){
        cin >> is[i];
    }
    for(i=n;i>0;i--){
        pos = i;
        for(j=1;j<=is[i];j++){
            os[pos] = os[pos+1];
            pos++;
        }
        os[pos] = i;
    }
    for(i=1;i<=n;i++){
        cout << os[i] << " ";
    }
    return 0;
}