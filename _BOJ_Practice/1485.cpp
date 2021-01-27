#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct loc{
    int x, y;
};

// 정사각형과 마름모의 비교
// 정사각형과 마름모는 네 변의 길이가 모두 같은 것이 공통점이다
// 하지만 정사각형은 두 대각선의 길이도 같아야한다 (마름모는 두 대각선의 길이가 다르다)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt","rt",stdin);
    int T;
    cin >> T;
    while(T--){
        loc a[4];
        cin >> a[0].x >> a[0].y;
        cin >> a[1].x >> a[1].y;
        cin >> a[2].x >> a[2].y;
        cin >> a[3].x >> a[3].y;
        
        int index=0;
        long long temp[10];
        for(int i=0;i<3;i++){
            for(int j=i+1;j<4;j++){
                temp[index++] = ((a[i].x - a[j].x) * (a[i].x - a[j].x)) + ((a[i].y - a[j].y) * (a[i].y - a[j].y));
            }
        }
        sort(temp, temp+6);

        int ans = (temp[0] == temp[1]) && (temp[1] == temp[2]) && (temp[2] == temp[3]) && (temp[4] == temp[5]);

        cout << ans << '\n';
    }

    return 0;
}