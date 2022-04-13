#include <bits/stdc++.h>

using namespace std;

int arr[100005], N, M;;

bool isExist(int num){
    int lt = 0, rt = N - 1;
    while(lt <= rt) {
        int mid = (lt + rt) / 2;
        if(arr[mid] == num) return true;
        else if(arr[mid] < num) lt = mid + 1;
        else rt = mid - 1;
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt" , stdin);
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    sort(arr, arr + N);
    cin >> M;
    for(int i=0;i<M;i++){
        int X;
        cin >> X;
        if(isExist(X)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}