#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int x, y, p, ans=0;
    cin >> x >> y >> p;
    
    while(p-->0){
        if(x>y){
            y++;
        }else {
            x++;
        }
    }
    ans = min(x, y) * 2;
    cout << ans;
    return 0;
}