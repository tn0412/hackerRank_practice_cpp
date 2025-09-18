#include<iostream>

int returnMax(int a, int b, int c, int d) {
    int max = a;
    if(b > max) {
        max = b;
    }
    if(c > max) {
        max = c;
    }
    if(d > max) {
        max = d;
    }
    return max;
}

int main() {
    int a, b, c, d;
    scanf("%d\n%d\n%d\n%d", &a, &b, &c, &d);
    int max = returnMax(a, b, c, d);
    printf("%d\n", max);
    return 0;
}