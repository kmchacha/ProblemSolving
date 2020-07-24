/*
'******************************************************************************
' 파일명    : pps65.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/24
' 문제      : 미로 탐색(DFS)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[8][8], ch[8][8],cnt=0;
void DFS(int x, int y){
    if(x==7 && y==7) {
        cnt++;
    }else {
        if(1<=y-1 && y-1<=7 && ch[x][y-1]==0 && map[x][y-1]==0) {
            ch[x][y-1]=1;
            DFS(x,y-1);
            ch[x][y-1]=0;
        }
        if(1<=x+1 && x+1<=7 && ch[x+1][y]==0 && map[x+1][y]==0) {
            ch[x+1][y]=1;
            DFS(x+1,y);
            ch[x+1][y]=0;
        }
        if(1<=y+1 && y+1<=7 && ch[x][y+1]==0 && map[x][y+1]==0) {
            ch[x][y+1]=1;
            DFS(x,y+1);
            ch[x][y+1]=0;
        }
        if(1<=x-1 && x-1<=7 && ch[x-1][y]==0 && map[x-1][y]==0) {
            ch[x-1][y]=1;
            DFS(x-1,y);
            ch[x-1][y]=0;
        }
    }
}
int main(){
    freopen("input.txt", "rt", stdin);
    for(int i=1;i<=7;i++){
        for(int j=1;j<=7;j++){
            cin >> map[i][j];
        }
    }
    ch[1][1]=1;
    DFS(1,1);
    cout << cnt << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// int map[10][10], ch[10][10];
// int dx[4] = {-1,0,1,0};
// int dy[4] = {0,1,0,-1};
// int cnt=0;
// void DFS(int x, int y){
//     int i, xx, yy;
//     if(x==7 && y==7){
//         cnt++;
//     }else {
//         for(i=0;i<4;i++){
//             xx = x + dx[i]; // 가려고 하는 x 좌표
//             yy = y + dy[i]; // 가려고 하는 y 좌표
//             if(xx<1 || xx>7 || yy<1 || yy>7) continue;
//             if(map[xx][yy]==0 && ch[xx][yy]==0) {
//                 ch[xx][yy] = 1;
//                 DFS(xx, yy);
//                 ch[xx][yy] = 0;
//             }
//         }
//     }
// }
// int main(){
//     freopen("input.txt", "rt", stdin);
//     int i, j;
//     for(i=1;i<=7;i++){
//         for(j=1;j<=7;j++){
//             cin >> map[i][j];
//         }
//     }
//     ch[1][1]=1;
//     DFS(1, 1);
//     cout << cnt << endl;
//     return 0;
// }