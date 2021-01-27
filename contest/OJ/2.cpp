#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    long long T, ans=0, cnt=0, n;
    cin >> T;
    while(T--){
        cin >> n;
        while(n>0){
            if(n%2==1){
                cnt++;
                ans = max(cnt,ans);
            }else{
                cnt=0;
            }
            n = n/2;
        }
        cout << ans<<'\n';
        cnt=0;
        ans=0;
    }
    return 0;
}
