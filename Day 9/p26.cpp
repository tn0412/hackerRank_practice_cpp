#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class AddElements {
    T element;
public:
    AddElements(T arg) { element = arg; }
    T add(T other) { return element + other; }
};

template <>
class AddElements<string> {
    string element;
public:
    AddElements(string arg) { element = arg; }
    string concatenate(string other) { return element + other; }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while(n--) {
        string a;
        cin >> a;
        if(a == "string") {
            string b, c;
            cin >> b >> c;
            AddElements<string> obj1(b);
            cout << obj1.concatenate(c) << "\n";
        }
        else if (a == "int") {
            int b, c;
            cin >> b >> c;
            AddElements<int> obj2(b);
            cout << obj2.add(c) << "\n";
        }
        else if (a == "float") {
            float b, c;
            cin >> b >> c;
            AddElements<float> obj3(b);
            cout << obj3.add(c) << "\n";
        }
    }
    return 0;
}
