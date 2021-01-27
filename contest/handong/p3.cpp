#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct AA{
    int x, y;
};
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    AA p, q, r, s;
    int ans;
    cin >> p.x >> p.y;
    cin >> q.x >> q.y;
    cin >> r.x >> r.y;
    cin >> s.x >> s.y;

    int min_x1 = min(p.x, q.x);
    int min_x2 = min(r.x, s.x);

    if(min_x1 > min_x2){
        AA tmp1, tmp2;
        tmp1 = p; tmp2 = q;
        p=r; q=s;
        r=tmp1; s=tmp2;
    }

    if(!(p.x<s.x && q.y < s.y)) { cout << 0;  exit(0);}
    ans = abs(q.x-r.x) * abs(s.y-q.y);
    cout << ans;
    return 0;
}