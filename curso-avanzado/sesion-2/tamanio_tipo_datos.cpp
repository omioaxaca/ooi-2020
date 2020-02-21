#include <iostream>
#include <vector>

using namespace std;

int main() {

    cout << sizeof(char) << "\n";
    cout << sizeof(int) << "\n";
    cout << sizeof(long long int) << "\n";
    cout << sizeof(double) << "\n";

    //vector<int> v(1000000000);

    std::this_thread::sleep_for(10000);

    return 0;
}