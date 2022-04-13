#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, answer = INT_MAX;
    cin >> N;
    for(int i=1;i<=N;i++){
        int sum = i;
        int temp = i;
        while(temp > 0) {
            sum += (temp % 10);
            temp = temp / 10;
        }
        if(sum == N) {
            answer = i;
            break;
        }
    }
    if(answer == INT_MAX) cout << 0;
    else cout << answer;
    return 0;
}