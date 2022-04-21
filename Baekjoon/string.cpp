#include <iostream>
#include <string>
#include <vector>

int
main(int argc, const char* argv[])
{
    using namespace std;


    cout << "Your name ? : ";
    string name;
    std::getline(std::cin, name);

    cout << "Your age ? : ";
    int age;
    cin >> age;

    cout << name << " " << age << " ";

    typedef std::vector<std::pair<std::string, int> > pairlist_t;
    pairlist_t p1;
    //using pairlist_t = std::vector<std::pair<std::string, int> > ;

    return 0;
}