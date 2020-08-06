/*
'******************************************************************************
' 파일명    : pps30.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/19
' 문제      : 3의 개수는 (large)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //freopen("input.txt", "rt", stdin);
    int n, lt, cur, rt, k=1, i ,j, res=0;
    cin >> n;
    lt = 1;
    while(lt != 0) {
        lt = n / (10 * k);
        cur = (n / k) % 10;
        rt = n % k;
        //cout << "lt : " << lt << endl;
        //cout << "cur : " << cur << endl;
        //cout << "rt : " << rt << endl;
        if(cur > 3) res += (lt + 1) *k;
        else if(cur < 3) res += lt * k;
        else res += ((lt * k) + rt + 1);
        k = k*10;
    }
    cout << res << endl;
    return 0;
}