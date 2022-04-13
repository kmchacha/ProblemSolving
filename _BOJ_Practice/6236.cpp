#include <bits/stdc++.h>

using namespace std;

int N, M, arr[100005], lt, rt;
int count(int limit) {
    int ret = 1, sum=0;
    for(int i=0;i<N;i++){
        if(sum + arr[i] > limit) {
            ret++;
            sum = arr[i];
        }else sum += arr[i];
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    for(int i=0;i<N;i++) {
        cin >> arr[i];
        rt += arr[i];
        lt = max(lt, arr[i]);
    }
    while(lt <= rt) {
        int mid = (lt + rt) / 2;
        if(count(mid) <= M) {
            rt = mid - 1;
        }else lt = mid + 1;
    }
    cout << lt;
    return 0;
}