#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, l, ans1=0, ans2=0, tmp1=0 ,tmp2=0;
    cin >> l;
    cin >> n;
    vector<int> arr(l+1);
    for(int idx=1;idx<=n;idx++){
        int lt, rt, cnt=0;
        cin >> lt >> rt;
        for(int i=lt;i<=rt;i++){
            if(arr[i]==0){
                arr[i]=idx;
                cnt++;
            }
        }
        if(tmp1 < rt-lt+1) {
            ans1 = idx;
            tmp1 = rt-lt+1;
        }
        if(tmp2 < cnt) {
            tmp2 = cnt;
            ans2 = idx;
        }
    }
    cout << ans1 << '\n' << ans2;
    return 0;
}