#include <bits/stdc++.h>

using namespace std;

vector<vector<long long> > matmul(vector<vector<long long> > &a, vector<vector<long long> > &b){
    vector<vector<long long> > temp(2, vector<long long>(2));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                temp[i][j] += a[i][k] * b[k][j];
            }
            temp[i][j] %= 1000000007;
        }
    }
    return temp;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("input.txt", "rt", stdin);
    long long N;
    vector<vector<long long> > ans = {{{0, 1}, {1, 0}}};
    vector<vector<long long> > a = {{1, 1}, {1, 0}};

    cin >> N;
    while(N > 0) {
        if(N & 1) ans = matmul(a, ans);
        a = matmul(a, a);
        N /= 2;
    }
    cout << ans[0][0];
    return 0;
}