#include <bits/stdc++.h>

using namespace std;

int N, M, arr[505][505], ans;
vector<pair<int, int> > v[19];
vector<pair<int, int> > vSize;
int tetromino(int curY, int curX, int idx){
    int ret = 0;
    for(int i=0;i<v[idx].size();i++){
        int nextY = v[idx][i].first + curY;
        int nextX = v[idx][i].second + curX;
        ret += arr[nextY][nextX];
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> arr[i][j];
        }
    }
    //  ㅡ
    v[0].push_back(make_pair(0, 0));
    v[0].push_back(make_pair(0, 1));
    v[0].push_back(make_pair(0, 2));
    v[0].push_back(make_pair(0, 3));
    vSize.push_back(make_pair(1, 4));

    // ㅣ
    v[1].push_back(make_pair(0, 0));
    v[1].push_back(make_pair(1, 0));
    v[1].push_back(make_pair(2, 0));
    v[1].push_back(make_pair(3, 0));
    vSize.push_back(make_pair(4, 1));

    // ㅁ
    v[2].push_back(make_pair(0, 0));
    v[2].push_back(make_pair(1, 0));
    v[2].push_back(make_pair(0, 1));
    v[2].push_back(make_pair(1, 1));
    vSize.push_back(make_pair(2, 2));

    // L
    v[3].push_back(make_pair(0, 0));
    v[3].push_back(make_pair(1, 0));
    v[3].push_back(make_pair(2, 0));
    v[3].push_back(make_pair(2, 1));
    vSize.push_back(make_pair(3, 2));

    // ┌ 긴거
    v[4].push_back(make_pair(0, 0));
    v[4].push_back(make_pair(0, 1));
    v[4].push_back(make_pair(0, 2));
    v[4].push_back(make_pair(1, 0));
    vSize.push_back(make_pair(2, 3));

    // ㄴ
    v[5].push_back(make_pair(0, 0));
    v[5].push_back(make_pair(1, 0));
    v[5].push_back(make_pair(1, 1));
    v[5].push_back(make_pair(1, 2));
    vSize.push_back(make_pair(2, 3));

    // ┌ 짧은거
    v[6].push_back(make_pair(0, 0));
    v[6].push_back(make_pair(0, 1));
    v[6].push_back(make_pair(1, 0));
    v[6].push_back(make_pair(2, 0));
    vSize.push_back(make_pair(3, 2));

    // ┘ 짧은거
    v[7].push_back(make_pair(0, 1));
    v[7].push_back(make_pair(1, 1));
    v[7].push_back(make_pair(2, 0));
    v[7].push_back(make_pair(2, 1));
    vSize.push_back(make_pair(3, 2));

    // ㄱ
    v[8].push_back(make_pair(0, 0));
    v[8].push_back(make_pair(0, 1));
    v[8].push_back(make_pair(0, 2));
    v[8].push_back(make_pair(1, 2));
    vSize.push_back(make_pair(2, 3));

    // ㄴ 좌우 회전
    v[9].push_back(make_pair(0, 2));
    v[9].push_back(make_pair(1, 0));
    v[9].push_back(make_pair(1, 1));
    v[9].push_back(make_pair(1, 2));
    vSize.push_back(make_pair(2, 3));

    // ㄱ 짧은
    v[10].push_back(make_pair(0, 0));
    v[10].push_back(make_pair(0, 1));
    v[10].push_back(make_pair(1, 1));
    v[10].push_back(make_pair(2, 1));
    vSize.push_back(make_pair(3, 2));

    // ㄹ 1
    v[11].push_back(make_pair(0, 0));
    v[11].push_back(make_pair(1, 0));
    v[11].push_back(make_pair(1, 1));
    v[11].push_back(make_pair(2, 1));
    vSize.push_back(make_pair(3, 2));

    // ㄹ 2
    v[12].push_back(make_pair(0, 1));
    v[12].push_back(make_pair(0, 2));
    v[12].push_back(make_pair(1, 0));
    v[12].push_back(make_pair(1, 1));
    vSize.push_back(make_pair(2, 3));

    // ㄹ 3
    v[13].push_back(make_pair(0, 1));
    v[13].push_back(make_pair(1, 0));
    v[13].push_back(make_pair(1, 1));
    v[13].push_back(make_pair(2, 0));
    vSize.push_back(make_pair(3, 2));

    // ㄹ 4
    v[14].push_back(make_pair(0, 0));
    v[14].push_back(make_pair(0, 1));
    v[14].push_back(make_pair(1, 1));
    v[14].push_back(make_pair(1, 2));
    vSize.push_back(make_pair(2, 3));

    // ㅜ
    v[15].push_back(make_pair(0, 0));
    v[15].push_back(make_pair(0, 1));
    v[15].push_back(make_pair(0, 2));
    v[15].push_back(make_pair(1, 1));
    vSize.push_back(make_pair(2, 3));

    // ㅓ
    v[16].push_back(make_pair(0, 1));
    v[16].push_back(make_pair(1, 0));
    v[16].push_back(make_pair(1, 1));
    v[16].push_back(make_pair(2, 1));
    vSize.push_back(make_pair(3, 2));

    // ㅗ
    v[17].push_back(make_pair(0, 1));
    v[17].push_back(make_pair(1, 0));
    v[17].push_back(make_pair(1, 1));
    v[17].push_back(make_pair(1, 2));
    vSize.push_back(make_pair(2, 3));

    // ㅏ
    v[18].push_back(make_pair(0, 0));
    v[18].push_back(make_pair(1, 0));
    v[18].push_back(make_pair(1, 1));
    v[18].push_back(make_pair(2, 0));
    vSize.push_back(make_pair(3, 2));

    for(int k=0;k<19;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(i + vSize[k].first <= N && j + vSize[k].second <= M) {
                    ans = max(ans, tetromino(i, j, k));
                }
            }
        }
    }
    cout << ans;
    return 0;
}