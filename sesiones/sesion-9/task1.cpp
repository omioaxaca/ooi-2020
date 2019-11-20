#include <iostream>

using namespace std;


void hola() {
    cout << "Hello World" << endl;
}


int max2(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int max3(int a, int b, int c) {
    // int max_ab = max2(a, b);
    // return max2(max_ab, c);

    return max2(max2(a, b), c );
}

int max4(int a, int b, int c, int d) {
    // int max_abc = max3(a, b, c);
    // int max_abcd = max2(max_abc, d);
    // return max_abcd;

    // return max2(max3(a, b, c), d);

    return max2(max2(a, b), max2(c, d));
}


int main() {

    int a, b, c, d;

    cin >> a >> b >> c >> d;

    cout << "El maximo es: " << max4(a, b, c, d) << endl;

    return 0;
}
