#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, m;
vector<int > arr;
// 최대 v개를 주면서 나눠준 사람 수
int cal(int v){
    int cnt=0;
    for(int i=0;i<m;i++){
        int J_cnt = arr[i];
        while(J_cnt > 0){
            if(J_cnt >= v) J_cnt = J_cnt - v;
            else J_cnt = 0;
            cnt++;
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int input, lt=1, rt, mid, ans=2147000000;
    cin >> n >> m; // n 아이들의 수, m 색상의 수
    for(int i=1;i<=m;i++){
        cin >> input; // i번 색상 보석의 개수
        arr.push_back(input);
        if(input > rt) rt = input;
    }

    while(lt<=rt){
        mid = (lt + rt) / 2;
        //cout << mid << endl;
        int jealous = cal(mid);
        if(jealous <= n) {
            ans = mid;
            rt = mid - 1;
        }else {
            lt = mid + 1;
        }
    }

    cout << ans << '\n';
    return 0;
}