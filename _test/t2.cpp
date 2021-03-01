#include <bits/stdc++.h>
using namespace std;

int board[100001][100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("input1.txt", "rt" , stdin);
    int w, h, t, s; 
    cin >> w >> h >> t  >> s;
    for(int i=0;i<t;i++){
        int x, y;
        cin >> x >> y;
        board[y][x]++;
    }
    for(int i=0;i<s-1;i++){
        for(int j=0;j<s-1;j++){
            if(board[i][j] == 1){
                board[s-1][s-1]++;
            }
        }
    }
    for(int i=0;i<h+1;i++){
        for(int j=0;j<w+1;j++){
            cout << board[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;
    cout << board[s-1][s];
    return 0;
}