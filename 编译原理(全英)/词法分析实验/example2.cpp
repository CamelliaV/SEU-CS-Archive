#include <bits/stdc++.h>
using namespace std;
void f(int, int, int = 10);
void f(int, int = 6, int);
void f(int = 4, int, int);
void f(int a, int b, int c) {
    cout << a << " " << b << " " << c << endl;
}
int main() {
    f();
}