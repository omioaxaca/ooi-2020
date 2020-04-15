// Implementacion de una pila
#include <iostream>
#include <vector>

using namespace std;
                 
vector<int> pila; // 1 2 3 4
// ultimo elemento         ^

// O(1)
bool empty() {
    return pila.size() == 0;
}

// O(1)
void push(int a) {
    pila.push_back(a);
}

// O(1)
int top() {
    return pila[pila.size() - 1];
}

// O(1)
void pop() {
    pila.pop_back();
}

int main() {
    push(1);
    push(2);
    push(3);
    push(4);
    while(!empty()) {
        cout << top() << "\n";
        pop();
    }

    return 0;
}