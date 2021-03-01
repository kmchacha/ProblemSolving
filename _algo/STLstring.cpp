#include <bits/stdc++.h>
using namespace std;

// <algorithm> 에 string 존재
// #include <cctype> -> isupper(), islower(), isdigit()
int main()
{
    string a = "Time is 2021Year 03Month";
    cout << a.size() << endl;
    cout << a.length() << endl;

    for(int i=0;i<a.size();i++){
        cout << a[i] << ' ';
    }
    cout << endl;

    for(int i=0;i<a.size();i++){
        // if(isupper(a[i]))   cout << a[i] << ' '; // 대문자
        // if(islower(a[i]))   cout << a[i] << ' '; // 소문자
        if(isdigit(a[i]))   cout << a[i] << ' '; // 숫자
    }
    cout << endl;

    cout << a.find('Q'); // 문자의 인덱스 번호를 리턴받는다
    cout << endl;

    a.push_back('s');   // 문자 한개를 추가 
    cout << a << endl;

    a.pop_back();   // 문자 한개를 제거
    cout << a << endl; 

    a = a + 's';    // 문자 한개를 추가 
    cout << a << endl;

    a = a + " 28day";
    cout << a << endl;

    cout << a.substr(8) << endl; // 문자열에서 부분 문자열을 뽑아낸다 (해당 문자부터 끝까지 추출)
    cout << a.substr(0, 4) << endl; // 0번 인덱스부터 4개를 뽑아낸다 (두번쨰 인자는 뽑아낼 문자열의 길이)
    cout << a.substr(8,4) << endl;
    cout << a << endl; // string a에는 영향을 주지 않는다

    a.clear(); // string을 clear 시켜준다
    cout << a << endl;
    return 0;
}
