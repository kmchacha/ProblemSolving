#include <bits/stdc++.h>

using namespace std;

int arr[105], N, answer1=INT_MIN, answer2=INT_MAX;

void recur(int L, int res, int add, int sub, int mul, int div){
    // cout << L << " " << N << endl;
    if(L == N) {
        answer1 = max(answer1, res);
        answer2 = min(answer2, res);
    }else {
        if(add > 0) recur(L+1, res + arr[L], add-1, sub, mul, div);
        if(sub > 0) recur(L+1, res - arr[L], add, sub-1, mul, div);
        if(mul > 0) recur(L+1, res * arr[L], add, sub, mul-1, div);
        if(div > 0) {
            if(res >= 0) recur(L+1, res / arr[L], add, sub, mul, div-1);
            else recur(L+1, -1 * ((-1 * res) / arr[L]), add, sub, mul, div-1);
        }
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];
    int add, sub, mul, div;
    cin >> add >> sub >> mul >> div;
    recur(1, arr[0], add, sub, mul, div);
    cout << answer1 << '\n' << answer2;
    return 0;
}