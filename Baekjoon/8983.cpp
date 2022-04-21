#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> loc;
vector<pair<int, int> > Animal_loc;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    int M, N, L, cnt=0; // 사대의 수, 동물의 수, 사정거리
    cin >> M >> N >> L;

    vector<int> ch(N+1);

    // 사대의 x 위치 받기
    for(int i=0;i<M;i++){
        int tmp;
        cin >> tmp;
        loc.push_back(tmp);
    }
    // 사대 x 좌표 오름차순으로 정렬하기
    sort(loc.begin() , loc.end());
    for(int i=0;i<M;i++){
        cout << loc[i] << " ";
    }
    cout << endl;
    // 동물의 위치 받기
    for(int i=0;i<N;i++){
        int x, y;
        cin >> x >> y;
        Animal_loc.push_back(make_pair(x,y));
    }
    // 동물들 x좌표 오름차순으로 정렬하기
    sort(Animal_loc.begin(), Animal_loc.end());
    for(int i=0;i<N;i++){
        cout << Animal_loc[i].first << " " << Animal_loc[i].second << endl;
    }
    
    int cur=0; // 사대의 현재 위치 index
    // 동물을 기준으로 가장 가까운 왼쪽 사대와 오른쪽 사대를 통해서 cnt를 증가시킨다
    for(int i=0;i<N;i++){
        
    }
    cout << cnt << '\n';
    
    return 0;
}