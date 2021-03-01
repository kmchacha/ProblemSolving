#include <bits/stdc++.h>

using namespace std;

struct loc{
    int x, y, d;
    loc(int a, int b, int c){
        x=a;
        y=b;
        d=c;
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "rt", stdin);
    int n, cnt=0;
    int hx , hy;
    cin >> hx >> hy;
    loc house = loc(hx, hy, 0);
    cin >> n;
    loc * arr = (loc *)malloc(sizeof(loc) * (n+1));

    for(int i=1;i<=n;i++){
        cin >> arr[i].x >> arr[i].y >> arr[i].d;
    }
    // ** pow 함수를 사용할떄는 항상 long long 으로 타입을 바꾸어주자...
    
    // 지후의 집으로 치킨을 배달할 수 있는 가맹점의 개수
    for(int i=1;i<=n;i++){
        int diff = pow(house.x - arr[i].x, 2) + pow(house.y - arr[i].y, 2);

        if(diff <= pow(arr[i].d, 2)){
            //cout << "YES" << endl;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}