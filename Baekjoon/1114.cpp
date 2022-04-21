#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
// 통나무의 가장 긴 조각을 작게 만드는 프로그램

int l, k, c, ans1, ans2; // l 통나무의 길이, k 통나무를 자를 수 있는 위치의 개수, c 자를 수 있는 횟수
vector<int> location_cut(10002), each_length(10002);

int check(int size){
    int sum = 0, cnt = c;
    for(int i=k;i>=0;i--){
        if(each_length[i] > size) return -1;
        sum += each_length[i];

        if(sum > size){
            cnt--;
            sum = each_length[i];
        }

        if(cnt == 0){
            if(location_cut[i] > size) return -1;
            else return location_cut[i];
        }
    }
    return location_cut[0];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);

    cin >> l >> k >> c;
    
    for(int i=0;i<k;i++) cin >> location_cut[i];
    location_cut[k] = l;  // 맨 마지막 원소를 통나무의 길이로 해준다. (each_length 계산을 위해서)

    sort(location_cut.begin(), location_cut.begin() + k); // 정렬
    // 통나무를 자를 수 있는 위치 - 이전 통나무를 자를 수 있는 위치를 계산해서 each_length 배열에 넣어주었다
    each_length[0] = location_cut[0];
    for(int i=1;i<=k;i++){
        each_length[i] = location_cut[i] - location_cut[i-1];
    }
    
    int lt=1, rt=l, mid;
    while(lt<=rt){
        int tmp;
        mid = (lt + rt) / 2;
        if((tmp = check(mid)) > 0){
            ans1 = mid;
            ans2 = tmp;
            rt = mid -1;
        }else lt = mid + 1;
    }

    // output : 첫 번째 수는 가장 긴 조각의 길이이고, 두 번째 수는 그 때 처음 자르는 위치
    cout << ans1 << " " << ans2 << '\n';

    return 0;
}