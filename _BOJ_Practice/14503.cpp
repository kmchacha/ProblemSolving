#include <bits/stdc++.h>

using namespace std;

int N, M, answer=1;
int Board[55][55];

void solve(int r, int c, int d){
    if(Board[r][c] == 0) Board[r][c] = ++answer;

    int flag = 0;
    for(int i=0;i<4;i++){
        int to = d - (i + 1);
        to = (to < 0)? to + 4 : to;

        if(to == 0 && r-1 >= 0 && Board[r-1][c] == 0) { solve(r-1, c, to); flag=1; break;}
        if(to == 1 && c+1 < M && Board[r][c+1] == 0) { solve(r, c+1, to); flag=1; break;}
        if(to == 2 & r+1 < N && Board[r+1][c] == 0) { solve(r+1, c, to); flag=1; break;}
        if(to == 3 && c-1 >= 0 && Board[r][c-1] == 0) { solve(r, c-1, to); flag=1; break;}
    }
    
    if(d == 0 && r+1 >= 0 && Board[r+1][c] != 1)  solve(r+1, c, d); 
    else if(d == 1 && c-1 < M && Board[r][c-1]  != 1)  solve(r, c-1, d); 
    else if(d == 2 & r-1 < N && Board[r-1][c]  != 1)  solve(r-1, c, d); 
    else if(d == 3 && c+1 >= 0 && Board[r][c+1]  != 1)  solve(r, c+1, d);
    else {
        cout << answer-1;
        exit(0);
    }
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int r, c, d;
    cin >> N >> M;
    cin >> r >> c >> d;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> Board[i][j];
        }
    }
    solve(r, c, d);
    cout << answer-1;
    return 0;
}