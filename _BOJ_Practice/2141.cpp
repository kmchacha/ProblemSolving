#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// 수직선과 같은 일직선상에 N개의 마을이 위치해 있다. 
// i번째 마을은 X[i]에 위치해 있으며, A[i]명의 사람이 살고 있다.
vector<pair<long long, long long> > arr;
int n;
long long cal(int v){
    long long cnt=0;
    for(int i=0;i<n;i++){
        cnt += (abs(arr[i].first - v) * arr[i].second);
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int ans, loc_max=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        long long loc, cnt;
        cin >> loc >> cnt;
        if(loc_max < loc) loc_max = loc;
        arr.push_back(make_pair(loc, cnt));
    }
    sort(arr.begin(), arr.end());
    int lt=1, rt=loc_max;
    long long dist_min=9223372000000000000;
    while(lt<=rt){
        int mid = (lt + rt) / 2;
        long long dist = cal(mid);
        if(dist <= dist_min) {
            ans = mid;
            dist_min = dist;
            rt = mid - 1;
        }else {
            lt = mid + 1;
        }
    }
    cout << ans << '\n';
    return 0;
}