#include <bits/stdc++.h>

using namespace std;

// 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수
void func(int a, int b, int n){
    if(n == 1) cout << a << " " << b << '\n';
    else{
        func(a, 6-a-b, n-1);
        cout << a << " " << b << '\n';
        func(6-a-b, b, n-1);
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cout << (1 << n) - 1 << '\n';
    func(1, 3, n);
    return 0;
}
