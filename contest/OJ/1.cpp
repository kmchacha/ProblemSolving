#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, m; 
    long long ans = 0;
    cin >> n >> m;
    ans = ((m *(m+1))/2) - ((n *(n+1))/2) + n;
    cout << ans;

    return 0;
}
