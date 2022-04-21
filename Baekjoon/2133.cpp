#include <bits/stdc++.h>

using namespace std;

int dp[35], N;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4;i<=N;i++){
        if(i % 2 == 0) {
            dp[i] = 3 * dp[i - 2];

            for(int j=4;j<i;j+=2) {
                dp[i] += (dp[i - j] * 2);
            }
            dp[i] += 2;
        }
    }
    cout << dp[N];
    return 0;
}