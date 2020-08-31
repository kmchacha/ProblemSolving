#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n+1,2147000000);
    a[2]=1;
    a[4]=2;
    a[5]=1;
    for(int i=6;i<=n;i++){
        a[i] = min(a[i-2]+1, a[i-5]+1);
    }
    if(a[n]!=2147000000) cout << a[n] << '\n';
    else cout << "-1" << '\n';
    return 0;
}

// 2원과 5원은 서로 배수가 아님으로 그리디알고리즘으로 푸는건 불가능
// dp를 이용함