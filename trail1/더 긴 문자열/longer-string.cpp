#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if(s1.size() > s2.size()) cout << s1 << ' ' <<  s1.size();
    else if(s1.size() < s2.size()) cout << s2 << ' ' << s2.size();
    else cout << "same" ;
    return 0;
}