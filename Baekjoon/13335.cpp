#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>
#include <queue>

using namespace std;

int truck[2000];

queue<int> Q;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("input.txt", "rt", stdin);
    // n 트럭의 수, w 다리의 길이. l 다리의 하중
    int n, w, l;
    cin >> n >> w >> l;    // 5  2  10
    // 각 트럭의 무게 입력받기
    for(int i=1;i<=n;i++){
        cin >> truck[i];   // 9 4 8 1 5
    }  

    int sum=0, t=0;
    for(int i=1;i<=n;i++){
        Q.push(truck[i]);
        t += 1;
        sum += truck[i];
        if(sum > l) {
            cout << Q.front() << endl;
            Q.pop();
        }
    }
    // int cur_w=0, cnt=0; // 현재 다리에 가해진 무게, 다리에 있는 트럭의 개수
    // for(int i=1;i<=n;i++){ /// i=4
    //     cur_w += a[i];   /// cur_w=6
    //     t+=1; cnt+=1;    /// t=6, cnt=1
        
    //     // 다리의 트럭이 꽉찬 경우
    //     if(cnt+1 > w) {
    //         if(i!=n && a[i+1] + cur_w - a[i-cnt+1] > l) {
    //             t+=(w-1); 
    //             cur_w=0; cnt=0;
    //             continue;    
    //         }
    //     }else {
    //         if(i!=n && a[i+1] + cur_w > l) {
    //             t+=(w-1); 
    //             cur_w=0; cnt=0;
    //             continue;    
    //         }
    //     }
    // }
    // t+=w;
    // cout << t << '\n';
    return 0;
}