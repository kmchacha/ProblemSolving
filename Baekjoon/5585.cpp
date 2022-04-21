
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coin[]={500,100,50,10,5,1}, cnt;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    m = 1000 - n;
    for(int i=0;i<6;i++){
        while(m-coin[i] >=0) {
            cnt++;
            m = m - coin[i];
        }
    }
    cout << cnt << '\n';
    return 0;
}

// 500 100 50 10 5 1 모두 배수인 것을 알 수 있다.
// 그리디 알고리즘 