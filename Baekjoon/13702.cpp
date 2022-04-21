#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<long long> a;
int n, k; // 주전자 숫자, 사람 숫자

int Howmany(long long m){
    int cnt=0;
    for(int i=0;i<n;i++){
        long long amount=a[i];
        while(amount-m>=0){
            cnt++;
            amount = amount - m;
        }
    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    long long lt=0, rt=0, mid, ans=0;
    cin >> n >> k;
    
    for(int i=1;i<=n;i++){
        int tmp;
        cin >> tmp;
        rt += tmp;
        a.push_back(tmp);
    }

    while(lt<=rt){
        mid = (lt + rt) / 2;
        if(k <= Howmany(mid)) {
            lt = mid + 1;
            ans = mid;
        }
        else if(k > Howmany(mid)){
            rt = mid - 1;
        }
    }

    cout << ans << '\n';
    return 0;
}