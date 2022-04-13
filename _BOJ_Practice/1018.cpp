#include <bits/stdc++.h>

using namespace std;

int N, M, answer = INT_MAX;
char board[55][55];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> board[i][j];
        }
    }
    
    int count;
    for(int i=0;i<=N-8;i++){
        for(int j=0;j<=M-8;j++){
            count = 0;
            for(int p=i;p<i+8;p++){
                for(int q=j;q<j+8;q++){
                    if((p + q) % 2 == 0) {
                        if(board[p][q] != 'W') count++;
                    }else {
                        if(board[p][q] != 'B') count++;
                    }
                }
            }
            answer  = min(answer, count);
        }
    }

    for(int i=0;i<=N-8;i++){
        for(int j=0;j<=M-8;j++){
            count = 0;
            for(int p=i;p<i+8;p++){
                for(int q=j;q<j+8;q++){
                    if((p + q) % 2 == 0) {
                        if(board[p][q] != 'B') count++;
                    }else {
                        if(board[p][q] != 'W') count++;
                    }
                }
            }
            answer  = min(answer, count);
        }
    }
    answer  = min(answer, count);
    cout << answer;
    return 0;
}