#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main() {
    int q;
    cin >> q;
    set<int> arr;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> y >> x;
        if(y == 1) {
            arr.insert(x);
        } else if(y == 2) {
            arr.erase(x);
        } else {
            if(arr.find(x) != arr.end()) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }
}