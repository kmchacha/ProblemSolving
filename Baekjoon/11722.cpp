#include <bits/stdc++.h>

using namespace std;

int N, arr[1005], downdp[1005], answer;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        downdp[i] = 1;
    }
    for(int i=0;i<N;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i] < arr[j]) {
                downdp[i] = max(downdp[j] + 1, downdp[i]);
            }
        }
        answer = max(answer, downdp[i]);
    }
    cout << answer;
    return 0;
}