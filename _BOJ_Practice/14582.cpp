#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int score[2][10];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    for(int i=0;i<2;i++){
        for(int j=1;j<10;j++){
            cin >> score[i][j];
        }
    }
    int T1=0, T2=0, flag=0;
    for(int i=1;i<10;i++){
        T1 += score[0][i];
        if(T1 > T2) flag=1;
        T2 += score[1][i];
    }
    if(flag==1) cout << "Yes" <<'\n';
    else cout << "No" << '\n';
    return 0;
}