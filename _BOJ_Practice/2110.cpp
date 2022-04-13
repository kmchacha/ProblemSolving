#include <bits/stdc++.h>

using namespace std;

int N, C, arr[200005];

int count(int L){
    int ret = 0, prev = 0;
    for(int i=0;i<N;i++){
        if(i==0 || arr[i] >= prev + L){
            prev = arr[i];
            ret++;
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> C;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr, arr + N);
    int lt = 1, rt = arr[N-1];
    while(lt <= rt){
        int mid = (lt + rt) / 2;
        if(count(mid) >= C) {
            lt = mid + 1;
        }else rt = mid - 1;
    }
    cout << rt;
    return 0;
}