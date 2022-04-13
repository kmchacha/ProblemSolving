#include <bits/stdc++.h>

using namespace std;

char arr[105][105];
int dy[] = {0, 1, 0 ,-1};
int dx[] = {1, 0, -1, 0};
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> arr[i][j];
        }
    }
    queue<pair<int, int> > q;
    vector<vector<int> > ch1(105, vector<int>(105, 0));
    int answer1 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ch1[i][j] == 0){
                ch1[i][j] = 1;
                answer1++;
                char buf = arr[i][j];
                q.push(make_pair(i, j));
                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();

                    for(int k=0;k<4;k++){
                        int nextY = cur.first + dy[k];
                        int nextX = cur.second + dx[k];

                        if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
                        if(ch1[nextY][nextX] == 1) continue;
                        if(buf != arr[nextY][nextX]) continue;

                        ch1[nextY][nextX] = 1;
                        q.push(make_pair(nextY, nextX));
                    }
                }
            }
        }
    }
    cout << answer1 << " ";


    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j] == 'R') arr[i][j] = 'G';
        }
    }
    vector<vector<int> > ch2(105, vector<int>(105, 0));
    int answer2 = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ch2[i][j] == 0){
                ch2[i][j] = 1;
                answer2++;
                char buf = arr[i][j];
                q.push(make_pair(i, j));
                while(!q.empty()){
                    pair<int, int> cur = q.front(); q.pop();

                    for(int k=0;k<4;k++){
                        int nextY = cur.first + dy[k];
                        int nextX = cur.second + dx[k];

                        if(nextY < 0 || nextX < 0 || nextY >= n || nextX >= n) continue;
                        if(ch2[nextY][nextX] == 1) continue;
                        if(buf != arr[nextY][nextX]) continue;

                        ch2[nextY][nextX] = 1;
                        q.push(make_pair(nextY, nextX));
                    }
                }
            }
        }
    }
    cout << answer2 << " ";

    return 0;
}