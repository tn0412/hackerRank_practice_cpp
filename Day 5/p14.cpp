#include<iostream>

using namespace std;

class Student {
    private:
        int score[5];
        int totalScore;
    public:
        void input() {
            for(int i = 0; i < 5; i++) {
                cin >> score[i];
            }
        }
        int calculateTotalScore() {
            totalScore = 0;
            for(int i = 0; i < 5; i++) {
                totalScore += score[i];
            }
            return totalScore;
        }
};

int main() {
    int n;
    cin >> n;
    Student students[n];
    for(int i = 0; i < n; i++) {
        students[i].input();
    }
    int Kristen = students[0].calculateTotalScore();
    int count = 0;
    for(int i = 1; i < n; i++) {
        if(students[i].calculateTotalScore() > Kristen) {
            count++;
        }
    }
    cout << count << endl;
}