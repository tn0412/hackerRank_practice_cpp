#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> parseInts(string str) {
    stringstream ss(str);
    char ch;
    int number;
    vector<int> result;
    while (ss >> number) {
        result.push_back(number);
        ss >> ch;  // Read the comma
    }
    return result;
}

int main() {
    string line;
    cin >> line;
    vector<int> integers = parseInts(line);
    for(int num : integers) {
        cout << num << endl;
    }
}