#include <bits/stdc++.h>

using namespace std;

int arr[10], sum;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("input.txt", "rt", stdin);
    for(int i=0;i<9;i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i=0;i<9;i++){
        int flag = 0;
        for(int j=i+1;j<9;j++){
            if(i!=j && sum - arr[i] - arr[j] == 100) {
                arr[i] = arr[j] = 101;
                cout << i << " " << j << endl;
                flag = 1;
                break;
            }
        }
        // if(flag == 1) break;
    }
    sort(arr, arr + 9);
    for(int i=0;i<7;i++) cout << arr[i] << '\n';
    return 0;
}