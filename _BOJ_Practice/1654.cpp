#include <bits/stdc++.h>

using namespace std;

long long N, K, arr[10005], lt=1, rt;
long long count(long long limit){
    long long ret = 0;
    for(int i=0;i<K;i++){
        ret += (arr[i] / limit);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> K >> N;
    for(int i=0;i<K;i++) {
        cin >> arr[i];
        rt = max(rt, arr[i]);
    }
    while(lt <= rt){
        long long mid = (lt + rt) / 2;
        if(count(mid) >= N) {
            lt = mid + 1;
        }else rt = mid - 1;
    }
    cout << rt;
    return 0;
}