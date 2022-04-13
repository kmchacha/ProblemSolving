#include <bits/stdc++.h>

using namespace std;

int arr[105][3], answer;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N;
    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    for(int number=111;number<=999;number++){
        int flag = 0;
        string pred_number = to_string(number);
        
        // 숫자에 0 이 포함된다면 continue
        for(int j=0;j<3;j++){
            if(pred_number[j] == '0') flag = 1;
        }
        
        // 같은 숫자가 존재한다면 continue
        if(pred_number[0] == pred_number[1] || pred_number[1] == pred_number[2] || pred_number[0] == pred_number[2]) flag = 1;
        if(flag == 1) continue;

        for(int j=0;j<N;j++){
            string true_number = to_string(arr[j][0]);
            int strike = arr[j][1];
            int ball = arr[j][2];
            int pred_strike = 0, pred_ball = 0;
            for(int k=0;k<3;k++){
                if(true_number[k] == pred_number[k]) pred_strike++;
            }

            for(int k=0;k<3;k++){
                if(pred_number.find(true_number[k]) != string::npos) pred_ball++;
            }
            pred_ball -= pred_strike;
            
            if(pred_strike != strike || pred_ball != ball) { 
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            answer++;
        }
    }
    cout << answer;
    return 0;
}