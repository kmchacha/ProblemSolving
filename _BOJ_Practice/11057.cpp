#include <bits/stdc++.h>

using namespace std;

int N, uphill[1005][10], answer;
// 길이가 n이고 첫 자릿수가 digit(0~9)인 오르막수

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<=9;i++) uphill[1][i] = 1;
    for(int i=2;i<=N;i++){
        for(int j=0;j<10;j++){
            for(int k=j;k<10;k++){
                uphill[i][j] = (uphill[i][j] + uphill[i-1][k]) % 10007;
            }
        }

    }
    for(int i=0;i<=9;i++) answer = (answer + uphill[N][i]) % 10007;
    cout << answer;

    return 0;   
}