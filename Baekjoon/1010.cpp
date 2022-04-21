#include <bits/stdc++.h>

using namespace std;

int T, n_left_cites, n_right_cites, dp[35][35];

int combination(int n, int m){
    if(dp[n][m] != 0) return dp[n][m];

    if(n == m) return dp[n][m] = 1;
    else if(m==1) return dp[n][m] = n;
    else return dp[n][m] = combination(n-1, m-1) + combination(n-1, m);
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> T;
    while(T--){
        cin >> n_left_cites >> n_right_cites;
        cout << combination(n_right_cites, n_left_cites) << '\n';
    }
    return 0;
}