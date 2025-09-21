#include<iostream>

using namespace std;

class Box {
    private:
        int l, b, h;
    public:
        Box() {
            l = b = h = 0;
        }
        Box(int length, int breadth, int height) {
            l = length;
            b = breadth;
            h = height;
        }
        int getLength() {
            return l;
        }
        int getBreadth() {
            return b;
        }
        int getHeight() {
            return h;
        }
        long long CalculateVolume() {
            return (long long)l*b*h;
        }
        bool operator<(Box& B) {
            if(l < B.l) {
                return true;
            } else if(l == B.l && b < B.b) {
                return true;
            } else if(l == B.l && b == B.b && h < B.h) {
                return true;
            } else {
                return false;
            }
        }
        friend ostream& operator<<(ostream& out, Box& B) {
            out << B.l << " " << B.b << " " << B.h;
            return out;
        }
};

int main() {
    int n;
    cin >> n;
    int i = 0;
    Box defaultBox;
    while(i < n) {
        int type;
        // cout << "Enter type: ";
        cin >> type;
        switch(type) {
            case 1: { //Print current box dimensions
                cout << defaultBox << endl;
                break;
            }
            case 2: { //Create new box and print dimensions
                int l, b, h;
                cin >> l >> b >> h;
                Box NewBox(l, b, h);
                defaultBox = NewBox;
                cout << defaultBox << endl;
                break;
            }
            case 3: { //Compare two boxes
                int l, b, h;
                cin >> l >> b >> h;
                Box NewBox(l, b, h);
                if(NewBox < defaultBox) {
                    cout << "Lesser" << endl;
                } else {
                    cout << "Greater" << endl;
                }
                break;
            }
            case 4: { //Calculate volume of box
                // int l, b, h;
                // cin >> l >> b >> h;
                cout << defaultBox.CalculateVolume() << endl;
                break;
            }
            case 5: { //Create box by copy constructor
                Box NewBox(defaultBox);
                cout << NewBox << endl;
                break;
            }
        }
        i++;
    }
}