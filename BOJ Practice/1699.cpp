// 제곱수의 합 1699
#include <iostream>

int
main(int argc, const char* argv[])
{
    using namespace std;

    int n;
    cin >> n;

    int dp[100001];
    for(int i = 1; i <= n; i++) {
        dp[i] = i;
        for(int j=1 ; j*j <= i; j++){
            if(dp[i] > dp[i-j*j]+1) {
                dp[i] = dp[i-j*j]+1;
            }
        }
    }
    

    cout << dp[n] << endl;
    return 0;
}