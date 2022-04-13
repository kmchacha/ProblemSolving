#include <bits/stdc++.h>

using namespace std;

int N, arr1[32], idx=31, arr2[32], ans;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    while(N > 0) {
        arr1[idx] = N % 2;
        N = N / 2;
        idx--;
    }
    for(int i=0;i<32;i++){
        arr2[i] = (arr1[i]==1)? 0 : 1;
    }
    if(arr2[31] == 0) arr2[31] = 1;
    else {
        for(int i=31;i>=0;i--){
            if(arr2[i] == 1) {
                arr2[i] = 0;
            }
            else {
                arr2[i] = 1;
                break;
            } 
        }
    }
    for(int i=0;i<32;i++){
        if(arr1[i] != arr2[i]) ans++;
    }
    cout << ans;
    return 0;
}