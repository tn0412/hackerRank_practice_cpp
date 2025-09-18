#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1.size() << " " << s2.size() << endl << (s1+s2) << endl;
    char f_char = s1[0];
    s1[0] = s2[0];
    s2[0] = f_char;
    cout << s1 << " " << s2;
    return 0;
}
