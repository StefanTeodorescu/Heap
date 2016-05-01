#include <iostream>
#include "Heap.h"

using namespace std;

class Less {
public:
    const bool operator () (const int& A, const int& B) const {
        return A < B;
    }
};

class Greater {
public:
    const bool operator () (const int& A, const int& B) const {
        return A > B;
    }
};

int main() {
    Heap<int, less<int>> H1; //traiasca STL
    Heap<int, greater<int>> H2;

    H1.insert(1);
    H1.insert(5);
    H1.insert(4);
    H1.insert(-2);
    H1.insert(7);
    H2.insert(1);
    H2.insert(5);
    H2.insert(4);
    H2.insert(-2);
    H2.insert(7);

    int i;
    for (i = 1; i <= 5; i++) {
        cout << H1.pop() << " ";
    }
    cout << "\n";
    for (i = 1; i <= 5; i++) {
        cout << H2.pop() << " ";
    }

    return 0;
}