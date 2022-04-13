#include <bits/stdc++.h>

using namespace std;

int N, board[6600][6600];
void Draw(int y1, int x1, int y2, int x2, int n){
    if(n == 3) {
        for(int i=y1;i<=y2;i++){
            for(int j=x1;j<=x2;j++){
                board[i][j] = 1;
            }
        }
        board[y1+1][x1+1] = 0;
    }else {
        int width = n / 3;
        Draw(y1, x1, y1+width-1, x1+width-1, width);
        Draw(y1, x1 + width, y1+width-1, x1+2*width-1, width);
        Draw(y1, x1 + 2*width, y1+width-1, x1+3*width-1, width);

        Draw(y1+width, x1, y1+2*width-1, x1+width-1, width);
        Draw(y1+width, x1 + 2*width, y1+3*width-1, x1+3*width-1, width);

        Draw(y1 + 2*width, x1, y1+3*width-1, x1+width-1, width);
        Draw(y1 + 2*width, x1 + width, y1+3*width-1, x1+2*width-1, width);
        Draw(y1 + 2*width, x1 + 2*width, y1+3*width-1, x1+3*width-1, width);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    Draw(1, 1, N, N, N);
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(board[i][j] == 1) cout << "*";
            else cout << " ";
        }
        cout << '\n';
    }
    return 0;   
}