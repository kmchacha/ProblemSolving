// // 시간 초과
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <queue>
// using namespace std;
// int map[10][10], n=9;

// int main(){
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     //freopen("input.txt", "rt", stdin);
//     queue<pair<int, int> > Q;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cin >> map[i][j];
//             if(map[i][j] == 0) {
//                 ch[i/3+1][j/3+1][i][j]=1;
//                 Q.push(make_pair(i,j));
//             }
//         }
//     }

//     while(!Q.empty()){
//         pair<int, int> tmp = Q.front();
//         Q.pop();
//         int cx = tmp.second;
//         int cy = tmp.first;

//         // 가로 계산
//         int tmp2, cnt=0;
//         for(int k=1;k<=9;k++){
//             int flag=0;
//             for(int i=0;i<n;i++){
//                 if(map[cy][i]==k) flag=1;
//             }
//             if(flag==0) {
//                 cnt++;
//                 tmp2 = k;
//             }
//         }
//         if(cnt==1) {
//             map[cy][cx]=tmp2;
//             continue;
//         }
//         // 세로 계산
//         cnt=0;
//         for(int k=1;k<=9;k++){
//             int flag=0;
//             for(int i=0;i<n;i++){
//                 if(map[i][cx]==k) flag=1;
//             }
//             if(flag==0) {
//                 cnt++;
//                 tmp2 = k;
//             }
//         }
//         if(cnt==1) {
//             map[cy][cx]=tmp2;
//             continue;
//         }
//         // 3 x 3 계산
//         cnt=0;
//         for(int k=1;k<=n;k++){
//             int flag=0;
//             for(int i=cy/3*3;i<cy/3*3+3;i++){
//                 for(int j=cx/3*3;j<cx/3*3+3;j++){
//                     if(map[i][j]==k) flag=1;
//                 }
//             }
//             if(flag==0){
//                 cnt++;
//                 tmp2 = k;
//             }
//         }
//         if(cnt==1) {
//             map[cy][cx]=tmp2;
//             continue;
//         }

//         Q.push(make_pair(cx,cy));
        
//     }   
    
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout << map[i][j] << " ";
//         }
//         cout << '\n';
//     }
//     return 0;
// }



#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int map[11][11], n=9, ch[11];

// 가로 검사
bool check1(int r, int num){
    for(int i=1;i<=n; i++){
        if(map[r][i] == num) return true;
    }
    return false;
}
// 세로 검사
bool check2(int c, int num){
    for(int i=1;i<=n;i++){
        if(map[i][c]==num) return true;
    }
    return false;
}
// 3x3 검사
bool check3(int r, int c, int num){
    //int r = (r % 3) + (r-1 / 3)*3;
    //int c = (c % 3) + (c-1 / 3)*3;
    for(int rr=r;rr<=rr+2;rr++){

    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "rt", stdin);
    queue<pair<int, int> > Q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
            if(map[i][j] == 0) {
                Q.push(make_pair(i,j));
            }
        }
    }

    
    return 0;
}