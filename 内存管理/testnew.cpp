#include <iostream>

class Simple {
public:
    Simple() { std::cout << "Constructor called!" << std::endl; }
    ~Simple() { std::cout << "Destructor called!" << std::endl; }
};

int main() {
    Simple* simpleArr = new Simple[4];

    delete[] simpleArr;
    return 0;
}