#include <bits/stdc++.h>

using namespace std;

int H[100005];
int histogram(int s, int e){
    if(s > e) return 0;
    if(s == e) return H[s];
    int mid = (s + e) / 2;
    int result = max(histogram(s, mid), histogram(mid+1, e));

    int w = 1, h = H[mid], l = mid, r = mid;
    while(r - l <= e - s){
        int p = (l > s) ? min(h, H[l - 1]) : -1;
        int q = (r < e) ? min(h, H[r + 1]) : -1;

        if(p >= q) {
            h = p;
            l--;
        }else {
            h = q;
            r++;
        }
        w++;
        result = max(result, w * h);
    }
    return result;
}
// int histogram(int start, int end){
//     if(start == end) return 0;
//     if(start + 1 == end) return H[start];

//     int mid = (start + end) / 2;
//     int result = max(histogram(start, mid), histogram(mid, end));

//     // 양쪽 구간에 걸쳐 있는 답을 O(e-s)에 찾음
//     int w = 1, h = H[mid] ,l = mid, r = mid;
//     while(r - l + 1 < end - start){
//         int p = l > start ? min(h, H[l - 1]) : -1;
//         int q = r < end - 1 ? min(h, H[r + 1]) : -1;

//         if(p >= q) {
//             h = p;
//             l--;
//         }else {
//             h = q;
//             r++;
//         }

//         result = max(result, ++w * h);
//     }
//     return result;
// }
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> H[i];
    cout << histogram(0, N - 1);
    return 0;
}