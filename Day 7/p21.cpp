#include<iostream>
#include<map>

using namespace std;


int main() {
    int q;
    cin >> q;
    map<string, int> score;
    int y, type;
    string x;
    while(q--) {
        cin >> type;
        switch(type) { 
            case 1:
                cin >> x >> y;
                score[x] += y; 
                break;
            case 2: 
                cin >> x;
                score.erase(x); 
                break;
            case 3:
                cin >> x; 
                cout << score[x] << endl; 
                break;
        }
    }
}