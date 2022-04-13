#include <bits/stdc++.h>

using namespace std;

unsigned long long A, B, C;
unsigned long long recursive(int b){
    if(b==0) return 1;
    unsigned long long temp = recursive(b / 2);
    temp = temp * temp % C;
    if(b%2==0) return temp;
    else return A * temp % C;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> A >> B >> C;
    unsigned long long answer = A;
    answer = recursive(B);
    cout << answer;
    return 0;
}