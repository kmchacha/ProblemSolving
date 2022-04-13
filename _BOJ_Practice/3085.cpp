#include <bits/stdc++.h>

using namespace std;

int dy[] = {1, 0};
int dx[] = {0, 1};
int N, answer;
char arr[55][55];

int func(int y1, int x1, int y2, int x2){
    char temp = arr[y1][x1];
    arr[y1][x1] = arr[y2][x2];
    arr[y2][x2] = temp;
    
    
    int ret = 0, cnt;
    char ch;
    for(int j=0;j<N;j++){
        ch = arr[j][0];
        cnt = 1;
        for(int i=1;i<N;i++){
            if(ch == arr[j][i]) {
                cnt++;
            }else {
                cnt = 1;
                ch = arr[j][i];
            }
            ret = max(ret, cnt);
        }
    }

    for(int j=0;j<N;j++){
        ch = arr[0][j];
        cnt = 1;
        for(int i=1;i<N;i++){
            if(ch == arr[i][j]) {
                cnt++;
            }else {
                cnt = 1;
                ch = arr[i][j];
            }
            ret = max(ret, cnt);
        }
    }
    
    temp = arr[y1][x1];
    arr[y1][x1] = arr[y2][x2];
    arr[y2][x2] = temp;

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> arr[i][j];
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            
            for(int k=0;k<2;k++){
                int nextY = dy[k] + i;
                int nextX = dx[k] + j;
                if(nextY < 0 || nextX < 0 || nextY >= N || nextX >= N) continue;

                if(arr[nextY][nextX] != arr[i][j]) {
                    int count = func(i, j, nextY, nextX);

                    answer = max(answer, count);
                }
            }
        }
    }
    cout << answer;
    return 0;
}