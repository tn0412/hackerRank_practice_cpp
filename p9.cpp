#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q, k;
    cin >> n >> q;
    vector<vector<int>> a(n);
    // int a[n][k];
    // int result[q];
    for(int i = 0; i < n; i++) {
        cin >> k;
        a[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < q; i++) {
        int i1, j1;
        cin >> i1 >> j1;
        cout << a[i1][j1] << endl;
    }
    return 0;
}
