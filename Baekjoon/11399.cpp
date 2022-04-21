#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, ans=0;
    cin >> n;
    vector<int> array(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> array[i];
    }
    sort(array.begin()+1, array.end());
    for(int i=1;i<=n;i++) {
        array[i] = array[i-1] + array[i];
        ans += array[i];
    }
    cout << ans << '\n';
    return 0;
}