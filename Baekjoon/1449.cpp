#include <bits/stdc++.h>

using namespace std;

int arr[1005], answer = 1, rt;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, L;
    cin >> N >> L;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr, arr + N);
    rt = arr[0] + L - 1;
    for(int i=1;i<N;i++){
        if(rt >= arr[i]) continue;
        else {
            answer++;
            rt = arr[i] + L - 1;
        }
    }
    cout << answer;
    return 0;
}