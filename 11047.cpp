#include <bits/stdc++.h>

using namespace std;

int arr[15], answer;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, K;
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> arr[i];
    for(int i=N-1;i>=0;i--){
        if(K / arr[i] != 0) {
            answer+= (K / arr[i]);
            K -= (K / arr[i]) * arr[i];
        }
    }
    cout << answer;
    return 0;
}