#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int n, d, k, c;
    cin >> n >> d >> k >> c;
    vector<int> a(n+1, 0);
    for(int i=1;i<=n;i++)   cin >> a[i];
    // 쿠폰 번호의 초밥을 제외하고 나머지 초밥 중에서 k개의 배열을 찾는다
    

    return 0;
}