#include <bits/stdc++.h>

using namespace std;

int arr[500005], N, M;;
bool isexist(int k) {
    int lt = 0, rt = N - 1;
    while(lt <= rt){
        int mid = (lt + rt) / 2;
        if(arr[mid] == k) return true;
        else if(arr[mid] > k) rt = mid - 1;
        else lt = mid + 1;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr, arr + N);
    cin >> M;
    for(int i=0;i<M;i++) {
        int k;
        cin >> k;
        if(isexist(k)) cout << 1 << " ";
        else cout << 0 << " ";
    }
    return 0;
}