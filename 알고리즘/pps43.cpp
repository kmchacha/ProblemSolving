/*
'******************************************************************************
' 파일명    : pps43.cpp
' 작성자    : 차경민
' 목적      : Problem Solving
' 날짜      : 2020/07/20
' 문제      : 뮤직 비디오      이분 검색 응용(결정 알고리즘)
'******************************************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
int a[1001], n;
using namespace std;
int count(int size) {
    int i, sum=0, cnt=1;
    for(i=1;i<=n;i++){
        if(sum>=size){
            sum = 0;
            cnt++;
        }
    }
    return cnt;
}
int main(){
    freopen("input.txt", "rt", stdin);
    int n, m, i, lt=1, rt, mid, res;
    cin >> n >> m;
    for(i=0;i<n;i++){
        cin >> a[i];
        rt += a[i];
    }
    
    while(lt<=rt){
        mid = (lt+rt)/2;
        if(count(mid)>=m){
            res = mid;
            lt = mid + 1;
        }else{
            rt = mid - 1;
        }
    }
    cout << res << endl;
    return 0;
}
// #include <iostream>
// #include <vector>
// #include <algorithm>
// int a[1001], n;
// using namespace std;
// int count(int size) {
//     int i, cnt=1, sum=0;
//     for(i=1;i<=n;i++) {
//         if(sum + a[i] > size) {
//             cnt++;  // 새로운 dvd
//             sum = a[i];
//         }
//         else {
//             sum = sum + a[i];
//         }
//     }
//     return cnt;
// }
// int main(){
//     freopen("input.txt", "rt", stdin);
//     int m, i, lt=1, rt=0, mid, res, maxx=-2147000000;
//     cin >> n >> m;
//     for(i=1;i<=n;i++){
//         cin >> a[i];
//         rt += a[i];
//         if(a[i] > maxx) maxx=a[i];
//     }
//     while(lt<=rt){
//         mid = (lt + rt) / 2;
//         if(mid>=maxx && count(mid)<=m){
//             res = mid;
//             rt = mid - 1;
//         }
//         else {
//             lt = mid + 1;
//         }
//     }
//     cout << res << endl;
    
//     return 0;
// }