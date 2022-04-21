#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct police{
    int x, y;
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int n, sx, sy;
    cin >> n;
    vector<police> police(n+1);
    for(int i=1;i<=n;i++){
        int x, y;
        cin >> x >> y;
        police[i].x = x;
        police[i].y = y;
    }
    cin >> sx >> sy;
    int hx=-2147000000, lx=2147000000, hy=-2147000000, ly=2147000000;
    for(int i=1;i<=n;i++){
        if(hx < police[i].x) hx=police[i].x;
        if(lx > police[i].x) lx=police[i].x;
        if(hy < police[i].y) hy=police[i].y;
        if(ly > police[i].y) ly=police[i].y;
    }
    if(sx > lx && sx <hx && sy > ly && sy < hy) cout << "NO" << '\n';
    else cout << "YES" << '\n';

    return 0;
}