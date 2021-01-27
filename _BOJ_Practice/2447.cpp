#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char map[3000][3000];

void recur(int n, int x, int y){
    if(n==1){
        map[x][y]='*';
    }
    else {
        int div=n/3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(i==1 && j==1) continue;

                recur(div, (i*div) + x ,(j*div)+y);
            }
        }
    }
}
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            map[i][j]=' ';
        }
    }
    recur(n, 0, 0);

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << map[i][j];
        }
        cout << '\n';
    }
    return 0;
}