#include <bits/stdc++.h>

using namespace std;

int N;
char board[100][100];
void solve(int y1, int x1, int y2, int x2){
    int flag = 0;
    for(int i=y1;i<=y2;i++){
        for(int j=x1;j<=x2;j++){
            if(board[i][j] != board[y1][x1]) { flag =1; break;}
        }
        if(flag ==1) break;
    }

    if(flag == 0){
        cout << board[y1][x1];
    }else {
        int width = (y2 - y1 + 1) / 2;
        cout << "(";
        solve(y1, x1, y1 +(width - 1), x1 +(width -1));
        solve(y1, x1 + width, y1 +(width - 1), x1 + 2*width -1);
        solve(y1 + width, x1, y1 +2*width - 1, x1 + width -1);
        solve(y1 + width, x1 + width, y1 +2*width - 1, x1 + 2*width -1);
        cout << ")";
    }

}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> board[i][j];
        }
    }
    solve(1, 1, N, N);

    return 0;   
}