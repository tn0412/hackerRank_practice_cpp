#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int q;
    cin >> q;
    while(q--) {
        int query;
        cin >> query;
        auto it = lower_bound(arr.begin(), arr.end(), query);
        if (it != arr.end() && *it == query) {
            cout << "Yes " << (it - arr.begin() + 1) << "\n";
        } else {
            cout << "No " << (it - arr.begin() + 1) << "\n";
        }
    }

}
