#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 아케인스톤에 모인 경험치의 합을 최대화, 정렬, 그리디 알고리즘

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, k;
    long long sum=0, ans=0;
    cin >> n >> k;
    vector<int> expr(n+1);
    for(int i=1;i<=n;i++){
        cin >> expr[i];
    }
    sort(expr.begin()+1, expr.end());
    for(int i=2;i<=k+1;i++){
        sum += expr[i];
    }
    for(int i=1;i<n;i++){
        ans += sum;
        //cout << ans << " " << sum << endl;
        if(i+k+1<=n) sum += (expr[i+k+1]-expr[i+1]);
        else sum += (-expr[i+1]);
    }
    cout << ans << '\n';
    return 0;
}