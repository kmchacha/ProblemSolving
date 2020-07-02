// Continuous Sum 1912
#include <iostream>
#include <limits>

int
main(int argc, const char* argv[])
{
    using namespace std;

    int n;
    cin >> n;

    int a[100000];
    for(int i = 0 ; i<n; i++) {
        cin >> a[i];
    }
    
    //dp[i] : i 번째에서 끝나는 연속 합의 최대 값

    int dp[100000];

    dp[0] = a[0];
    int max = dp[0];
    for(int i = 1 ; i < n ; i++) {
        if(a[i] < dp[i-1] + a[i]) {
            dp[i] = dp[i-1] + a[i];
        }else {
            dp[i] = a[i];
        }
        if(max < dp[i]) max = dp[i];
    }

    cout << max << endl;

    return 0;
}