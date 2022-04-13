#include <bits/stdc++.h>

using namespace std;

int order[105], answer;
vector<int> v;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    int N, K;
    cin >> N >> K;
    for(int i=0;i<K;i++) cin >> order[i];
    for(int i=0;i<K;i++){
        if(v.size() < N) {
            int flag = 0;
            for(int j=0;j<v.size();j++) {
                if(v[j] == order[i]) flag = 1;
            }
            if(flag == 0) v.push_back(order[i]);
            continue;
        }

        int flag = 0;
        for(int j=0;j<v.size();j++){
            if(v[j] == order[i]) { flag = 1; break;}
        }
        if(flag == 1) continue;

        vector<int> temp(K+1, -1);
        for(int q=0;q<v.size();q++){
            for(int p=i+1;p<K;p++){
                if(temp[q] == -1 && order[p] == v[q]) temp[q] = p;
            }
        }

        int max_idx = 0;
        for(int q=0;q<v.size();q++){
            if(temp[q] == -1) { 
                flag = 1;
                v[q] = order[i]; 
                answer++;
                break;
            }
            max_idx = max(max_idx, temp[q]);
        }
        if(flag == 1) continue;
        
        for(int j=0;j<v.size();j++){
            if(order[max_idx] == v[j]) {
                v[j] = order[i];
                answer++;
                break;
            }
        }
    }
    cout << answer;
    return 0;
}