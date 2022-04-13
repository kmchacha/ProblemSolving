#include <bits/stdc++.h>

using namespace std;

int N, board[2200][2200];
int answer[3]; // -1, 0, 1
void recursion(int y1, int x1, int y2, int x2){
    if(y1 == y2 && x1 == x2) {
        answer[board[y1][x1] + 1] += 1;
        return;
    }

    int flag = 0, temp = board[y1][x1];
    for(int i=y1;i<=y2;i++){
        for(int j=x1;j<=x2;j++){
            if(temp != board[i][j]) { flag = 1; break; }
        }
        if(flag == 1) break;
    }
    // 모두 숫자가 같은 경우
    if(flag == 0) {
        answer[board[y1][x1] + 1] += 1;
    }else { // 다른 경우
        int width = (y2 - y1 + 1) / 3;

        recursion(y1, x1, y1 + (width - 1), x1 + (width - 1));
        recursion(y1, x1 + width,  y1 + (width - 1), x1 +2*width - 1);
        recursion(y1, x1 + 2*width, y1 + (width - 1), x1 + 3*width - 1);

        recursion(y1 + width, x1, y1 + 2*width - 1, x1 + (width - 1));
        recursion(y1 + width, x1 + width, y1 + 2*width - 1, x1 + 2*width - 1);
        recursion(y1 + width, x1 + 2*width, y1 + 2*width - 1, x1 + 3*width -1);

        recursion(y1 + 2*width, x1, y1 + 3*width -1, x1 + (width - 1));
        recursion(y1 + 2*width, x1 + width, y1 + 3*width -1, x1 +2*width - 1);
        recursion(y1 + 2*width, x1 + 2*width, y1 + 3*width -1, x1 + 3*width - 1);
    }
    return;
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
    recursion(1, 1, N, N);
    cout << answer[0] << '\n' << answer[1] << '\n' << answer[2];
    return 0;
}