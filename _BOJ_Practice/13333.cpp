#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

using namespace std;

int a[10001], ch[10001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, ans=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    sort(a+1, a+n+1); // 3 4 5 8 10
    for(int k=1;k<=n;k++){
        int cnt1=0, cnt2=0;
        for(int i=1;i<=n;i++){
            // 한 학생이 발표한 총 n ≥ 1 편의 논문 중에서, k번 이상 인용된 논문이 k편 이상이고 
            // 나머지 n − k 편의 논문들 인용회수가 각각 k 번 이하라면, 해당 학생의 q-인덱스는 k이다.            
            if(a[i] >= k) { cnt1++; ch[i]=1;}
            if(a[i] <= k && ch[i]==0) cnt2++;
        }
        for(int i=1;i<=n;i++) ch[i]=0;
        //cout << cnt1 << " " << cnt2 << endl;
        if(cnt1 >=k && cnt2 <=k) {
            ans = k;
        }
    }
    // 4
    cout << ans << endl;
    return 0;
}