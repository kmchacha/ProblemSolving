#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// active-selection problem
// finish 시간이 단조증가하는 순서로 활동이 정렬되어 있어야 한다
// DP, Greedy로 문제를 접근 가능하다

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, cnt=0;
    cin >> n;
    vector<pair<int, int> > array;
    for(int i=1;i<=n;i++){
        int start, finish;
        cin >> start >> finish;
        array.push_back(make_pair(finish,start));
    }
    // 두번쨰 종료 시점에 따라서 정렬한다
    sort(array.begin(), array.end());
    // Greedy  --> 제일 먼저 끝나는 활동을 선택했을 때, 남은 Sub Problem에서 최대한 많은 활동을 고른다
    int temp=0;
    for(int i=0;i<n;i++){
        if(array[i].second >= temp) { // -> 끝나는 시간과 시작 시간이 같아도 된다는 조건으로 인해
            cnt++;
            temp = array[i].first;
        }
    }


    // // DP
    // vector<int> dp(n);
    // for(int i=0;i<n;i++){
    //     dp[i] = max(dp[])
    // }
    cout << cnt << '\n';
    return 0;
}