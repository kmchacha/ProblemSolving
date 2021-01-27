#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
// 10 12 30 8
// 30 8 -> 30 20 -> 30 32 -> 40 32 -> 40 44 -> 50 44 -> 50 56 -> 60 56 -> 60 68 -> 70 68 -> 70 80 -> 80 80
// 1 <= x, y, p1, p2 <= 100 이므로 최대 갈 수 있는 거리는 10000 이다.
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int x, y, p1, p2;
    cin >> x >> y >> p1 >> p2;
    while(1){
        if(p1>p2) p2 += y;
        else if(p1<p2) p1 += x;
        else {
            cout << p1 << endl;
            exit(0);
        }

        if(p1>10000 || p2>10000) break;
    }
    cout << -1 << '\n';

    return 0;
}