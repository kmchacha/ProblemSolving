#include <bits/stdc++.h>

using namespace std;

int N, arr[1005], updp[1005], sum[1005], answer;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        updp[i] = 1;
        sum[i] = arr[i];
    }
    for(int i=0;i<N;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i] > arr[j]) {
                updp[i] = max(updp[i], updp[j] + 1);
                sum[i] = max(sum[i], sum[j] + arr[i]);
            }
        }
        answer = max(answer, sum[i]);
    }
    cout << answer;
    return 0;
}