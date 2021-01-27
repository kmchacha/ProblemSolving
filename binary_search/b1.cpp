// Youtube 나동빈 binary search 문제 1번

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

long n, m; // n 떡의 개수, m 요청한 떡의 길이
vector<long> a(1000001);

long check(int size){
    int sum = 0;
    for(int i=1;i<=n;i++){
        if(a[i]>=size) sum += (a[i]-size);
    }
    return sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    
    cin >> n >> m;
    int max=0;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        if(max < a[i]) max = a[i];
    }

    int lt=0, rt=max, mid, ans;
    while(lt<=rt){
        mid = (lt + rt) / 2;
        cout << mid << '\n';
        long tmp = check(mid);
        if(tmp>=m){
            ans = mid;
            lt = mid + 1;
        }else {
            rt = mid - 1;
        }
    }

    // 절단기에 설정할 수 있는 높이의 최대값
    cout << ans;
    return 0;
}

// Tip
// count by range
// int countByRange(vector<int>& v, int leftValue, int rightValue){
//     vector<int>::iterator rightIndex = upper_bound(v.begin(),v.end(),rightValue);
//     vector<int>::iterator leftIndex = lower_bound(v.begin(), v.end(), leftValue);
//     return rightValue - leftValue;
// }