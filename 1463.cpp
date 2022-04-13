#include <bits/stdc++.h>

using namespace std;
const int MAX = 1000005; 

int dp[MAX];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    fill(dp, dp + MAX, INT_MAX);
    dp[1] = 0;
    for(int i=1;i<N;i++){
        dp[i + 1] = min(dp[i + 1], dp[i] + 1);
        if(i * 2 < MAX) dp[i * 2] = min(dp[i * 2], dp[i] + 1);
        if(i * 3 < MAX) dp[i * 3] = min(dp[i * 3], dp[i] + 1);
    }
    cout << dp[N];
    return 0;
}