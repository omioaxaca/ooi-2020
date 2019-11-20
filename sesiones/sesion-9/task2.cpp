#include <iostream>

using namespace std;


int magick(int num) {
    if (num == 0) {
        return 0;
    }

    return num + magick(num - 1);
}


int main() {

    cout << "Magic: " << magick(5) << endl;

    /*
        magick(5) = 5 + magick(4) = 15
        magick(4) = 4 + magick(3) = 10
        magick(3) = 3 + magick(2) = 6
        magick(2) = 2 + magick(1) = 3
        magick(1) = 1 + magick(0) = 1
        magick(0) = 0
    */

    return 0;
}
