#include <bits/stdc++.h>

using namespace std;

string str;
int k;

int dp[10001][2]; // i번째 까지의 최대 길이 , k=0(값) k=1(바꿀 수 있는 횟수)
int ch[10001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input.txt", "rt", stdin);
    cin >> str >> k;
    int n = str.length();

    for(int i=1;i<=n;i++){
        if(str[i-1] == str[i-2]) ch[i] = ch[i-1] + 1;
        else ch[i] = 1;
    }
    dp[1][0] = 1; // i번째 까지의 최대 길이
    dp[1][1] = k; // 횟수
    // 지환이가얻을 수 있는 가장 긴 끈의 길이

    for(int i=2;i<=n;i++){
        if(str[i-1] == str[i-2]){
            dp[i][0] = dp[i-1][0] + 1;
            dp[i][1] = dp[i-1][1];
        }else{
            if(dp[i-1][1] >=1){
                if(ch[i] == ch[i-1]){
                    dp[i][0] = dp[i-1][0];
                    dp[i][1] = dp[i-1][1];
                }else if(ch[i] < ch[i-1]){
                    dp[i][0] = dp[i-1][0] + 1;
                    dp[i][1] = dp[i-1][1] - 1;
                    str[i-1] = str[i-2];
                }
            }else{
                dp[i][0] = dp[i-1][0];
                dp[i][1] = dp[i-1][1];
            }
        }

        //cout << dp[i][0] << " ";
    }
    cout << dp[n][0];
    return 0;
}