#include<iostream>

using namespace std;

class Student {
    private:
        int age;
        string first_name, last_name;
        int standard;
    public:
        void set_age(int a) {
            age = a;
        }
        void set_first_name(string fn) {
            first_name = fn;
        }
        void set_last_name(string ln) {
            last_name = ln;
        }
        void set_standard(int s) {
            standard = s;
        }
        int get_age() {
            return age;
        }
        string get_first_name() {
            return first_name;
        }
        string get_last_name() {
            return last_name;
        }
        int get_standard() {
            return standard;
        }
};

int main() {
    int age;
    string first_name, last_name;
    int standard;
    Student s1;
    cin >> age >> first_name >> last_name >> standard;
    s1.set_age(age);
    s1.set_first_name(first_name);
    s1.set_last_name(last_name);
    s1.set_standard(standard);

    cout << s1.get_age() << "\n";
    cout << s1.get_last_name() << ", " << s1.get_first_name() << "\n";
    cout << s1.get_standard() << "\n";
    cout << "\n";
    cout << s1.get_age() << "," << s1.get_first_name() << "," << s1.get_last_name() << "," << s1.get_standard();

}