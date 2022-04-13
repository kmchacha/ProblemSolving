#include <bits/stdc++.h>

using namespace std;

string factorial[101][101];

string bigNumAdd(string n1, string n2)
{
    int sum = 0;
    string result;

    // 1의 자리부터 더하기
    while (!n1.empty() || !n2.empty() || sum)
    {
        if (!n1.empty())
        {
            sum += n1.back() - '0';
            n1.pop_back();
        }
        if (!n2.empty())
        {
            sum += n2.back() - '0';
            n2.pop_back();
        }
        result.push_back((sum % 10) + '0');
        sum /= 10;
    }

    // 1의 자리부터 push 했으므로 뒤집어준다.
    reverse(result.begin(), result.end());
    return result;
}

string combination(int n, int r)
{
    if (n == r || r == 0)
        return "1";
    string &result = factorial[n][r]; // 참조형 변수

    if (result != "")
        return result;

    // 파스칼삼각형 원리 이용
    result = bigNumAdd(combination(n - 1, r - 1), combination(n - 1, r));
    return result;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "rt", stdin);
    long long N, M;
    cin >> N >> M;
    cout << combination(N, M);
    return 0;
}