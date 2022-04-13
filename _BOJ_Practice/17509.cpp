#include <bits/stdc++.h>

using namespace std;

pair<int, int> arr[15];
int answer;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    for(int i=0;i<11;i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + 11);
    int pre = 0;
    for(int i=0;i<11;i++){
        answer += pre + arr[i].first;
        pre += arr[i].first;
    }
    for(int i=0;i<11;i++){
        answer += (20 * arr[i].second);
    }
    cout << answer;
    return 0;
}