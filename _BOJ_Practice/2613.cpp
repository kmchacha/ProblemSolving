#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int a[301], answer[301], ansSize=1, n, m;

int judge(int v){
    int cnt=1, sum=0;
    for(int i=1;i<=n;i++){
        sum += a[i];
        if(sum > v) {
            cnt++;
            sum=a[i];
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //freopen("input.txt", "rt", stdin);
    int sum=0, ans=0;
    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        sum += a[i]; // 하나의 그룹이 가질 수 있는 최대 값
    }
    int lt=1, rt=sum, mid;
    while(lt<=rt){
        mid = (lt + rt) / 2;
        if(judge(mid) <= m){
            rt = mid - 1;
            ans = mid;
        }else {
            lt = mid + 1;
        }
    }

    cout <<  ans  << '\n';

   int num = 0, s = 0;
    for(int i = 0; i < n; i++){
        s += a[i+1];
        num++;
        if(s > ans){
            s = a[i+1];
            answer[ansSize++] = num - 1;
            num=1;
        }
    }
    answer[ansSize] = num;
    int difference = (m - ansSize);
    for(int i = 1; i <= ansSize; i++){
        if(answer[i] == 1) cout << answer[i] << ' ';
        else{
            while(answer[i] >= 2 && difference >= 1){
                cout << "1 ";
                answer[i]--; difference--;
            }
            cout << answer[i] << ' ';
        }
    }
    return 0;
}